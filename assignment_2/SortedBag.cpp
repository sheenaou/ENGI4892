#include <iostream>
#include "SortedBag.h"

using namespace std;

/*******************************************
Node(T info);
constructor for Node class
*******************************************/
template<class T>
Node<T>::Node(T info){
	data_=info;
}

/*******************************************
SortedBag();
constructor for SortedBag class 
*******************************************/
template<class T>
SortedBag<T>::SortedBag(){
	cout <<"A bag was created with nothing in it";
}

/*******************************************
SortedBag(T info);
constructor for SortedBag class with first element given
*******************************************/
template<class T>
SortedBag<T>::SortedBag(T info){
	cout<<"a bag was created with something in it"<<endl;
	head= new Node<T>(info);
	size_++;
}

/*******************************************
add(const T& element);
adds an element to the sorted bag in its correct position
*******************************************/
template<class T>
void SortedBag<T>::add(const T& element){
	holder=head;
	while ( (holder->next != nullptr) && (element >= holder->next->data_) ){ //iterate until you reach a point where the next element is greater than or equal to the element
	holder=holder->next;
	}

	if (size_==0){				//if nothing is in the bag set head as this element
		head = new Node<T>(element);
		size_++;			// increase the size of the bag
		return ;
	}
					//else if there are things already in the bag then start at the beginning 
	else if ( element < head->data_ ){		//if the element is less than the head then make the element the new head
		temp = new Node<T>(element);
		temp->next = holder;		//set the "next node pointer " of the element to the former head
		head=temp;
		size_++;			//increase the size of the bag
	}

	else if (holder->data_ == element){				//if the element was already in the bag, increase the quantity of the item by 1
		holder->quantity_=holder->quantity_+1;
		size_++;					//increase the size of the bag
		return;
	}
	else {
		temp=new Node<T>(element);			//else place the node between the necessary values or at the end
		temp->next= holder->next;			//update appropriate data
		holder->next=temp;	
		size_++;					//increase the size of the bag
		return;
	}
}

/*******************************************
removeOne(const T& element);
removes one from the desired element 
*******************************************/
template<class T>
void SortedBag<T>::removeOne(const T& element){
	int number=0;
	if (size_==0){ 								//check to see if there is anything in the bag to remove
		cout<<"There is nothing to remove, the bag is empty"<<endl;
		return;
	}
	holder=head;
	while ( (holder->next != nullptr) && (element != holder->data_) ){	//if the bag is not empty then start at the beginning
		temp=holder;							//iterate until you find the element to remove or you reach the end of the list
		holder=holder->next;
	}
	if ( element == holder->data_){			
		if( holder->quantity_ == 1){		//if there is only one of that node, remove it from the list
			removeAll(element);
			size_--;
			return;		
		}
		else {
			holder->quantity_--;		//if the quantity of the element is more than one, decrease the quantity instead
			size_--;			
			return;
		}
	}
	else cout<<element<<" is not in the bag"<<endl;	//if the item is not found in the list, then exit
}

/*******************************************
removeAll(const T& element);
removes all occurances of the element 
*******************************************/
template<class T>
void SortedBag<T>::removeAll(const T& element){

	if (size_==0){ 								//check if the bag is empty
		cout<<"There is nothing to remove, the bag is empty"<<endl;
	}
	holder = head;
	while ( (holder->next != nullptr) && (element != holder->data_) ){		// start at the beginning of the bag and iterate until you reach the element you are looking for
		temp=holder;								// or you reach the end of the bag
		holder=holder->next;
	}
	if (holder->data_==element){				// if the element was found, delete all of the occurances of it
		temp->next=holder->next;
		delete holder;
	}
	else cout<<element<<" is not in the bag"<<endl;		//if the item was not found, then exit
}

/*******************************************
printBag();
Prints the contents of the bag
*******************************************/
template<class T>
void SortedBag<T>::printBag(){
	if (size_==0){					//check to see if the bag is empty
		cout<<"This bag is empty"<<endl;
		return;
	}
	int position=1;			
	holder=head;
	while(holder != nullptr){			//iterate until you reach the end of the bag
		cout<<"Node "<<position<<"'s value is "<< holder->data_ <<endl;
		cout<<"There are "<<holder->quantity_<<" in the bag"<<endl;
		holder=holder->next;
		position++;
	}
return;	
}

/********************************************
bagSize();
returns the number of things in the bag 
*********************************************/
template<class T>
int SortedBag<T>::bagSize(){
	cout<<size_<<endl;		//output the size of the bag
return size_;
}	

/********************************************
occurances(const T& element);
returns the number of occurances of a specific item in the bag 
*********************************************/
template<class T>
int SortedBag<T>::occurances(const T& element){
	int occur=0;			//initialize variable
	holder=head;			//start at the beginning
	while ( (holder->next != nullptr) && (holder->data_ != element) ){		//iterate until you reach the node you want or the end of the list
		holder=holder->next;
	}
	if ( holder->data_ == element){					//if the node was found, store the value of its quantity until the variable "occur"
		occur=holder->quantity_;
	}
	cout<<"There are "<<occur<<" "<<element<<"'s in the bag"<<endl;
return occur;
}	

/********************************************
occurances(const T& element);
check to see if the bag is empty
*********************************************/
template<class T>
bool SortedBag<T>::isEmpty(){
	if (size_ == 0){
		cout<<"This bag is empty"<<endl;		//if the size is zero, then the bag is empty
		return true;
	}
	if (size_ != 0){
		cout<<"This bag is not empty"<<endl;		//if the size is greater than zero then the bag is not empty
		return false;
	}
}
/********************************************
isContain(const T& element)
check to see if the bag contains a certain element
*********************************************/
template<class T>
bool SortedBag<T>::isContain(const T& element){
	holder = head;			//start at the beginning

	while ( (holder->next != nullptr) && (holder->data_ != element) ){		//iterate until you find the element or reach the end of the list	
		holder=holder->next;
	}
	
	if ( holder->data_ == element){					//if you find the element in the bag
		cout<<element<<" was found in the bag"<<endl;
		return true;
	}
	cout<<element<<" is not in the bag"<<endl;
return 0;		//if the item was not found return false
}


//**************************************************TESTING**********************************************************************************************

int main(int argc, char *argv[]){
	SortedBag<int> firstBag(10);
	firstBag.add(10);
	firstBag.add(10);
	firstBag.add(6);
	firstBag.add(6);
	
	firstBag.add(27);
	firstBag.add(10);

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Print the contents of the bag"<<endl;
	firstBag.printBag();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"The bag size should be 7:"<<endl;
	firstBag.bagSize();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check how many 10's there are in the bag, There should be 4"<<endl;
	firstBag.occurances(10);

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check to see if the bag is empty, It should not be"<<endl;
	firstBag.isEmpty();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Remove all occurance of 10 and try to remove 35 and 6 (35 should not be found and should output accordingly)"<<endl;
	firstBag.removeAll(10);
	firstBag.removeOne(35);
	firstBag.removeOne(6);
	firstBag.printBag();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Add 9 to the bag"<<endl;
	firstBag.add(9);
	firstBag.printBag();
	
	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check to see if 10 is found in the bag"<<endl;
	firstBag.isContain(10);

return 0;

}
