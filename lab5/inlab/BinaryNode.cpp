/*name Gun Ho Park
id gp3dz
date 10/15/2019
files binaryNode.cpp/h
binaryNode.h
binarysearchtree.h/cpp
BSTPathTest.cpp
*/


#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
  value = "?";
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}