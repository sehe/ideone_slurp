// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-09-25 03:30:22
// status:	0
// result:	15
// memory:	3440
// signal:	0
// public:	false
// ------------------------------------------------
#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

#include <iostream>
#include <memory>

template<typename T> class BinaryTree
{
public:
    // Binary Tree Things
    BinaryTree();                 // default constructor to make empty tree
    BinaryTree(T ro);             // default constructor 2 to make tree with only root
    BinaryTree(T ro, T le, T ri); // default constructor 3 to make complete binary tree

    bool  isEmpty();              // method that returns t/f if tree is empty
    T     info();                 // method to return value in root of the tree
    void  inOrder();              // traverses nodes in a tree left, root, right
    void  preOrder();             // traverses nodes in a tree root, left, right
    void  postOrder();            // traverses nodes in a tree left, right, root

private:
    struct Tree_Node;
    typedef std::shared_ptr<Tree_Node> NodePtr;

    struct Tree_Node              // represents a node
    {
        T data;
        NodePtr left;             // left pointer
        NodePtr right;            // right pointer

        Tree_Node(T data, NodePtr  left = 0, NodePtr  right = 0)
                : data(data), left(left), right(right) {}

        void  inOrder()    // traverses nodes in a tree left, root, right
        {
            if (left) left->inOrder();
            //else std::cout << "[left null]\n";

            std::cout << data << "\n";

            if (right) right->inOrder();
            //else std::cout << "[right null]\n";
        }
        void  preOrder()   // traverses nodes in a tree root, left, right
        {
            std::cout << data << "\n";

            if (left) left->preOrder();
            //else std::cout << "[left null]\n";

            if (right) right->preOrder();
            //else std::cout << "[right null]\n";
        }
        void  postOrder()  // traverses nodes in a tree left, right, root
        {
            if (left) left->postOrder();
            //else std::cout << "[left null]\n";

            if (right) right->postOrder();
            //else std::cout << "[right null]\n";

            std::cout << data << "\n";
        }
    };

    NodePtr root; // create root with 2 pointers from this
};
/***********************************************************************/

template<typename T> BinaryTree<T>::BinaryTree() 
    : root(0)
{
}

template<typename T> BinaryTree<T>::BinaryTree(T ro) 
    : root(new Tree_Node(ro))
{
}

template<typename T> BinaryTree<T>::BinaryTree(T ro, T le, T ri)
    : root(new Tree_Node(ro, NodePtr(new Tree_Node (le)), NodePtr(new Tree_Node (ri))))
{
}

template<typename T> bool BinaryTree<T>::isEmpty()
{
    return !root;
}

template<typename T> T BinaryTree<T>::info()
{
    if (!root) throw "oops";
    return root->data;
}

template<typename T> void BinaryTree<T>::inOrder()
{
    if (root) 
        root->inOrder();
}

template<typename T> void BinaryTree<T>::preOrder()
{
    if (root) 
        root->preOrder();
}

template<typename T> void BinaryTree<T>::postOrder()
{
    if (root) 
        root->postOrder();
}

#endif  /* BINARYTREE_H */

#include <iostream>
#include <stack>
//#include "BinaryTree.h"
//#include "stack.h"

using namespace std;

int main()
{
    BinaryTree<char> testing2('a', 'b', 'c');
    std::cout << "------------- inOrder: \n";
    testing2.inOrder();
    std::cout << "------------- preOrder: \n";
    testing2.preOrder();
    std::cout << "------------- postOrder: \n";
    testing2.postOrder();

    std::stack<BinaryTree<char> > testing;
    testing.push(testing2);
    cout << testing.size();
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
------------- inOrder: 
b
a
c
------------- preOrder: 
a
b
c
------------- postOrder: 
b
c
a
1
#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif
