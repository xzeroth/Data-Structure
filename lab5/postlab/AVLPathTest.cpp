/*
#name Gun Ho Park
#id gp3dz
#date 10/17/2019
#files AVLNode.cpp/h AVLPathTest.cpp AVLTree.cpp.h analysis.pdf Makefile
*/
#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
  AVLTree avl;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      avl.insert(word);
    } else if (instr == "R") {
      avl.remove(word);
    } else if (instr == "L") {
      cout << "AVL path: " << avl.pathTo(word) << endl;
    }
  }
  cout << "AVL numNodes: " << avl.numNodes() << endl;
}