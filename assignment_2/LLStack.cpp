#include <iostream>
#include "LLStack.h"


using namespace std;
/*******************************************
push(int e);
put something on the stack
pre-condition:  given an integer 'e'
post-condition: the stack will contain 'e' at the top of the data structure

TIME COMPLEXITY QUESTION: O(1), since the value is readily available
*******************************************/

void myStack::push(int e){
		firstQueue.enqueue(e);
return;
}
/*******************************************
pop();
removes the top element of the stack
pre-condition:  stack must not be empty
post-condition: the integer at the top of the data structure is returned,
		and also removed from the structure

TIME COMPLEXITY QUESTION: O(n), since you must iterate through the  first queue
*******************************************/
int myStack::pop(){
	int temp=0;
	int number=0;
	int size=firstQueue.size_;
	for (int i=0;i<size-1;i++){			//repeat until you reach the last element
		temp=firstQueue.dequeue();		//dequeue the first queue
		secondQueue.enqueue(temp);		//place that onto the second queue
	}
	number =firstQueue.dequeue();			//save the value of the last element
	for (int i=0;i<size-1;i++){
		temp=secondQueue.dequeue();		//dequeue the second queue and place the elements back onto the first queue
		firstQueue.enqueue(temp);
	}		
return number;
}
/*******************************************
isEmpty()
check to see if the stack is empty
*******************************************/
bool myStack::isEmpty(){
	if (firstQueue.size_==0){
		cout<<"This stack is empty"<<endl;
		return true;
	}
	if (firstQueue.size_ !=0){
		cout<<"This stack is NOT empty"<<endl;
	}
return false;
}

/*******************************************
print();
print the contents of the stack
*******************************************/
void myStack::print(){
	firstQueue.print();
return;
}
/*******************************************
myStack(int e);
constructor for stack class with first element given
*******************************************/
myStack::myStack(int e){
	cout<<"a stack was created "<<endl;
	firstQueue.enqueue(e);
	size_++;
}
//********************TEST**********************************//

int main(){
	myStack firstStack(10);
	cout<<endl<<"Stack with everything"<<endl;
	firstStack.push(15);
	firstStack.push(20);
	firstStack.push(25);
	firstStack.firstQueue.print();

	cout<<endl<<"Stack with the first thing removed"<<endl;
	firstStack.pop();
	firstStack.firstQueue.print();

	cout<<endl<<"Stack with the something put back on"<<endl;
	firstStack.push(50);
	firstStack.firstQueue.print();

	cout<<endl<<"Stack with the first thing removed"<<endl;
	firstStack.pop();
	firstStack.firstQueue.print();

	cout<<endl<<"Check if the stack is empty"<<endl;
	firstStack.isEmpty();

	cout<<endl<<"pop one by one and print the contents"<<endl;
	firstStack.pop();
	firstStack.firstQueue.print();
	firstStack.pop();
	firstStack.firstQueue.print();
	firstStack.pop();
	firstStack.firstQueue.print();

	cout<<endl<<"Check if the stack is empty"<<endl;
	firstStack.isEmpty();
return 0;
}
