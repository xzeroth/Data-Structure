/*
Name Gun Ho Park
Id gp3dz
Date 10/13/2019
File TreeCalc.cpp/h
     TreeCalcTest.cpp
     TreeNode.cpp/h
*/


// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    stack<TreeNode*> mystack;

}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    if(!mystack.empty()){
        cleanTree(mystack.top());
    }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr){
        cleanTree(ptr->left);
        cleanTree(ptr->right);
        delete ptr;
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *node = new TreeNode(val);
    
    if(isdigit(val[0]) || val.length() > 1){
        mystack.push(node);
    }else if(val[0] == '/' || 
             val[0] == '*' || 
             val[0] == '-' || 
             val[0] == '+'){
        TreeNode *right = mystack.top();
        mystack.pop();
        node -> right = right;

        TreeNode *left = mystack.top();
        mystack.pop();
        node -> left = left;

        mystack.push(node);
    }

}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format

    if(ptr == NULL){
        return;
    }
    cout << ptr -> value << " ";

    printPrefix(ptr->left);
    printPrefix(ptr->right);
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
    
    if(ptr->left != NULL){
        cout << "(";
        printInfix(ptr->left);
    }
    if( (ptr->value[0] == '-'  ||
         ptr->value[0] == '+'  ||
         ptr->value[0] == '/'  ||
         ptr->value[0] == '*') &&
         ptr->value.length() == 1){
        cout << " " << ptr->value << " ";
    }else{
        cout << ptr -> value; 
    }
    if(ptr->right != NULL){
        printInfix(ptr->right);
        cout << ")";
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if(ptr == NULL){
        return;
    }
    printPostfix(ptr->left);
    printPostfix(ptr->right);

    cout << ptr -> value << " ";

}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result

    if(ptr == NULL){
        return 0;
    }
    calculate(ptr->left);
    calculate(ptr->right);

    if(ptr->value == "+"){
        ptr->value = to_string(stoi(ptr->right->value)+stoi(ptr->left->value));
    }else if(ptr->value == "-"){
        ptr->value = to_string(stoi(ptr->left->value)-stoi(ptr->right->value));
    }else if(ptr->value == "*"){
        ptr->value = to_string(stoi(ptr->right->value)*stoi(ptr->left->value));
    }else if(ptr->value == "/"){
        ptr->value = to_string(stoi(ptr->left->value)/stoi(ptr->right->value));
    }
    return stoi(ptr->value);
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = calculate(mystack.top());
    while(!mystack.empty()){
        mystack.pop();
    }
    return i;
}

























