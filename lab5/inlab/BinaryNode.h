/*name Gun Ho Park
id gp3dz
date 10/15/2019
files binaryNode.cpp/h
binaryNode.h
binarysearchtree.h/cpp
BSTPathTest.cpp
Makefile
*/



#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
  BinaryNode();
  ~BinaryNode();

  string value;
  BinaryNode* left;
  BinaryNode* right;

  friend class BinarySearchTree;
};

#endif