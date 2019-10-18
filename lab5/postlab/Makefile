#name Gun Ho Park
#id gp3dz
#date 10/17/2019
#files AVLNode.cpp/h AVLPathTest.cpp AVLTree.cpp.h analysis.pdf Makefile


CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -g -std=c++11
OFILES=AVLNode.o AVLPathTest.o AVLTree.o 

.SUFFIXES: .o .cpp

BST: $(OFILES)
	$(CXX) AVLNode.o AVLPathTest.o AVLTree.o
	@echo "yes"

clean:
	-rm -f *.o *~BST

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
