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

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctype.h>

#include "stack.h"
#include "stackNode.h"

using namespace std;

class postfixCalculator{
public:
	postfixCalculator();
	void addOn(int value);
	void addOn(string sign);
	int checkTop();
	void remove();
	bool isEmpty() const;
	int getAns();


	
private:
	stack * newStack;

	// int rightOpen = int('(');
	// int leftOpen = int(')');
	// int plus = int('+');
	// int minus = int('-');
	// int divide = int('/');
	// int multi = int('*');
};

#endif