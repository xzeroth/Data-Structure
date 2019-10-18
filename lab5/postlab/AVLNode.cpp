/*
#name Gun Ho Park
#id gp3dz
#date 10/17/2019
#files AVLNode.cpp/h AVLPathTest.cpp AVLTree.cpp.h analysis.pdf Makefile
*/
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
  value = "?";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLNode::~AVLNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}