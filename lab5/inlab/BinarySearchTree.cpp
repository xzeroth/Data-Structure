/*name Gun Ho Park
id gp3dz
date 10/15/2019
files binaryNode.cpp/h
binaryNode.h
binarysearchtree.h/cpp
BSTPathTest.cpp
Makefile*/

#include "BinarySearchTree.h"
#include <string>
#include <vector>
#include "BinaryNode.h"
#include <iostream>


using namespace std;

BinarySearchTree::BinarySearchTree() { 
	root = NULL; 
	nodeCounter =0;
}

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if(!find(x)){
	insert(root, x);
	nodeCounter = nodeCounter + 1;
  }
}

void BinarySearchTree::insert(BinaryNode*& node, const string& x){
	BinaryNode* tempNode = new BinaryNode;
	tempNode -> value = x;

	if(root == NULL){
		root = tempNode;
	}else if(node -> value > x){
		if(node -> left != NULL){
			insert(node->left, x);
		}else{
			node -> left = tempNode;
		}
	}else if(node -> value < x){
		if(node -> right != NULL){
			insert(node-> right, x);
		}else{
			node -> right = tempNode;
		}
	}

}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { 
	root = remove(root, x); 
	nodeCounter = nodeCounter - 1;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
	vector<string> ansVec;

	string ansString ="";

	if(finda(root,x,ansVec)){
		for(int i=0;i<ansVec.size();i++){
			ansString = ansString + ansVec[i] + " ";
		}
	}
	return ansString;

}

bool BinarySearchTree::finda(BinaryNode*& node, const string& x, vector<string>& path){

	if(!node){
		return false;
	}

	path.push_back(node -> value);

	if(node->value == x){
		return true;
	}

	if(finda(node->left,x,path) ||
		finda(node->right,x,path)){
		return true;
	}

	path.pop_back();
	return false;




	// if(node != NULL){
	// 	if(x == node -> value){
	// 		return true;
	// 	}
	// 	if(x < node -> value){
	// 		return find(node -> left, x);
	// 	}else if(x > node -> value){
	// 		return find(node -> right, x);
	// 	}
	// }else {
	// 	return false;
	// }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
	vector<string> randomVec;
	return finda(root, x , randomVec);


}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
	return nodeCounter;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void BinarySearchTree::printTree() { 
	printTree(root, NULL, false); 
}