/*
Name Gun Ho Park
Id gp3dz
Date 10/13/2019
File TreeCalc.cpp/h
     TreeCalcTest.cpp
     TreeNode.cpp/h
*/
// Insert your header information here
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

//Default Constructor -left and right are NULL, value '?'
TreeNode::TreeNode() {
    value="?";
    left=NULL;
    right=NULL;
}

//Constructor - sets value to val
TreeNode::TreeNode(const string & val) {
    value=val;
    left=NULL;
    right=NULL;
}
