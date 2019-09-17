/*
Name : Gun Ho Park
ID : gp3dz
Date : 09/17/2019
Files : unix.questions.txt
		postfixCalculator.cpp
		testPostFixCalc.cpp
		postfixCalculator.h
*/

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>

using namespace std;

class postfixCalculator{
public:
	postfixCalculator();
	void addOn(int value);
	void addOn(char sign);
	void addOn(string equation);
	int checkTop();
	void remove();
	bool isEmpty() const;
	int getAns();

	
private:
	stack<int> * newStack;

	// int rightOpen = int('(');
	// int leftOpen = int(')');
	// int plus = int('+');
	// int minus = int('-');
	// int divide = int('/');
	// int multi = int('*');
};

#endif