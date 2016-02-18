/*
Author: Matt McColeman
Student ID: 100525235
Date: 01/21/2015
*/

//calling libraries
#include <iostream>

//calling namespace
using namespace std;

//creating sort function for numerical values
//with parameters for numArray
int sort(int *numArray){
//nested for loop to sort the numbers in numArray
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(numArray[i] < numArray[j]){
				swap(numArray[i], numArray[j]);
			}	
		}
	}
//for loop to print numArray
	for(int x = 0; x < 7; x++){
		cout << numArray[x] << " ";
	}

	cout << endl;
	

}

//creating sort function to sort letters alphabetically
//with parameters charArray
char sort(char *charArray){
//nested for loop to sort letters
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if(charArray[i] < charArray[j]){
				swap(charArray[i], charArray[j]);
			}	
		}
	}
//for loop to print sorted array
	for(int x = 0; x < 7; x++){
		cout << charArray[x];
	}

	cout << endl;

}

int main(){
//initializing numArray and charArray
	int numArray[] = {1, 2, 3, 4, 5, 4, 3};
	char charArray[] = {'a', 'c', 'g', 'j', 'a', 'c', 'd'};
//calling NumArray and charArray
	sort(numArray);
	sort(charArray);
}
