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
#include <string>
#include <ctype.h>
#include <stdlib.h>

#include "stack.h"

using namespace std;

stack::stack(){
  head = new stackNode;
  tail = new stackNode;
  head -> next = tail;
  count = 0;
  

}

stack::~stack(){

}


bool stack::isEmpty() const{
  if ( count == 0 ){
    return true;
  }else {
    return false;
  }

}

void stack::push(int x){
  stackNode * tempNode = new stackNode;
  tempNode -> value = x;

  stackNode *topNode = pointTop();

  if(!isEmpty()){
    topNode -> next = tempNode;
    tempNode -> next = tail;
   }else{
    tempNode -> next = tail;
    head -> next = tempNode;
   }

  count++;

}

void stack::pop(){

  stackNode *tempNode = head;
  stackNode *deleteNode = pointTop();
  if(!isEmpty()){
    while(tempNode -> next != pointTop()){
      tempNode = tempNode -> next;
    }
      tempNode -> next = tail;
      delete deleteNode;
  }
  count--;

}

stackNode* stack::pointTop(){

  stackNode *tempNode = head;
  if(!isEmpty()){
    while(tempNode -> next != tail){
      tempNode = tempNode -> next;
    }
  }
  return tempNode;
}

int stack::whatTop(){

  return pointTop() -> value;

}

int stack::size() const{
  return count;

}


void stack::printList(){

  stackNode *tempNode = head -> next;
  while(tempNode != tail){
    cout << tempNode -> value << endl;
    tempNode = tempNode -> next;
  }
}





























