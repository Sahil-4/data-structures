#include <stdio.h>
#include <assert.h>
#include "binary_search_tree.h"

void test() {
    // Create root node
    BinarySearchTree* root = create(10);
    assert(root->val == 10);

    // Insert nodes
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 18);

    printf("In-order Traversal (Expected output: 3 5 7 10 12 15 18):\n");
    inOrderTraverse(root);
    printf("\n");

    printf("Pre-order Traversal (Expected output: 10 5 3 7 15 12 18):\n");
    preOrderTraverse(root);
    printf("\n");

    printf("Post-order Traversal (Expected output: 3 7 5 12 18 15 10):\n");
    postOrderTraverse(root);
    printf("\n");

    // Test search
    BinarySearchTree* searchResult = searchNode(root, 7);
    assert(searchResult != NULL && searchResult->val == 7);

    searchResult = searchNode(root, 20);
    assert(searchResult == NULL);

    // Test counting nodes
    int nodeCount = countNodes(root);
    assert(nodeCount == 7);

    // Test deleteNode
    root = deleteNode(root, 15);
    printf("In-order Traversal after deleting 15 (Expected output: 3 5 7 10 12 18):\n");
    inOrderTraverse(root);
    printf("\n");

    root = deleteNode(root, 10);
    printf("In-order Traversal after deleting 10 (Expected output: 3 5 7 12 18):\n");
    inOrderTraverse(root);
    printf("\n");

    // Test converting to a balanced BST
    root = convertToBalancedBST(root);
    printf("In-order Traversal after balancing (Expected output: 3 5 7 12 18):\n");
    inOrderTraverse(root);
    printf("\n");

    // Free memory
    memory_release(root);

    printf("All tests passed!\n");
}

int main() {
    // Test binary search tree implementation 

    test();

    return 0;
}
