// McColeman_Matt_100525235_Lab01.cpp : Defines the entry point for the console application.
/*
Author: Matt McColeman
Student number: 100525235
Date: 14/01/2015
*/

#include "stdafx.h"
#include <iostream>
#include <array>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string myarray[7] = { "a", "c", "g", "j", "a", "c", "d", };
	
	cout << "original array: ";
	for (int x = 0; x < 7; x++){
		cout << myarray[x];
	}

	cout << endl;

	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (myarray[i] < myarray[j]){
				swap (myarray[i], myarray[j]);
			}
		}
	}
	
	cout << "sorted array: ";

	for (int x = 0; x < 7; x++){
		cout << myarray[x];
	}


	return 0;
}

