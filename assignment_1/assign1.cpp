#include <iostream>
#include <fstream>
#include "assign1.h"
using namespace std;


int maximum(int *array, int size){
int hold= array[0];
for(int i=0;i<size-1;i++){
	if (hold < array[i])
		hold=array[i];
}
return hold;
}

int minimum(int *array, int size){
int hold=array[0];
for(int i=0;i<size-1;i++){
	if (hold > array[i])
		hold=array[i];
}
return hold;
}

double average(int *array, int size){
double hold;
for(int i=0;i<size;i++){
	hold = hold + array[i];
}
hold = hold/size;
return hold;
}

int main() {
ifstream myfile;
int rows; 	//creation of variable to hold the first number in the text file which represents the number of rows in the ragged array
int cols; 	//creation of variable to hold the first number in the next row of the text file which represents the number of columns
double overallAverage;
int overallSize;
int overallMax;
int overallMin;
myfile.open("array.txt");	 //The text file is open
	if (myfile.is_open()){		//ensures the file is open successfully
		myfile>>rows;		//inserts value of the first number in the text file into the variable "rows"
		myArrayStruct* rowArray= new myArrayStruct[rows] ; //create the first array with the number of rows in the file as the size
		myfile>>cols;		//inserts the value of the first number of the second row of the text file into the variable "cols"
		for (int i=0;i<rows;i++){	//iterates through the ragged array
			rowArray[i].colsArray=new int[cols];		//creates a dynamically allocated array of type int
			
			for (int j=0;j<cols;j++){		//iterates through the row and inserts the values into the second array, then outputs the value
				myfile>>rowArray[i].colsArray[j];
				cout <<rowArray[i].colsArray[j]<<" ";
				overallSize++;
				overallAverage= overallAverage + rowArray[i].colsArray[j];
			}
			rowArray[i].max_=maximum(rowArray[i].colsArray,cols); 		//calculates the highest number in the designated row
			rowArray[i].min_=minimum(rowArray[i].colsArray,cols);		//calculates the lowest number in the designated row 
			rowArray[i].average_=average(rowArray[i].colsArray,cols);	//calculates the average of all the elements in the designated row
			rowArray[i].size_=cols;		//sets the value of size_ to the number of elements in the row
			cout <<endl;
			myfile>>cols;	//get the first element on the next row which indicates the number of columns
		}
		
		overallAverage=overallAverage/overallSize;
		overallMin=rowArray[0].min_;
		overallMax=rowArray[0].max_;
		for (int i=0;i<rows;i++){
			if ( overallMin > (rowArray[i].min_))
				overallMin=rowArray[i].min_;
			if ( overallMax < (rowArray[i].max_))
				overallMax=rowArray[i].max_;
			cout <<endl<<"The maximum number in row " << i << " is: " << rowArray[i].max_;
			cout <<endl<<"The minumum number in row " << i << " is: " << rowArray[i].min_;
			cout <<endl<<"The average value in row " << i << " is: " <<rowArray[i].average_;
			cout <<endl<<"The size of the array is: "<< rowArray[i].size_<<endl;
			
			
		}
		cout <<endl<<"The maximum number overall is " <<overallMax;
		cout <<endl<<"The minumum number overall is " <<overallMin;
		cout <<endl<<"The average value overall is " <<overallAverage;
		cout <<endl<<"The overall size is "<< overallSize<<endl;

	
		for (int i=0;i<rows;i++){		//deletes any dynamically allocated memory
				delete rowArray[i].colsArray;
		}
		delete [] rowArray;
		
	}
return 0;
}

