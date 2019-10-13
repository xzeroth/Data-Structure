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

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
#include <string>

// next line needed because NULL is part of std namespace
using namespace std;

class stackNode {
public:
    stackNode();                 // Constructor

private:
    int value;
    stackNode *next;

	// for doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class stack;

    // ListItr needs to access/change ListNode as well
   

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.  No constructor is
    // necessary, as an object will be set up by the List class.
};

#endif
