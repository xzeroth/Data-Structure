/*
Name : Gun Ho Park
ID : gp3dz
Date : 09 / 13 / 2019
FileName :  ListItr.cpp/h
			List.cpp/h
			ListNode.cpp/h
			ListTest.cpp
*/



#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>

#include "ListItr.h"
#include "List.h"
#include "ListNode.h"

using namespace std;

ListItr::ListItr(){
	current = NULL;

}
ListItr::ListItr(ListNode* theNode){
	current = theNode;

}
bool ListItr::isPastEnd() const{

	if ( current -> next != NULL){
		return false;
	}else{
		return true;
	}

}
bool ListItr::isPastBeginning() const{
	
	if( current -> next != NULL){
		return false;
	}else{
		return true;
	}

}
void ListItr::moveForward(){

	current = current -> next;

}
void ListItr::moveBackward(){

	current = current -> previous;

}
int ListItr::retrieve() const{

	return current -> value;
}

