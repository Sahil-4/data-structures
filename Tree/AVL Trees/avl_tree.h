#ifndef AVL_TREE_H
#define AVL_TREE_H

// AVL Tree Structure 
typedef struct AVLTree {
    int val;
    int height;
    struct AVLTree* left;
    struct AVLTree* right;
} AVLTree;

/// @brief Creates a new AVL tree node.
/// @param val The value to store in the new node.
/// @return A pointer to the newly created AVL tree node.
AVLTree* createAVLNode(int val);

/// @brief Inserts a value into the AVL tree.
/// @param root The root node of the AVL tree.
/// @param val The value to insert.
/// @return The root node of the AVL tree after insertion.
AVLTree* insertAVLNode(AVLTree* root, int val);

/// @brief Deletes a node with a given value from the AVL tree.
/// @param root The root node of the AVL tree.
/// @param val The value of the node to delete.
/// @return The root node of the AVL tree after deletion.
AVLTree* deleteAVLNode(AVLTree* root, int val);

/// @brief Searches for a value in the AVL tree.
/// @param root The root node of the AVL tree.
/// @param val The value to search for.
/// @return 1 if the value is found, 0 otherwise.
int searchAVLNode(AVLTree* root, int val);

/// @brief Checks if the AVL tree is empty.
/// @param root The root node of the AVL tree.
/// @return 1 if the tree is empty, 0 otherwise.
int isEmpty(AVLTree* root);

/// @brief Performs an in-order traversal of the AVL tree.
/// @param root The root node of the AVL tree.
void inOrderTraversal(AVLTree* root);

/// @brief Prints the AVL tree structure.
/// @param root The root node of the AVL tree.
/// @param level The current level of the tree (use 0 for the root).
void printTreeStructure(AVLTree* root, int level);

/// @brief Releases the memory used by the AVL tree.
/// @param root The root node of the AVL tree.
void memory_release(AVLTree* root);

#endif
