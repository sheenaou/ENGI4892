#include <iostream>

using namespace std;


/*******************************************
declaration of Node class
*******************************************/
template<class T>
class Node{
 public:
 	Node(T); //constructor
	T data_=0;
	int quantity_=1;
	Node* next = nullptr;
};

/*******************************************
declaration of SortedBag class
*******************************************/

template<class T>
class SortedBag{
 public:
	SortedBag(); //constructor
	SortedBag(T);
	int size_=0;
	Node<T> *head=nullptr;
	Node<T> *tail=nullptr;
	Node<T> *temp=nullptr;
	Node<T> *holder=nullptr;
	Node<T> *holder2=nullptr;
	
	void add(const T& element);
	void removeOne(const T& element);
	void removeAll(const T& element);
	void printBag();
	int bagSize();
	int occurances(const T& element);
	bool isEmpty();
	bool isContain(const T& element);

};

