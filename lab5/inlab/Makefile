#name Gun Ho Park
#id gp3dz
#date 10/15/2019
#files binaryNode.cpp/h
#binaryNode.h
#binarysearchtree.h/cpp
#BSTPathTest.cpp
#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -g
OFILES=BSTPathTest.o BinaryNode.o BinarySearchTree.o

.SUFFIXES: .o .cpp

BST: $(OFILES)
	$(CXX) BSTPathTest.o BinaryNode.o BinarySearchTree.o
	@echo "yes"

clean:
	-rm -f *.o *~BST

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h

