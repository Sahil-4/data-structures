#include <stdio.h>
#include <assert.h>
#include "avl_tree.h"

void test() {
    // Create root node
    AVLTree* root = NULL;

    // Test inserting nodes
    root = insertAVLNode(root, 10);
    root = insertAVLNode(root, 20);
    root = insertAVLNode(root, 30);
    root = insertAVLNode(root, 40);
    root = insertAVLNode(root, 50);
    root = insertAVLNode(root, 25);

    // After insertion, tree structure should be balanced
    // Expected structure:
    //         30
    //       /    \
    //     20      40
    //    /  \           \
    //  10   25     50

    printf("Tree structure after insertion:\n");
    printTreeStructure(root, 0);

    // Test searching for nodes
    assert(searchAVLNode(root, 10) == 1); // Node 10 should be found
    assert(searchAVLNode(root, 25) == 1); // Node 25 should be found
    assert(searchAVLNode(root, 50) == 1); // Node 50 should be found
    assert(searchAVLNode(root, 60) == 0); // Node 60 should not be found

    // Test in-order traversal (should be sorted)
    printf("In-order traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    // Test deleting nodes
    root = deleteAVLNode(root, 10);  // Delete leaf node
    root = deleteAVLNode(root, 40);  // Delete node with one child
    root = deleteAVLNode(root, 30);  // Delete root node

    // After deletion, tree structure should still be balanced
    // Expected structure:
    //         25
    //       /    \
    //     20      50

    printf("Tree structure after deletion:\n");
    printTreeStructure(root, 0);

    // Test if the tree is empty
    assert(isEmpty(root) == 0); // Tree should not be empty

    // Test deleting all nodes
    root = deleteAVLNode(root, 20);
    root = deleteAVLNode(root, 25);
    root = deleteAVLNode(root, 50);

    assert(isEmpty(root));

    // Clean up memory
    memory_release(root);

    printf("All tests passed!\n");
}

int main() {
    // Test AVL Tree implementation
    test();

    return 0;
}
