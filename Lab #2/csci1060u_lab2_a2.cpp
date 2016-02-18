/*
Author: Matt McColeman
Student ID: 100525235
Date: 01/21/2015
*/

//calling libraries
#include <iostream>
#include <stdlib.h>
#include <fstream>

//calling namespace standard
using namespace std;

//creating sort function with parameters for the array of numbers
int sort(int *numArray){
//instructing the code to output to a text file
	ofstream textDoc("csci1060u_lab2_a2.txt");
//for loop entering one thousand numbers into the array 
//ranging from 1 to 100
	for(int x = 0; x < 1000; x++){
		numArray[x] = (rand()%100)+1;
	}
//nested for loop sorting the array
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			if(numArray[i] < numArray[j]){
				swap(numArray[i], numArray[j]);
			}	
		}
	}
//for loop printing the sorted array into the text document
	for(int c = 0; c < 1000; c++){
		textDoc << numArray[c] << " ";
	}
//closing the text document
	textDoc.close();

}

int main(){
//initializing an array for 1000 integers
	int numArray[1000];
//calling sort function in main function
//with parameters to sort numArray
	sort(numArray);

}
