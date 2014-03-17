// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-25 03:20:38
// status:	0
// result:	15
// memory:	3480
// signal:	0
// public:	false
// ------------------------------------------------
#ifndef STACK_H
#define STACK_H
//#include "BinaryTree.h"
using namespace std;

#include <cassert>
#include <vector>

template<class T>
class stack
{
public:
    T pop()         { assert(!empty()); T v = _data.back(); _data.pop_back(); return v; }
    void push(T x)  { _data.push_back(x); }
    bool empty()    { return _data.empty(); }
    int size()      { return _data.size(); }

private:
    std::vector<T> _data;
};

#endif  /* STACK_H */
#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

template<typename T> class BinaryTree
{
public:
    // Binary Tree Things
    BinaryTree();                 // default constructor to make empty tree
    BinaryTree(T ro);             // default constructor 2 to make tree with only root
    BinaryTree(T ro, T le, T ri); // default constructor 3 to make complete binary tree
    ~BinaryTree();                // destructor for dynamics

    BinaryTree(BinaryTree const& other) : root(other.root? new Tree_Node(*other.root) : 0) {}

    bool  isEmpty();              // method that returns t/f if tree is empty
    T     info();                 // method to return value in root of the tree
    void  inOrder();              // traverses nodes in a tree left, root, right
    void  preOrder();             // traverses nodes in a tree root, left, right
    void  postOrder();            // traverses nodes in a tree left, right, root

private:
    struct Tree_Node              // represents a node
    {
        T data;
        Tree_Node *left;      // left pointer
        Tree_Node *right;     // right pointer

        Tree_Node(T data, Tree_Node* left = 0, Tree_Node* right = 0) 
            : data(data), left(left), right(right) {}

        Tree_Node(Tree_Node const& other) 
            : data(other.data),
            left (other.left? new Tree_Node(*other.left) : 0),
            right(other.right?new Tree_Node(*other.right) : 0)
        {}

        ~Tree_Node() 
        {
            delete left;
            delete right;
        }
    };

    Tree_Node *root;              // create root with 2 pointers from this    };
};
/***********************************************************************/

template<typename T> BinaryTree<T>::BinaryTree() 
    : root(0)
{
}

template<typename T> BinaryTree<T>::BinaryTree(T ro) 
    : root(new Tree_Node(ro, 0, 0))
{
}

template<typename T> BinaryTree<T>::BinaryTree(T ro, T le, T ri)
    : root(new Tree_Node(ro,
            new Tree_Node (le, 0, 0),
            new Tree_Node (ri, 0, 0)))
{
}

template<typename T> BinaryTree<T>::~BinaryTree() {
    delete root; 
}

template<typename T> bool BinaryTree<T>::isEmpty()
{
    return !root;
}

template<typename T> T BinaryTree<T>::info()
{
}

template<typename T> void BinaryTree<T>::inOrder()
{
}

template<typename T> void BinaryTree<T>::preOrder()
{
}

template<typename T> void BinaryTree<T>::postOrder()
{
}

#endif  /* BINARYTREE_H */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <ctime>
#include <limits>
//#include "BinaryTree.h"
//#include "stack.h"

using namespace std;

int main()
{
    stack<BinaryTree<char> > testing;
    BinaryTree<char> testing2('d', 'd', 'd');
    testing.push(testing2);
    cout << testing.size();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
1
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
