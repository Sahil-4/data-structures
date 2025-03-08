#include <stdio.h>
#include <assert.h>
#include "binary_tree.h"

void test() {
    // Create root node
    BinaryTree* root = create(4); // root
    assert(root->value == 4);

    // Insert nodes to form a proper BST
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    // Traversal tests
    printf("In-order Traversal (Expected: 1 2 3 4 5 6 7):\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal (Expected: 4 2 1 3 6 5 7):\n");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal (Expected: 1 3 2 5 7 6 4):\n");
    postOrderTraversal(root);
    printf("\n");

    printf("Level-order Traversal (Expected: 4 2 6 1 3 5 7):\n");
    levelOrderTraversal(root);
    printf("\n");

    // Search tests
    assert(search(root, 5) != NULL);
    assert(search(root, 10) == NULL);

    // Min/Max tests
    assert(findMin(root)->value == 1);
    assert(findMax(root)->value == 7);

    // Deletion tests
    root = deleteNode(root, 7); // Remove leaf node
    printf("After deleting 7 (Expected: 4 2 6 1 3 5):\n");
    levelOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 4); // Remove root
    printf("After deleting 4 (Expected: 5 2 6 1 3):\n");
    levelOrderTraversal(root);
    printf("\n");

    // Edge cases: Insert into empty tree
    BinaryTree* newRoot = NULL;
    newRoot = insert(newRoot, 42);
    assert(newRoot != NULL && newRoot->value == 42);
    freeTree(newRoot);

    // Single-node tree deletion
    BinaryTree* singleNodeTree = create(100);
    singleNodeTree = deleteNode(singleNodeTree, 100);
    assert(singleNodeTree == NULL);

    // Delete non-existent node
    root = deleteNode(root, 999);
    printf("After attempting to delete non-existent node (Expected: 5 2 6 1 3):\n");
    levelOrderTraversal(root);
    printf("\n");

    // Empty tree search
    BinaryTree* emptyTree = NULL;
    assert(search(emptyTree, 10) == NULL);

    // Min/max in single-node tree
    BinaryTree* oneNode = create(500);
    assert(findMin(oneNode)->value == 500);
    assert(findMax(oneNode)->value == 500);
    freeTree(oneNode);

    // cleanup
    freeTree(root);
    printf("All tests passed!\n");
}

int main() {
    // Test binary tree implementation
    test();

    return 0;
}