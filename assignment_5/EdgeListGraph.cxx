#include "EdgeListGraph.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e){
	myVertices=v;	//creates a graph with a given list of vertices and edges
	myEdges=e;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const{
	return myVertices;		//returns the vector of all the vertices
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const{
	return myEdges;		//returns the vector of all edges
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const{
	EdgeCollection temp;	//temp variable	
	for (int i=0; i<myEdges.size() ;i++){	//iterate through all the edges
		if(myEdges.at(i).contains(v))	//if the edge contains the vertex 
			temp.emplace_back(v,myEdges[i].opposite(v),myEdges[i].weight());//store the edge in a temp variable
	}
	return temp; //return the temp variable
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const{	
	for (int i=0; i<myEdges.size() ;i++){	//iterate through all the edges
		if(myEdges.at(i).contains(v))	//if the edge contains the vertex
			if (myEdges[i].opposite(v)==w)	//check what's on the other side of the check
				return true;		// return true if they're adajacent
	}
return false;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertVertex(const Vertex& v){
	for (int i=0; i<myVertices.size() ;i++){	//iterate through all the vertices
		if(myVertices[i]==v)			//if the vertex already exists, exit the function and return false
			return false;
	}
	myVertices.push_back(v);	//if it doesn't already exist then add the vertex to the vector
return true;	//return true if the vertex was added
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -**********
bool EdgeListGraph::removeVertex(const Vertex& v){
	EdgeCollection temp;
	VertexCollection tempV;	
	bool check;

	for (int j=0; j<myVertices.size(); j++){	//iterate through the vertices
		if( myVertices[j]==v )	
			check=true;			//vertex exist in the graph
		else{	
			tempV.push_back(myVertices[j]);	//put everything that does not match the vertex in a temp variable	
		}
	}
	for (int i=0; i<myEdges.size() ;i++){		//iterate through the edges
		if(myEdges.at(i).contains(v)==false)	//if the edges does not contain the vertex 
			temp.emplace_back(myEdges[i]);	//store the edge in a temp variable
	}

	myEdges=temp;	//make the temp variables the vector of edges and vertices
	myVertices=tempV;

return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertEdge(const Edge& e){
	bool check=false;
	bool check2=false;
	for (int i=0; i<myEdges.size() ;i++){		//check if the edges already exists
		if (myEdges[i]==e)		
			return false;			//if it does then return false
	}
	VertexCollection temp=e.endVertices();		//temp variable to hold value of v1 of the edge
	Vertex op=temp[1];				//temp variable to hold the value of v2 of the edge
	for ( int j=0; j<myVertices.size(); j++){	//iterate through all the vertices
		if( myVertices[j]==temp[0] && !check)	//check to see if the vertices exists already
			check=true;
		if( myVertices[j]==op && !check2)
			check2=true;
	}
	if( !check)	//if the vertices don't exist, then add them
		myVertices.push_back(temp[0]);
	else if (!check2)
		myVertices.push_back(op);
	myEdges.emplace_back(e);//add the edge to the myEdges vector

return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e){
	bool check=false;
	EdgeCollection temp;
	for (int i=0; i<myEdges.size() ;i++){	//iterate though all the edges
		if (myEdges[i]==e)	//check if the edge exists
			check=true;	//if it exists then it can be removed
		else
			temp.emplace_back(myEdges[i]);	//if it isn't the edge then store in a temp variable
	}
	myEdges=temp;	//make temp variable the new myEdges vector
return check;	
}
















