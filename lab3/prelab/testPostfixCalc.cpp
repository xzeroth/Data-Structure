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
#include <ctype.h>
#include <vector>

#include "postfixCalculator.h"

using namespace std;

int main(){

	postfixCalculator* cs = new postfixCalculator;




	//Infix: ( 3 + 6 ) - ( 8 / 4 )
	//Postfix: 3 6 + 8 4 / -

	// cs -> addOn("3 6 + 8 4 / -");
	// cout << cs -> getAns() << endl << endl;

	// cs -> addOn("- 50 *");
	// cout << cs -> checkTop();
	// cout << cs -> getAns() << endl << endl;

	// cs -> addOn("20 10 - -3 10 - - 2 -");
	// cout << cs -> getAns() << endl << endl;

	cs -> addOn("3 6 + 8 4 / -");
	cout << cs -> getAns()<< endl<< endl;

	// cs -> addOn(20);
	// cout << cs -> getAns() << endl;
	// cs -> addOn(10);
	// cout << cs -> getAns() << endl;
	// cs -> addOn('-');
	// cout << cs -> getAns() << endl;
	// cs -> addOn(-3);
	// cout << cs -> getAns() << endl;
	// cs -> addOn(10);
	// cout << cs -> getAns() << endl;
	// cs -> addOn('-');
	// cout << cs -> getAns() << endl;
	// cs -> addOn('-');
	// cout << cs -> getAns() << endl;
	// cs -> addOn(2);
	// cout << cs -> getAns() << endl;
	// cs -> addOn('-');
	// cout << cs -> getAns() << endl;


	// cs -> addOn(3);
	// cout << cs -> getAns() << endl;
	// cs -> addOn(6);
	// cout << cs -> getAns() << endl;
	// cs -> addOn('+');
	// cout << cs -> getAns() << endl;
	// cs -> addOn(8);
	// cout << cs -> getAns() << endl;
	// cs -> addOn(4);
	// cout << cs -> getAns() << endl;
	// cs -> addOn('/');
	// cout << cs -> getAns() << endl;
	// cs -> addOn('-');
	// cout << cs -> getAns() << endl;




	//ASCII variables

	// int rightOpen = int('(');
	// int leftOpen = int(')');
	// int plus = int('+');
	// int minus = int('-');
	// int divide = int('/');
	// int multi = int('*');



	// cs -> addOn(1);
	// cout << cs -> checkTop() << endl;
	// 	cs -> addOn(2);
	// cout << cs -> checkTop() << endl;
	// 	cs -> addOn(3);
	// cout << cs -> checkTop() << endl;
	// 	cs -> addOn(4);
	// cout << cs -> checkTop() << endl;

	// cs -> remove();
	// cout << cs -> checkTop() << endl;
	// 	cs -> remove();
	// cout << cs -> checkTop() << endl;
	// 	cs -> remove();
	// cout << cs -> checkTop() << endl;
	// 	cs -> remove();
	// cout << cs -> checkTop() << endl;


	// cout << cs -> isEmpty() << endl;

	return 0;
}