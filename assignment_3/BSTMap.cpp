#include <iostream>
#include "BSTMap.h"
#include <string>
#include <stack>
#include <fstream>
using namespace std;

/*******************************************
Node( info);
constructor for Node class
*******************************************/
template<class K, class V>
Node<K,V>::Node(K info, V number)
	:name_(info),data_(number)
{
}

/*******************************************
bool insert(const K key, const V value)
*******************************************/
template<class K, class V>
bool BSTMap<K,V>::insert(const K& key, const V value) {
	temp = root;					//sets a variable pointer to the root		
	if (root==nullptr){				//if the Map is empty then insert at the root
		root = new Node<K,V>(key,value);	//creates a new Node with the given values
		return true;
	}	
	while ( temp != nullptr){	//while loop to find where to insert the node
		prev=temp;	//prev is a variable pointer which holds the value of the parent node
		if (key > temp->name_ )		//compare the value of key to the key value stored in temp
			temp=temp->right;	//if greater than, go right
		else if (key < temp->name_ )	
			temp=temp->left;	//if less than, go right
		else if (temp->name_ == key)	//if the key is already in the MAap, do not allow insertion
			return false;
	}
	if (key > prev->name_ ){			//if the key is greater than the parent node
		prev->right= new Node<K,V>(key,value);	//make it the right child of the parent
		return true;
	}
	else if (key < prev->name_ ){			//if the key if less than the parent node
		prev->left= new Node<K,V>(key,value);	//make it the left child of the parent
		return true;
	}
return false;
}
/*******************************************
bool remove(const K key)
*******************************************/
template<class K, class V>
bool BSTMap<K,V>::remove(const K key) {
	temp = root;	//set the temp variable pointer to start at the root
	bool found = false;	//variable that is true when the node is found and false otherwise
	prev=temp;		//variable pointer prev will keep track of the parent node
	while ( temp != nullptr and found == false){		//loop to find the node to remove
	if (temp->name_ < key){					//compare key to the value of key stored in temp
			prev=temp;				
			temp=temp->right;			//if the key is greater than the value of key stored in temp, go to its greater child
		}
		else if (temp->name_ > key){			
			prev=temp;
			temp=temp->left;			//if the key is less than the value of key stored in temp, go to its left child
		}
		else if (temp->name_ == key){			//the key and the value stored in temp are the same, the node was found
			found=true;
		}
	}

	
	if(found==true){		//if you found the node
		if ( temp->right == nullptr && temp->left==nullptr){  //no child case
			if (prev->right==temp)		//set the required left or right pointer of the parent to null
				prev->right=nullptr;		
			else if (prev->left==temp)
				prev->left=nullptr;
			delete temp;			//delete the node
		}
		else if (temp->right == nullptr && temp->left != nullptr){	//no right child case
			if (prev->right==temp)			//if the child to be delete is on the right of the parent, 
				prev->right=temp->left;		//set the right child of the parent to the left child(if it has one) of the node to be deleted
			else if (prev->left==temp)		//if the child to be delete is on the left of the parent, 
				prev->left==temp->left;		//set the left child of the parent to the left child(if it has one) of the node to be deleted
			delete temp;	//delete the node
		}
		else if (temp->right !=nullptr && temp->left == nullptr){	//no left child case
			if (prev->right==temp)			//if the child to be delete is on the right of the parent,
				prev->right=temp->right;	//set the right child of the parent to the right child(if it has one) of the node to be deleted
			else if (prev->left==temp){		//if the child to be delete is on the left of the parent
				prev->left=temp->right;		//set the left child of the parent to the right child(if it has one) of the node to be deleted
			}
			delete temp;
		}

		else if (temp->right !=nullptr && temp->left != nullptr){  // both children

			hold=temp->left;		//variable pointer hold will store the value of the node that will replace the deleted node
							//1) Go left once of the node to be deleted
			temp2=hold;			//variable pointer temp2 keeps track of the parent node of hold
			while(hold->right != nullptr){	//2) Go deep right
				temp2 = hold;
				hold=hold->right;
			}
			temp->name_=hold->name_;	//replace the data of the key and value in the node to be deleted with the node found above(left once, deep right)
			temp->data_=hold->data_;	
			temp2->right=nullptr;		//set the parent node of the node found above(left once deep right) to null
			delete hold;
		}

	}
	if(found==false)	//if the node was not found, you cannot remove it
		return false;

return true;
}
/*******************************************
V* search(const K key)
*******************************************/
template<class K, class V>
V* BSTMap<K,V>::search(const K key) {
	temp = root;		//start at the root
	prev=temp;		//prev will keep track of the parent
	bool found= false;	//variable that is true when the node is found and false otherwise
	if (temp->name_==key)	//if the key value stored at the root is equal to the key, then the node was found
		return &temp->data_;
	else if( temp==nullptr )	//if the Map is empty, then the node cannot be found
		return NULL;
	while ( temp != nullptr && found == false){	//iterate through the map until you reach the end of the node was found
		if (temp->name_ < key){
			prev=temp;
			temp=temp->right;
		}
		else if (temp->name_ > key){
			prev=temp;
			temp=temp->left;
		}
		else if (temp->name_ == key)		
			found=true;		
	}
	if ( found == false ){		//the node was not found after iteration
		cout << "NOT FOUND"<<endl;
		return NULL ;
	}
	else 
		return &(temp->data_);	
}

/*******************************************
bool isEmpty()
*******************************************/
template<class K, class V>
bool BSTMap<K,V>::isEmpty() {
	if ( root==nullptr)		//if there is not root of the MAP then it is empty, otherwise there is something in the map
		return true;
return false;
}

/*******************************************
void print();
*******************************************/
template<class K, class V>
void BSTMap<K,V>::print() {
	temp = root;		//start at the root
	if (temp==nullptr){	//if the MAP is empty, do nothing
		return;
	}	
	
	inorder(temp);		//call a function that will iterate through the map	
		
}
/*******************************************
void inorder(Node<K,V>* other);
*******************************************/
template<class K, class V>
void BSTMap<K,V>::inorder(Node<K,V>* other){
	
	if(other==nullptr){	//if a null pointer was passed, do nothing
		return;
	}
	if(other!=nullptr){
	inorder(other->left);	
	cout<<"Key:"<<other->name_<<" Value:"<<other->data_<<endl;
	inorder(other->right);
	}
};

int main() {
	string name;
	long value;
	string person="B_Person";
	long info=0;
	ifstream myFile;
	myFile.open("someFile.txt");	 	//Open the file with all the data
	BSTMap<string,long> myMap;		//creates an instance of BSTMAP that maps from the persons name to the telephone number
	BSTMap<long,string> reverseMap;		//creates a second instance BSTMap that maps from the telephone number to the persons name 
		cout<<"*************************************************************************"<<endl;
		cout<<"			  PRINT THE FIRST AND SECOND MAPS		        "<<endl;
		cout<<"*************************************************************************"<<endl;
		if (myMap.isEmpty())
			cout<<"The first map is empty"<<endl;		
		if(reverseMap.isEmpty())		
			cout<<endl<<"The second map is empty"<<endl;
	if (myFile.is_open()){	
		for (int i=0; i<10; i++){		
			myFile>>name;
			myFile>>value;
		myMap.insert(name,value);	//inserts the contents on the data file into the map
		reverseMap.insert(value,name);	//repeat for the second map
		}
		cout<<"*************************************************************************"<<endl;
		cout<<"			  REMOVING A NODE WITH TWO CHILDREN		        "<<endl;
		cout<<"	 IF SUCCESSFUL THEN REMOVE THE CORRESPONDING ENTRY IN THE SECOND MAP    "<<endl; 
		cout<<"*************************************************************************"<<endl;
		bool gone=false;		
		string person3="D_Person";
		long *done = myMap.search(person3);
		int other= *done;
		gone = myMap.remove(person3);
		if (gone==true)
			reverseMap.remove(other);
		cout<<"This is the First Map with D_Person/4000001 Removed"<<endl;
		myMap.print();
		cout<<endl<<"This is the Second Map with D_Person/4000001 Removed"<<endl;
		reverseMap.print();
		cout<<"*************************************************************************"<<endl;
		cout<<"			  REMOVING A NODE WITH NO CHILDREN		        "<<endl;
		cout<<"	 IF SUCCESSFUL THEN REMOVE THE CORRESPONDING ENTRY IN THE SECOND MAP    "<<endl; 
		cout<<"*************************************************************************"<<endl;
		person3="J_Person";
		myMap.remove(person3);
		other=1000001;
		reverseMap.remove(other);
		cout<<"This is the First Map with J_Person Removed"<<endl;
		myMap.print();
		cout<<endl<<"This is the Second Map with 1000001 Removed"<<endl;
		reverseMap.print();
		cout<<"*************************************************************************"<<endl;
		cout<<"			  REMOVING A NODE WITH A ONE CHILD		        "<<endl; 
		cout<<"	    FIRST MAP:REMOVE RIGHT CHILD    SECOND MAP:REMOVING LEFT CHILD   	"<<endl; 
		cout<<"*************************************************************************"<<endl;
		person3="G_Person";
		myMap.remove(person3);
		cout<<"This is the First Map with G_Person Removed"<<endl;
		myMap.print();		
		other=2000001;
		reverseMap.remove(other);
		cout<<endl<<"This is the Second Map with 2000001 Removed"<<endl;
		reverseMap.print();
		cout<<"*************************************************************************"<<endl;
		cout<<"		    SEARCH IN THE FIRST MAP FOR SOMEONE WHO EXISTS	        "<<endl;
		cout<<"			     USE RESULT TO SEARCH SECOND MAP   			"<<endl; 
		cout<<"*************************************************************************"<<endl;
		cout<<endl<<"Find the number for B_Person ( 8000001 )"<<endl;
		long *info = myMap.search(person);
		cout<<"The value held in the first map is "<< *info <<endl;
		cout<<"Find the person in the second map who owns this number ( B_Person )"<<endl;
		cout<<"The Person in the second map is "<< *reverseMap.search(*info)<<endl;

		cout<<"*************************************************************************"<<endl;
		cout<<"		SEARCH IN THE FIRST MAP FOR SOMEONE WHO DOESN'T EXIST	        "<<endl;
		cout<<"			IF FOUND, USE RESULT TO SEARCH SECOND MAP   		"<<endl; 
		cout<<"*************************************************************************"<<endl;
		person="M_Person";		
		if (myMap.search(person) != nullptr){
			info = myMap.search(person);
			cout<<"The value held in the first map is "<< *info <<endl;
			cout<<"The Person in the second map is "<< *reverseMap.search(*info)<<endl;
		}
	}
return 0;
}
































