/*
Name : Gun Ho Park
Class : CS2150
Email : gp3dz@virgiani.edu
Files : LifeCycle.h, LifeCycle.cpp, TestLifeCycle.cpp, lifecycle.question.txt
Date : 09/03/2019
 */



#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <string>

using namespace std;


class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }
    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);


#endif
