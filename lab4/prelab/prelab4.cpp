/* 
name Gun ho Park
Date 09 24 2019
Class CS2150
ID gp3dz
file prelab4.cpp
	floatingpoint.pdf
*/


#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <climits>
#include <cmath>


using namespace std;

void overflow();
void sizeOfTest();
void outputBinary(unsigned int x);

int main(){



	outputBinary(1000000);
	sizeOfTest();
	overflow();



return 0;
}


void overflow(){

	unsigned int x = UINT_MAX;
	cout << "before adding 1: " << x << endl;
	x = x + 1;
	cout << "after adding 1: " << x << endl;
	cout << " " << endl;

	
	cout << "When 1 is added to the max unsigned int it print out 0."<< endl; 
	cout << "Because when all the bits in binary is 1 ( ex. 1111 1111 1111 )" << endl;
	cout << " adding 1 (0000 0000 0001) will convert all the bits in to 0." << endl;
	

}

void sizeOfTest(){

	cout << "size of int in bytes: " << sizeof(int) << endl;
	cout << "size of unsigned int in bytes: " << sizeof(unsigned int) << endl;
	cout << "size of float in bytes: " << sizeof(float) << endl;
	cout << "size of double in bytes: " << sizeof(double) << endl;
	cout << "size of char in bytes: " << sizeof(char) << endl;
	cout << "size of bool in bytes: " << sizeof(bool) << endl;
	cout << "size of int* in bytes: " << sizeof(int*) << endl;
	cout << "size of char* in bytes: " << sizeof(char*) << endl;
	cout << "size of double* in bytes: " << sizeof(double*) << endl;

}

void outputBinary(unsigned int x){
//-19.125
	string asd = "";
	int count = 0;
	
	for ( int i = 31 ; i >= 0 ; i-- ) {
		
		unsigned int power = (unsigned int)(pow(2,i));

		if( power <= x){
			x = x % power;
			asd = asd + "1";
			count++;
		}else {
			asd = asd + "0";
			count++;
		}
		if( count == 4){
			asd = asd + " ";
			count = 0;
		}
	}
	cout << asd << endl;
}






















