#include <stdlib.h>
#include "Node.h"
#include <iostream>

TEMP
class BinaryTree {
public:
    // constructor
    BinaryTree<type>(type);

    // traversals
    void traversePreOrder();
    void traversePostOrder();
    void traverseInOrder();

private: // variables
    Node<type> *root;

private: // functions
    // the dark side version of pre order traversal 
    static void preOrderTraversal(Node<type> *);
};

TEMP
// constructor
BinaryTree<type>::BinaryTree(type value) {
    // update root
    root = new Node<type>(value);
    // set root parent to null
    root->setParent(NULL);
    // trail tree will be removed in the future
    root->setLeft(new Node<type>('B'));
    root->getLeft()->setLeft(new Node<type>('D'));

    root->setRight(new Node<type>('C'));
    root->getRight()->setLeft(new Node<type>('E'));
    root->getRight()->getLeft()->setRight(new Node<type>('G'));

    root->getRight()->setRight(new Node<type>('F'));
    root->getRight()->getRight()->setLeft(new Node<type>('H'));
    root->getRight()->getRight()->setRight(new Node<type>('I'));


}

TEMP
// print tree traversal in preorder
void BinaryTree<type>::traversePreOrder() {
    // 
    BinaryTree::preOrderTraversal(this->root);
    // stdout flush
    std::cout << std::endl;
}

TEMP
// the dark side version of pre order traversal 
void BinaryTree<type>::preOrderTraversal(Node<type> *root) {
    // current node in the tree
    Node<type> *current = root;
    Node<type> *currentLeft = root->getLeft();
    Node<type> *currentRight = root->getRight();
    
    // print current node's value
    std::cout << current->getValue() << " ";

    // now traverse left and right children
    if(currentLeft) {
        BinaryTree::preOrderTraversal(currentLeft);
    }
    if(currentRight) {
        BinaryTree::preOrderTraversal(currentRight);
    }

}