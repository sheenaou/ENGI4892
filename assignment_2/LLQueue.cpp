#include <iostream>
#include "LLQueue.h"
using namespace std;


/*******************************************
Node(int info);
constructor for node class
*******************************************/
Node::Node(int info){
	data_=info;
}

/*******************************************
dequeue();
removes the first element and returns its value
*******************************************/
int myQueue::dequeue(){
	temp=head;
	
	if (size_==0){
		return 0;
	}
	else if(size_==1){
		head=nullptr;
		tail=nullptr;
		size_--;
		return 0;
	}
		
	while ( temp->next != nullptr){		//iterate until you are at the end of the list
		holder=temp;		
		temp=temp->next;
	}
	int number=temp->data_;

	delete temp;			//remove the last element
	holder->next=nullptr;
	tail = holder;
	size_--;			//decrease the size of the queue
		
return number;
};

/*******************************************
enqueue(int e);
adds e to the end on the queue
*******************************************/
void myQueue::enqueue(int e){
	if(size_ == 0){			//if nothing is in the queue, then add to the beginning
		head= new Node(e);
		tail=head;
		size_++;		//increase the size of the queue
		return;
	}
	if(size_ != 0){			//if there is something already in the queue add the element to the end
		temp=head;
		head=new Node(e);
		head->next=temp;
		size_++;		//increase the size of the queue
		return;
	}
return;
};
/*******************************************
print();
prints the entire contents of the queue
*******************************************/
void myQueue::print(){
	if (size_==0){
		cout<<"There is nothing in the queue"<<endl;
		return;
	}
	int position=1;
	holder=head;
	while(holder != nullptr){
		cout<<"Node "<<position<<"'s value is "<< holder->data_ <<endl;
		holder=holder->next;
		position++;
	}
return;	
}

/*******************************************
myQueue(int e);
constructor for queue class with first element given
*******************************************/
myQueue::myQueue(int e){
	cout<<"a queue was created with something in it"<<endl;
	head= new Node(e);
	size_++;
}
/*******************************************
~myQueue(int e);
destructor for queue class 
*******************************************/
myQueue::~myQueue(){
	holder=head;
	while(holder != nullptr){
		temp=holder;	
		holder=holder->next;
		delete temp;
	}
	head=nullptr;
	tail=nullptr;
}

/*******************************************
isEmpty()
Check to see if the queue is empty
*******************************************/
bool myQueue::isEmpty(){
	if (size_==0){
		cout<<"This queue is empty"<<endl;
		return true;
	}

	if (size_ !=0){
		cout<<"This queue is NOT empty"<<endl;
		return false;
	}
return 0;
}
//******************************************************//

