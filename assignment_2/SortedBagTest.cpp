#include <iostream>
#include "SortedBag.h"

using namespace std;

int main(int argc, char *argv[]){
	SortedBag<int> firstBag(10);
	firstBag.add(10);
	firstBag.add(10);
	firstBag.add(6);
	firstBag.add(6);
	firstBag.add(27);

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Print the contents of the bag"<<endl;
	firstBag.printBag();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"The bag size should be 8:"<<endl;
	firstBag.bagSize();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check how many 10's there are in the bag, There should be 3"<<endl;
	firstBag.occurances(10);

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check to see if the bag is empty, It should not be"<<endl;
	firstBag.isEmpty();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Remove one occurance of 10 and ALL the occurances of 6, then print the bag"<<endl;
	firstBag.removeOne(6);
	firstBag.removeAll(10);
	firstBag.printBag();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Remove one occurance of 10 and try to remove 35 (35 should not be found and should output accordingly)"<<endl;
	firstBag.removeOne(10);
	firstBag.removeOne(35);
	firstBag.printBag();

	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Remove the last occurance of 10 and add 9 to the bag"<<endl;
	firstBag.add(9);
	firstBag.removeOne(10);
	firstBag.printBag();
	
	cout<<endl<<"**********************************************************"<<endl;
	cout<<"Check to see if 10 is found in the bag"<<endl;
	firstBag.isContain(10);

return 0;

}

