#include <iostream>
#include "LLQueue.h"
using namespace std;

// Pure virtual abstract base class representing a minimal stack
class Stack{
 public:
	// c'tor and d'tor
	Stack() { }
	// pre-condition:  given an integer 'e'
	// post-condition: the stack will contain 'e' at the top of the data structure
	virtual void push(int e) = 0;
	// pre-condition:  stack must not be empty
	// post-condition: the integer at the top of the data structure is returned,
	//    and also removed from the structure
	virtual int pop() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};


class myStack : public Stack {
 public:
	// c'tor and d'tor
	myStack(int);
	// pre-condition:  given an integer 'e'
	// post-condition: the stack will contain 'e' at the top of the data structure
	void push(int e) override;
	
	// pre-condition:  stack must not be empty
	// post-condition: the integer at the top of the data structure is returned,
	//    and also removed from the structure
	int pop() override;
	bool isEmpty() override;
	void print() override;
	int size_=0;
	myQueue firstQueue;
	myQueue secondQueue;
};


