#include <stdlib.h>
#include <stdio.h>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/// @brief Binary search tree node 
typedef struct BinarySearchTree {
    int val;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
} BinarySearchTree;

/// @brief creates new Binary search tree 
/// @return BinarySearchTree
BinarySearchTree* create();

/// @brief performs pre order traversal in binary search tree 
/// @param root root of binary search tree 
void preOrderTraverse(BinarySearchTree* root);

/// @brief performs in order traversal in binary search tree 
/// @param root root of binary search tree 
void inOrderTraverse(BinarySearchTree* root);

/// @brief performs post order traversal in binary search tree 
/// @param root root of binary search tree 
void postOrderTraverse(BinarySearchTree* root);

/// @brief count nodes in given binary search tree 
/// @param root root of binary search tree 
int countNodes(BinarySearchTree* root);

/// @brief search node with value val in the given binary search tree 
/// @param root root of given binary search tree 
/// @param val value of node to search
/// @return pointer to the node with value val 
BinarySearchTree* searchNode(BinarySearchTree* root, int val);

/// @brief find inorder predecessor of given binary search tree 
/// @param root root of given binary search tree 
/// @return predecessor of given binary search tree 
BinarySearchTree* predecessor(BinarySearchTree* root, int val);

/// @brief find inorder successor of given binary search tree 
/// @param root root of given binary search tree 
/// @return successor of given binary search tree 
BinarySearchTree* successor(BinarySearchTree* root, int val);

/// @brief inserts a new node in given binary search tree 
/// @param root root of binary search tree 
/// @param val value to be inserted in new node 
/// @return root of binary search tree 
BinarySearchTree* insertNode(BinarySearchTree* root, int val);

/// @brief delete the node having value val 
/// @param root root of given binary search tree 
/// @param val value of node that has to be deleted 
/// @return root of binary search tree 
BinarySearchTree* deleteNode(BinarySearchTree* root, int val);

/// @brief convert given binary tree into Balanced Binary Search Tree 
/// @param root root of given binary search tree 
BinarySearchTree* convertToBalancedBST(BinarySearchTree* root);

/// @brief free up memory allocated by the binary search tree 
/// @param root root of binary search tree 
void memory_release(BinarySearchTree* root);

#endif
