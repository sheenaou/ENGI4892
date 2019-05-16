#include "HashWithChaining.hxx"
#include "HashWithQuadratic.hxx"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int ac, char* av[]){

	function<int(int)> concatEven = [] (int key) {
		string s=to_string(key);
		string temp="";
		int length=s.size();
		for (int i=0 ; i<length ; i+=2){
			temp+=( s.at(i) );
		}
		int code = stoi(temp);
		return code;
	};

	function<int(int)> concatOdd = [] (int key) {
		string s=to_string(key);
		string temp="";
		int length=s.size();
		for (int i=1 ; i<length ; i+=2){
			temp.push_back( s.at(i) );
		}
		int code = stoi(temp);
		return code;
	};

  // concat even digits, chaining
	HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
	HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
	HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
	HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
  // FIXME

	int number=0;
	string name="";

	ifstream myFile;
	myFile.open("students.txt");
	if (myFile.is_open()){	
		for(int i=0 ; i<100 ;i++){		
			myFile>>number;
			myFile>>name;
			h1.insert(number,name);
			h2.insert(number,name);
			h3.insert(number,name);
			h4.insert(number,name);
		}

		cout<<"***********************************************************************"<<endl;
		cout<<"				STATISTICS                                    "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"Total Keys for H1:"<< h1.totalKeysExamined()<<endl;
		cout<<"Total Keys for H2:"<< h2.totalKeysExamined()<<endl;
		cout<<"Total Keys for H3:"<< h3.totalKeysExamined()<<endl;
		cout<<"Total Keys for H4:"<< h4.totalKeysExamined()<<endl;
		cout<<endl;
		cout<<"Load Factor for H1:"<<h1.loadFactor()<<endl;
		cout<<"Load Factor for H2:"<<h2.loadFactor()<<endl;
		cout<<"Load Factor for H3:"<<h3.loadFactor()<<endl;
		cout<<"Load Factor for H4:"<<h4.loadFactor()<<endl;

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 1                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h1.print();

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 2                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h2.print();

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 3                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h3.print();
	
		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 4                                 "<<endl;
		cout<<"***********************************************************************"<<endl;
		h4.print();

		cout<<"***********************************************************************"<<endl;
		cout<<"				FIND A VALUE                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"Search H1 for 200292840. The student found was:"<< *h1.find(200292840)<<endl;
		cout<<"Search H2 for 200292840. The student found was:"<< *h2.find(200292840)<<endl;
		cout<<"Search H3 for 200292840. The student found was:"<< *h3.find(200292840)<<endl;
		cout<<"Search H4 for 200292840. The student found was:"<< *h4.find(200292840)<<endl;	
	
		cout<<"***********************************************************************"<<endl;
		cout<<"				STATISTICS                                    "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"Total Keys for H1:"<< h1.totalKeysExamined()<<endl;
		cout<<"Total Keys for H2:"<< h2.totalKeysExamined()<<endl;
		cout<<"Total Keys for H3:"<< h3.totalKeysExamined()<<endl;
		cout<<"Total Keys for H4:"<< h4.totalKeysExamined()<<endl;

		cout<<"***********************************************************************"<<endl;
		cout<<"				FIND A VALUE                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"Search H1 for 200773018. The student found was:"<< *h1.find(200773018)<<endl;
		cout<<"Search H2 for 200773018. The student found was:"<< *h2.find(200773018)<<endl;
		cout<<"Search H3 for 200773018. The student found was:"<< *h3.find(200773018)<<endl;
		cout<<"Search H4 for 200773018. The student found was:"<< *h4.find(200773018)<<endl;
		
		cout<<"***********************************************************************"<<endl;
		cout<<"				STATISTICS                                    "<<endl;
		cout<<"***********************************************************************"<<endl;
		cout<<"Total Keys for H1:"<< h1.totalKeysExamined()<<endl;
		cout<<"Total Keys for H2:"<< h2.totalKeysExamined()<<endl;
		cout<<"Total Keys for H3:"<< h3.totalKeysExamined()<<endl;
		cout<<"Total Keys for H4:"<< h4.totalKeysExamined()<<endl;

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 1                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h1.print();

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 2                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h2.print();

		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 3                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h3.print();
	
		cout<<"***********************************************************************"<<endl;
		cout<<"				HASH TABLE 4                                  "<<endl;
		cout<<"***********************************************************************"<<endl;
		h4.print();
	}
return 0;
}
