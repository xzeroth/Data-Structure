

/*name Gun Ho Park
id gp3dz
date 10/15/2019
files binaryNode.cpp/h
binaryNode.h
binarysearchtree.h/cpp
BSTPathTest.cpp
*/







#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
  BinarySearchTree bst;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      bst.insert(word);
    } else if (instr == "R") {
      bst.remove(word);
    } else if (instr == "L") {
      cout << "BST path: " << bst.pathTo(word) << endl;
    }
  }
  cout << "BST numNodes: " << bst.numNodes() << endl;
  bst.printTree();
}