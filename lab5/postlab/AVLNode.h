/*
#name Gun Ho Park
#id gp3dz
#date 10/17/2019
#files AVLNode.cpp/h AVLPathTest.cpp AVLTree.cpp.h analysis.pdf Makefile
*/

#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
  AVLNode();
  ~AVLNode();

  string value;
  AVLNode* left;
  AVLNode* right;
  int height;

  friend class AVLTree;
};

#endif