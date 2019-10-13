/*
Name : Gun Ho Park
ID : gp3dz
Date : 09/17/2019
Files : unix.questions.txt
		postfixCalculator.cpp
		testPostFixCalc.cpp
		postfixCalculator.h
*/

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

#include "postfixCalculator.h"

using namespace std;

postfixCalculator::postfixCalculator(){
	newStack = new stack<int>;
}

void postfixCalculator::addOn(int value){

	newStack -> push(value);

}


void postfixCalculator::addOn(string equation){

	vector<string> tempVector;

	string word = "";
	for (int i = 0 ; i < equation.length() ; i++){
		if( equation.at(i) == ' ' ){
			tempVector.push_back(word);
			word = "";
		}else if(i == equation.length() - 1){
			word = word + equation.at(i);
			tempVector.push_back(word);
		}else{
			word = word + equation.at(i);
		}
	}
	// cout << tempVector[0] << endl;
	// cout << tempVector[1] << endl;
	// cout << tempVector[2] << endl;
	// cout << tempVector[3] << endl;
	// cout << tempVector[4] << endl;
	// cout << tempVector[5] << endl;

	for( int x = 0 ; x < tempVector.size() ; x++ ){
		if( tempVector[x] != "+" && 
			tempVector[x] != "-" && 
			tempVector[x] != "*" &&
			tempVector[x] != "/"){
			int tempInput = stoi(tempVector[x]);

			// stringstream num(tempVector[x]);
			// num >> tempInput;
			addOn(tempInput);
		}else{
			addOn(tempVector[x]);
		}
	}



	// for( int i = 0 ; i < equation.length() ; i++){
	// 	addOn(equation.at(i));
	// 	cout << checkTop() << endl;
	// }

}

void postfixCalculator::addOn(char sign){

	if ( sign == '-' ){
		int temp1 = checkTop();
		remove();
		int temp2 = checkTop();
		remove();
		newStack -> push(temp2 - temp1);
	}else if( sign == '+' ){
		int temp1 = checkTop();
		remove();
		int temp2 = checkTop();
		remove();
		newStack -> push(temp2 + temp1);
	}else if( sign == '*' ){
		int temp1 = checkTop();
		remove();
		int temp2 = checkTop();
		remove();
		newStack -> push(temp2 * temp1);
	}else if( sign == '/' ){
		int temp1 = checkTop();
		remove();
		int temp2 = checkTop();
		remove();
		newStack -> push(temp2 / temp1);
	}else if( sign == '~' ){
		int temp1 = checkTop();
		temp1 = temp1 * -1;
		remove();
		newStack -> push(temp1);
	}


}

int postfixCalculator::checkTop(){
	if(isEmpty()){
		cout << "Stack is empty, nothing to check" << endl;
		cout << "Shutting down program" << endl;
		exit(-1);
	}else{
		return newStack -> top();
	}
	return 0;
}

void postfixCalculator::remove(){
	if(isEmpty()){
		cout << "Stack is empty, can't remove" << endl;
		cout << "Shutting down program" << endl;
		exit(-1);
	}else{
		newStack -> pop();
	}
}

bool postfixCalculator::isEmpty() const{
	return newStack -> empty();
}

int postfixCalculator::getAns(){
	return checkTop();
}



























