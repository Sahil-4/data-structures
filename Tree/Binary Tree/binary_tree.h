#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

/// @brief Structure to represent a node in the binary tree.
typedef struct BinaryTree {
    int value;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

/// @brief Creates a new tree node.
/// @param value The value to store in the new node.
/// @return A pointer to the newly created binary tree node.
BinaryTree* create(int value);

/// @brief Performs an in-order traversal of the binary tree.
/// @param root The root node of the binary tree.
void inOrderTraversal(BinaryTree* root);

/// @brief Performs a pre-order traversal of the binary tree.
/// @param root The root node of the binary tree.
void preOrderTraversal(BinaryTree* root);

/// @brief Performs a post-order traversal of the binary tree.
/// @param root The root node of the binary tree.
void postOrderTraversal(BinaryTree* root);

/// @brief Performs a level-order traversal of the binary tree.
/// @param root The root node of the binary tree.
void levelOrderTraversal(BinaryTree* root);

/// @brief Inserts a value into the binary tree.
/// @param root The root node of the binary tree.
/// @param value The value to insert.
/// @return The root node of the binary tree after insertion.
BinaryTree* insert(BinaryTree* root, int value);

/// @brief Deletes a node with a given value from the binary tree.
/// @param root The root node of the binary tree.
/// @param value The value of the node to delete.
/// @return The root node of the binary tree after deletion.
BinaryTree* deleteNode(BinaryTree* root, int value);

/// @brief Searches for a node with a given value in the binary tree.
/// @param root The root node of the binary tree.
/// @param value The value to search for.
/// @return A pointer to the node with the specified value, or NULL if not found.
BinaryTree* search(BinaryTree* root, int value);

/// @brief Finds the node with the minimum value in the binary tree.
/// @param root The root node of the binary tree.
/// @return A pointer to the node with the minimum value.
BinaryTree* findMin(BinaryTree* root);

/// @brief Finds the node with the maximum value in the binary tree.
/// @param root The root node of the binary tree.
/// @return A pointer to the node with the maximum value.
BinaryTree* findMax(BinaryTree* root);

/// @brief Frees the memory used by the binary tree.
/// @param root The root node of the binary tree.
void freeTree(BinaryTree* root);

#endif
