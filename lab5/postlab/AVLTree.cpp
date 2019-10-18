/*
#name Gun Ho Park
#id gp3dz
#date 10/17/2019
#files AVLNode.cpp/h AVLPathTest.cpp AVLTree.cpp.h analysis.pdf Makefile
*/

#include "AVLTree.h"
#include <string>
#include "AVLNode.h"
#include <iostream>
#include <vector>
using namespace std;

AVLTree::AVLTree() { 
  root = NULL; 
  nodeCounter = 0;
}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
  nodeCounter = 0;
}


// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.


void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if(!find(x)){
  root = testInsert(x, root);
  nodeCounter = nodeCounter + 1;
  }
}

int AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  if(n == NULL){
    return 0;
  }
  return height(n->left)-height(n->right);
}

// void AVLTree::balanceIt(AVLNode*& n){

// }

AVLNode* AVLTree::testInsert(const string& x, AVLNode*& node){
  if(node == NULL){
    return(newNode(x));
  }
  if(x < node->value){
    node->left = testInsert(x,node-> left);
  }else if(x > node->value){
    node->right=testInsert(x,node->right);
  }else{
    return node;
  }

  node->height = 1 + max(height(node->left), height(node->right));

  int balances = balance(node);

  if(balances > 1 && x < node->left->value){
    return rotateRight(node);
  }
  if(balances < -1 && x > node->right->value){
    return rotateLeft(node);
  }
  if(balances > 1 && x > node ->left -> value){
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }
  if(balances<-1 && x < node->right->value){
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }
  return node;
}
/*
void AVLTree::insert(const string& x, AVLNode*& node){
  AVLNode* tempNode = new AVLNode;
  tempNode -> value = x;
  tempNode -> height = 1;

  if(root == NULL){
    root = tempNode;
  }else if(node -> value > x){
    if(node -> left != NULL){
      insert(x, node->left);
    }else{
      node -> left = tempNode;
    }
  }else if(node -> value < x){
    if(node -> right != NULL){
      insert(x, node-> right);
    }else{
      node -> right = tempNode;
    }
  }
  
  node->height = max(height(node->left),height(node->right))+1;

  // if(balance(node)>1 && x<node->left->value)
  //    rotateRight(node);
  if(balance(node)<-1 && x>node->right->value){
      cout << "Asdasd"<<endl;
     rotateLeft(node);
   }
  // if(balance(node)>1 && x>node->left->value){
  //   node->left = rotateLeft(node->left);
  //    rotateRight(node);
  // }
  


  // if(balance(node)<-1 && x<node->right->value){
  //   node->right = rotateRight(node->right);
  //    rotateLeft(node);
  // }
  
  

}
*/
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { 
  root = remove(root, x); 
  nodeCounter = nodeCounter - 1;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  vector<string> ansVec;

  string ansString ="";

  if(finda(x,root,ansVec)){
    for(int i=0;i<ansVec.size();i++){
      ansString = ansString + ansVec[i] + " ";
    }
  }
  return ansString;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  vector<string> randomVec;
  return finda(x, root, randomVec);


}

bool AVLTree::finda(const string& x, AVLNode*& node, vector<string>& path) {
  
  if(!node){
    return false;
  }

  path.push_back(node -> value);

  if(node->value == x){
    return true;
  }

  if(finda(x ,node->left,path) ||
    finda(x,node->right,path)){
    return true;
  }

  path.pop_back();
  return false;
}


// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return nodeCounter;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.


// rotateLeft performs a single rotation on node n with its right child.
// AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
//   // YOUR IMPLEMENTATION GOES HERE
//     // YOUR IMPLEMENTATION GOES HERE
//   AVLNode *q = n -> left;
//   n -> left = q -> right;
//   q -> right = n;

//   n->height = max(height(n->left),height(n->right))+1;
//   q->height = max(height(q->left),n->height)+1;
//   n=q;
//   return n;
// }

AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode *q = n -> right;
  AVLNode *w = q -> left;
  q->left = n;
  n->right = w;

  n->height = max(height(n->left),height(n->right))+1;
  q->height = max(height(q->left),height(q->right))+1;
  return q;
}


// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode *q = n -> left;
  AVLNode *w = q -> right;
  q->right = n;
  n->left = w;

  n->height = max(height(n->left),height(n->right))+1;
  q->height = max(height(q->left),height(q->right))+1;
  return q;

}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
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
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  // balance(n);

  int balances = balance(n);

  cout << balances << endl;

  if(balances > 1 && x < n->left->value){
    return rotateRight(n);
  }
  if(balances < -1 && x > n->right->value){
    return rotateLeft(n);
  }
  if(balances > 1 && x > n ->left -> value){
    n->left = rotateLeft(n->left);
    return rotateRight(n);
  }
  if(balances<-1 && x < n->right->value){
    n->right = rotateRight(n->right);
    return rotateLeft(n);
  }



  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}


AVLNode* AVLTree::newNode(string x){
  AVLNode* node = new AVLNode();
  node->value = x;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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
  cout << root->value << root->height <<endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }