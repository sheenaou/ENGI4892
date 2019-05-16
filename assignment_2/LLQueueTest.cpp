#include <iostream>
#include "LLQueue.h"
using namespace std;


int main(){
	myQueue firstQueue(5);
	cout<<endl<<"Queue with everything"<<endl;
	firstQueue.enqueue(10);
	firstQueue.enqueue(9);
	firstQueue.enqueue(7);
	firstQueue.enqueue(14);
	firstQueue.print();

	cout<<endl<<"Queue with first removed"<<endl;
	firstQueue.dequeue();
	firstQueue.print();

	cout<<endl<<"Queue with something put back on"<<endl;
	firstQueue.enqueue(1);
	firstQueue.print();

	cout<<endl<<"Check if Queue is Empty"<<endl;
	firstQueue.isEmpty();
	
	cout<<endl<<"dequeue one by one and print the queue"<<endl;
	
	firstQueue.dequeue();
	firstQueue.print();
	cout<<endl;

	firstQueue.dequeue();
	firstQueue.print();
	cout<<endl;

	firstQueue.dequeue();
	firstQueue.print();
	cout<<endl;

	firstQueue.dequeue();
	firstQueue.print();
	cout<<endl;

	firstQueue.dequeue();
	firstQueue.print();
	cout<<endl;

	cout<<endl<<"Check if Queue is Empty"<<endl;
	firstQueue.isEmpty();
	return 0;
}
