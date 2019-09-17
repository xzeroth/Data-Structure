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

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

List::List(){
  head = new ListNode;
  tail = new ListNode;
  head -> next = tail;
  tail -> previous = head;
  count = 0;
  

}
List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
List::~List(){

}
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
  if ( count == 0 ){
    return true;
  }else {
    return false;
  }

}
void List::makeEmpty(){

  int x = size();

  do{
    ListItr itrPosition(first());
    remove(itrPosition.current -> value);
    x--;
  }while(x>0);

}

ListItr List::first(){

  return(head -> next);

}

ListItr List::last(){

  ListItr end = ListItr(tail);
  end.moveBackward();

  return end;

}
void List::insertAfter(int x, ListItr position){

  ListNode * tempNode = new ListNode();
  tempNode -> value = x;

  tempNode -> next = position.current -> next;
  tempNode -> previous = position.current;
  position.current -> next -> previous = tempNode;
  position.current -> next = tempNode;

  count++;

}


void List::insertBefore(int x, ListItr position){

  ListNode * tempNode = new ListNode();
  tempNode -> value = x;

  tempNode -> next = position.current;
  tempNode -> previous = position.current -> previous;
  position.current -> previous -> next = tempNode;
  position.current -> previous = tempNode;

  count++;
  
}
void List::insertAtTail(int x){
  ListNode * tempNode = new ListNode;
  tempNode -> value = x;

    tempNode -> next = tail;
    tail -> previous -> next = tempNode;
    tempNode -> previous = tail -> previous;
    tail -> previous = tempNode;
  // }

  count++;

}
void List::remove(int x){

  ListItr found = find(x);

  if(found.current != tail){

    found.current -> previous -> next = found.current -> next;
    found.current -> next -> previous = found.current -> previous;
    
    delete found.current;
    count--;
  }
  

}

ListItr List::find(int x){

  ListItr itrPosition(first());

  while( itrPosition.current -> value != x){

    itrPosition.moveForward();
    if(itrPosition.current == tail){
      return itrPosition;
    }

  }

    return itrPosition;

}

int List::size() const{
  return count;

}

void printList(List& source, bool direction){


  if(direction){

    ListItr itrPosition(source.first());
    for( int i = 0 ; i < source.size() ; i++){
      cout << itrPosition.retrieve() << endl;
      itrPosition.moveForward();
    }
  }else{
    ListItr itrPosition(source.last());
    for( int i = 0 ; i < source.size() ; i++){
      cout << itrPosition.retrieve() << endl;
      itrPosition.moveBackward();
      }
    }


    

  }

































