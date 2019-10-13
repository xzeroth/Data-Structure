/*
Name Gun Ho Park
Date 09/25/2019
ID gp3dz
Class CS2150
file postlab4.cpp
*/


#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void oneCounter(int x);
int ones = 0;

int main(int argc , char* argv[]){

	if( argc == 1 ){
		cout << "Need an argument.. Exiting program..." << endl;
		exit(-1);
	}else{
		int number = stoi(argv[1]);
		cout << "There are ";
		oneCounter(number);
		cout << ones << " ones in " << argv[1] << " binary format." << endl;
	}

	return 0;
}

void oneCounter(int x){
	if ( x > 0 ){
		oneCounter(x / 2);
		ones = ones + x % 2;
	}
}