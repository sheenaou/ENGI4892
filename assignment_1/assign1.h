#include <iostream>
#include <fstream>
using namespace std;

struct myArrayStruct {
	int size_;	
	int max_;
	int min_;
	double average_;
	int *colsArray;
} ;

int maximum(int *array[], int size);

int minimum(int *array[], int size);

double average(int *array[], int size);


