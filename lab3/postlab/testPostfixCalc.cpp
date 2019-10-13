/*
Name : Gun Ho Park
ID : gp3dz
Date : 09/20/2019
Files : testPostFixCalc.cpp/h
		stackNode.cpp/h
		stack.cpp.h
		postfixCalculator.cpp.h
		difficulties.txt
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctype.h>

#include "postfixCalculator.h"
#include "stack.h"
#include "stackNode.h"

using namespace std;

int main(){


	int option = 99;
	string equation;
	
	while(option != 0){

		cout <<"Pick options" << endl;
		cout <<"1. Enter your own string"<< endl;
		cout <<"2. Class addition.txt"<<endl;
		cout <<"3. Class subtraction.txt"<<endl;
		cout <<"4. Class multiplication.txt"<<endl;
		cout <<"5. Class division.txt"<<endl;
		cout <<"6. Class negation.txt"<<endl;
		cout <<"0. End program"<<endl;

		postfixCalculator* input = new postfixCalculator;

		cout <<"Enter ...";
		cin >> option;

		switch(option){
			case 1:{
				cout <<"Enter equation : ";
				string tempString;
				cin.ignore(1024, '\n' );
				getline (cin, tempString);
				cout << "You entered " << tempString << endl;
				input -> addOn(tempString);
				input -> getAns();
				break;
			}
			case 2:{
				 equation = "1 2 3 4 5 + + + +";
				cout <<"Answer for " << equation << " is"<< endl;
				input -> addOn(equation);
				input -> getAns();
				break;
			}
			case 3:{
				 equation = "20 10 - -3 10 - - 2 -";
				cout <<"Answer for " << equation << " is"<< endl;
				input -> addOn(equation);
				input -> getAns();
				break;
			}
			case 4:{
				 equation = "-1 -2 -5 3 * 2 -2 * * * *";
				cout <<"Answer for " << equation << " is"<< endl;
				input -> addOn(equation);
				input -> getAns();
				break;
			}
			case 5:{
				 equation = "-1512 -12 -2 / / -2 / 3 /";
				cout <<"Answer for " << equation << " is"<< endl;
				input -> addOn(equation);
				input -> getAns();
				break;
			}
			case 6:{
				 equation = "-1 ~ ~ ~";
				cout <<"Answer for " << equation << " is"<< endl;
				input -> addOn(equation);
				input -> getAns();
				break;
			}
			case 0:{
				cout <<"Ending program..."<<endl;
				exit(-1);
			}
			default:{
				cout << "Invalid input. Try again"<< endl;
			}
		}
	}
	// postfixCalculator* input = new postfixCalculator;

	

	

	// input -> addOn("-1 ~ ~ ~");
	// input -> getAns();


	return 0;
}