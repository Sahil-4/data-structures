#include "binary_search_tree.h"

BinarySearchTree* create(int val) {
    BinarySearchTree* bst = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));

    bst->val = val;
    bst->left = bst->right = NULL;

    return bst;
}

void preOrderTraverse(BinarySearchTree* root) {
    if (!root) return;

    printf("%d\n", root->val);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(BinarySearchTree* root) {
    if (!root) return;

    inOrderTraverse(root->left);
    printf("%d\n", root->val);
    inOrderTraverse(root->right);
}

void postOrderTraverse(BinarySearchTree* root) {
    if (!root) return;

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    printf("%d\n", root->val);
}

int countNodes(BinarySearchTree* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

BinarySearchTree* searchNode(BinarySearchTree* root, int val) {
    if (!root) return NULL;

    if (root->val == val) return root;

    if (root->val > val) {
        return searchNode(root->left, val);
    }

    return searchNode(root->right, val);
}

BinarySearchTree* predecessor(BinarySearchTree* root, int val) {
    BinarySearchTree* pred = NULL;
    BinarySearchTree* curr = root;

    while (curr) {
        if (curr->val < val) {
            pred = curr;
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }

    return pred;
}

BinarySearchTree* successor(BinarySearchTree* root, int val) {
    BinarySearchTree* suc = NULL;
    BinarySearchTree* curr = root;

    while (curr) {
        if (curr->val > val) {
            suc = curr;
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    return suc;
}

BinarySearchTree* insertNode(BinarySearchTree* root, int val) {
    if (!root) return create(val);

    if (val <= root->val) {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

BinarySearchTree* __deleteNodeHelper(BinarySearchTree* root) {
    if (!root->left) return root->right;
    if (!root->right) return root->left;

    BinarySearchTree* lastRight = root->left;
    while (lastRight->right) lastRight = lastRight->right;

    lastRight->right = root->right;

    return root->left;
}

BinarySearchTree* deleteNode(BinarySearchTree* root, int val) {
    if (!root) return NULL;

    if (root->val == val) {
        return __deleteNodeHelper(root);
    }

    BinarySearchTree* r = root;
    while (root) {
        if (root->val > val) {
            if (root->left && root->left->val == val) {
                root->left = __deleteNodeHelper(root->left);
            }
            else {
                root = root->left;
            }
        }
        else {
            if (root->right && root->right->val == val) {
                root->right = __deleteNodeHelper(root->right);
            }
            else {
                root = root->right;
            }
        }
    }

    return r;
}

void storeInorderNodes(BinarySearchTree* root, BinarySearchTree** nodes, int* index) {
    if (!root) return;

    storeInorderNodes(root->left, nodes, index);
    nodes[*index] = root;
    (*index)++;
    storeInorderNodes(root->right, nodes, index);
}

BinarySearchTree* constructBST(BinarySearchTree** nodes, int low, int high) {
    if (low > high) return NULL;

    int mid = low + (high - low) / 2;

    BinarySearchTree* root = nodes[mid];

    root->left = constructBST(nodes, low, mid - 1);
    root->right = constructBST(nodes, mid + 1, high);

    return root;
}

BinarySearchTree* convertToBalancedBST(BinarySearchTree* root) {
    int nodeCount = countNodes(root);

    BinarySearchTree** nodes = (BinarySearchTree**)malloc(nodeCount * sizeof(BinarySearchTree*));
    int index = 0;
    storeInorderNodes(root, nodes, &index);

    root = constructBST(nodes, 0, nodeCount - 1);

    free(nodes);

    return root;
}

void memory_release(BinarySearchTree* root) {
    if (!root) return;

    memory_release(root->left);
    memory_release(root->right);
    free(root);
}
