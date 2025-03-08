#include "binary_tree.h"

BinaryTree* create(int value) {
    BinaryTree* newNode = (BinaryTree*)malloc(sizeof(BinaryTree));

    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void inOrderTraversal(BinaryTree* root) {
    if (!root) return;

    inOrderTraversal(root->left);
    printf("%d ", root->value);
    inOrderTraversal(root->right);
}

void preOrderTraversal(BinaryTree* root) {
    if (!root) return;

    printf("%d ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(BinaryTree* root) {
    if (!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->value);
}

void levelOrderTraversal(BinaryTree* root) {
    if (!root) return;

    BinaryTree** queue = (BinaryTree**)malloc(sizeof(BinaryTree*) * 100);
    int front = 0, back = 0;

    queue[back++] = root;

    while (back - front > 0) {
        BinaryTree* curr = queue[front++];
        printf("%d ", curr->value);

        if (curr->left) queue[back++] = curr->left;
        if (curr->right) queue[back++] = curr->right;
    }

    free(queue);
}

BinaryTree* insert(BinaryTree* root, int value) {
    if (root == NULL) return create(value);

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

BinaryTree* search(BinaryTree* root, int value) {
    if (!root || root->value == value) return (BinaryTree*)root;
    return (value < root->value) ? search(root->left, value) : search(root->right, value);
}

BinaryTree* findMin(BinaryTree* root) {
    while (root && root->left) root = root->left;
    return root;
}

BinaryTree* findMax(BinaryTree* root) {
    while (root && root->right) root = root->right;
    return root;
}

BinaryTree* deleteNode(BinaryTree* root, int value) {
    if (!root) return NULL;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (!root->left) {
            BinaryTree* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            BinaryTree* temp = root->left;
            free(root);
            return temp;
        }
        BinaryTree* minNode = findMin(root->right);
        root->value = minNode->value;
        root->right = deleteNode(root->right, minNode->value);
    }

    return root;
}

void freeTree(BinaryTree* root) {
    if (!root) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
    root = NULL;
}
