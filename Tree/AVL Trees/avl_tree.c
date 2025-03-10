#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

// Utility function to get the height of the tree
int height(AVLTree* node) {
    if (!node) return 0;
    return node->height;
}

// Utility function to create a new AVL tree node
AVLTree* createAVLNode(int val) {
    AVLTree* node = (AVLTree*)malloc(sizeof(AVLTree));
    if (!node) return NULL;

    node->val = val;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially at leaf level

    return node;
}

// Utility function to get the balance factor of a node
int getBalance(AVLTree* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

// Right rotation
AVLTree* rightRotate(AVLTree* y) {
    AVLTree* x = y->left;
    AVLTree* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    // Return new root
    return x;
}

// Left rotation
AVLTree* leftRotate(AVLTree* x) {
    AVLTree* y = x->right;
    AVLTree* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    // Return new root
    return y;
}

// Recursive function to insert a node in the AVL tree
AVLTree* insertAVLNode(AVLTree* root, int val) {
    if (!root) return createAVLNode(val);

    // Equal values are not allowed in AVL Tree
    if (val == root->val) return root;

    if (val < root->val) root->left = insertAVLNode(root->left, val);
    else root->right = insertAVLNode(root->right, val);

    // Update height of this ancestor node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && val < root->left->val) return rightRotate(root);

    // Right Right Case
    if (balance < -1 && val > root->right->val) return leftRotate(root);

    // Left Right Case
    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Utility function to find the node with the minimum value in an AVL tree
AVLTree* findMinNode(AVLTree* node) {
    AVLTree* current = node;
    while (current->left) current = current->left;
    return current;
}

// Recursive function to delete a node in the AVL tree
AVLTree* deleteAVLNode(AVLTree* root, int val) {
    if (!root) return root;

    if (val < root->val) {
        root->left = deleteAVLNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = deleteAVLNode(root->right, val);
    }
    else {
        // Node with only one child or no child
        if ((!root->left) || (!root->right)) {
            AVLTree* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            AVLTree* temp = findMinNode(root->right);

            root->val = temp->val;

            root->right = deleteAVLNode(root->right, temp->val);
        }
    }

    if (!root) return root;

    // Update height
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a value in the AVL tree
int searchAVLNode(AVLTree* root, int val) {
    if (!root) return 0;

    if (root->val == val) return 1;
    else if (val < root->val) return searchAVLNode(root->left, val);
    else return searchAVLNode(root->right, val);
}

// Function to check if the AVL tree is empty
int isEmpty(AVLTree* root) {
    return root == NULL;
}

// In-order traversal of the AVL tree
void inOrderTraversal(AVLTree* root) {
    if (!root) return;

    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

// Function to print the AVL tree structure
void printTreeStructure(AVLTree* root, int level) {
    if (!root) return;

    printTreeStructure(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->val);
    printTreeStructure(root->left, level + 1);
}

// Function to release memory used by the AVL tree
void memory_release(AVLTree* root) {
    if (!root) return;

    memory_release(root->left);
    memory_release(root->right);
    free(root);
}
