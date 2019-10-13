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


/*
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function print()
 */
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "stackNode.h"

using namespace std;

// When reading in ListItr.h first, it starts reading in this file
// before declaring that ListItr is a class.  This file then include
// ListItr.h, but beacuse of the #ifndef LISTITR_H statement, the code
// in that file is not read.  Thus, in this case, this List.h file
// will be read in, and will not know that ListItr is a class, which
// will cause compilation problems later on in this file.  Got it?
// Isn't C++ fun???

class stack {
public:
    stack();				//Constructor  
    ~stack();			//Destructor
    bool isEmpty() const;		//Returns true if empty; else false
    void push(int x);	//Insert x at tail of list
    void pop(); //new
    int whatTop(); //new
    stackNode* pointTop(); //new
    int size() const; //Returns the number of elements in the list
    void printList();

private:
    stackNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
};



//prints list forwards when direction is true
//or backwards when direction is false
#endif
/* end of List.h */
