#include <vector>
#include "HeapPriorityQueue.h"
#include <iostream>
#include <fstream>
using namespace std;

template<class K, class V>
void HeapPriorityQueue<K,V>::enqueue(const K& key, const V& value){
	heap.push_back( PQEntry(key,value) ); //put the pair in the next available position
	trickleUp(size_);	//fix the heap
	size_++;		//increase the size
}

// Removes the best key from the heap and returns associated value
template<class K, class V>	
V HeapPriorityQueue<K,V>::dequeue() {
	V max=heap[0].value;	//0'th position and store into max
	cout<<"Dequeue: "<<max<<endl;
	heap[0]=heap[size_-1];  //take whatever is in the last position and put it at 0
	trickleDown(0);		//fix the heap
	heap.pop_back();	//remove the last element
return max;
}


// Test for empty
template<class K, class V> 	
bool HeapPriorityQueue<K,V>::isEmpty() const {
	int length=heap.size();
	if( length > 0)		//if the size of the heap is not 0 then it isn't empty
		return false;
	if (length == 0)	//if it is 0 then the heap is empty
		return true;
}


// Prints contents of queue (key/value pairs) using level-order traversal
template<class K, class V>    	
void HeapPriorityQueue<K,V>::print() const {
	int length=heap.size();
	for (int i=0;i<length;i++){	//start at the beginning of the heap
		cout<<"Position "<<i<<": Key="<<heap[i].key<<"  value="<<heap[i].value<<endl; //print its contents
	}	//increase i and repeat until you reach the end
}



// Auxiliary methods to re-heapify the heap
template<class K, class V>    	
void HeapPriorityQueue<K,V>::trickleUp(int i){
	int parent= (i-1)/2;		//find the parent of the node
	if ( (i>=0) && (heap[i].key > heap[parent].key)){	//if the element if greater than the parent
		PQEntry temp = heap[i];		//switch the parent and the element
		heap[i]=heap[parent];		
		heap[parent]=temp;
		trickleUp(parent);	//repeat process
	}
}

template<class K, class V>    	
void HeapPriorityQueue<K,V>::trickleDown(int i){	
	int left=(2*i)+1;
	int right=(2*i)+2;
	PQEntry temp= heap[i];
	if( right > size_ &&left <size_){	//if the right child does not exist but the left does
		heap[i]=heap[left];		//make the 0 position the left child
	}
	else if (left >size_)	//if the left child does not exist
		return;
	else if( right < size_ && left < size_){ //if both children are present
		if( heap[right].key > heap[left].key){	//if the right child is greater
			heap[i]=heap[right];	//switch the 0'th position and the right child
			heap[right]=temp;	
			trickleDown(right);	//repeat process
		}
		else if (heap[right].key < heap[left].key) {	//if the left child is greater
			heap[i]=heap[left];	//siwtch the 0'th position and the left child
			heap[left]=temp;
			trickleDown(left);	//repeat process
		}	
	}
}
int main(){
	int number=0;
	string ticket="";
	ifstream myFile;
	myFile.open("tickets.txt");
	bool check=false;
	if (myFile.is_open()){	
		HeapPriorityQueue<int,string> testHeap;
		for( int i=0;i<5;i++){
			myFile>>number;
			myFile>>ticket;
			testHeap.enqueue(number,ticket);
			cout<<"**************************************"<<endl;
			cout<<"	   "<<i+1<<" element(s) added"<<endl;
			cout<<"**************************************"<<endl;
			testHeap.print();
		}
		for( int i=5;i>0;i--){
			cout<<"**************************************"<<endl;
			cout<<"	element"<<i<<" was dequeued"<<endl;
			cout<<"**************************************"<<endl;
			testHeap.dequeue();
			testHeap.print();
		}
		
	}
return 0; 
}






