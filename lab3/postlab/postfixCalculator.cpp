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
#include <sstream>


#include "postfixCalculator.h"
#include "stack.h"
#include "stackNode.h"

using namespace std;

postfixCalculator::postfixCalculator(){

	newStack = new stack;
}

void postfixCalculator::addOn(int value){

	newStack -> push(value);
	// cout << newStack -> whatTop() << endl;

}

void postfixCalculator::addOn(string equation){

    // Used to split string around spaces. 
    istringstream ss(equation); 
  
    // Traverse through all words 
    do { 
        // Read a word 
        string word; 
        ss >> word; 
  
        // Print the read word 
        if( word != "+" &&
        	word != "-" &&
        	word != "*" &&
        	word != "/" &&
        	word != "~" &&
        	word != ""){

        	// cout << word << "this is input" << endl;

        	int tempNum = stoi(word);
	        // cout << tempNum << endl;
        	addOn(tempNum);

        }else if (word == "+" ){
        	int first = checkTop();
        	remove();
        	int second = checkTop();
        	remove();
        	int ans = first + second;
        	// cout << ans << endl;
        	addOn(ans);
        }else if (word == "-"){
        	int first = checkTop();
        	remove();
        	int second = checkTop();
        	remove();
        	int ans = second - first;
        	// cout << ans << endl;
        	addOn(ans);
        }else if (word == "*"){
        	int first = checkTop();
        	remove();
        	int second = checkTop();
        	remove();
        	int ans = first * second;
        	// cout << ans << endl;
        	addOn(ans);
        }else if (word == "/"){
        	int first = checkTop();
        	remove();
        	int second = checkTop();
        	remove();
        	int ans = second / first;
        	// cout << ans << endl;
        	addOn(ans);
        }else if (word == "~"){
        	int first = checkTop();
        	remove();
        	int ans = first * -1;
        	// cout << ans << endl;
        	addOn(ans);
        }
        // newStack -> insertAtTail(word);
  
        // While there is more to read 
    } while (ss); 

}


int postfixCalculator::checkTop(){
	if(isEmpty()){
		cout << "Stack is empty, nothing to check" << endl;
		cout << "Shutting down program" << endl;
		exit(-1);
	}else{
		return newStack -> whatTop();
	// }
	return 0;
}
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
	return 0;
}

int postfixCalculator::getAns(){
	newStack -> printList();
	return 0;
}



























