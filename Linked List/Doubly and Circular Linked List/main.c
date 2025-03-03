#include <stdio.h>
#include <assert.h>
#include "doubly_circular_list.h"

void test() {
    // Create a new list
    List* list = create();
    assert(list != NULL);
    assert(isEmpty(list) == 1);
    assert(getSize(list) == 0);

    // Add nodes at the head
    addNodeAtHead(list, 2);
    addNodeAtHead(list, 1);
    assert(list->head->data == 1);
    assert(list->head->next->data == 2);

    // Add nodes at the tail
    addNodeAtTail(list, 3);
    addNodeAtTail(list, 4);
    assert(list->head->prev->data == 4);

    // Insert node at specific position
    insertNodeAt(list, 0, 0);
    assert(list->head->data == 0);
    insertNodeAt(list, 2, 10);
    assert(list->head->next->next->data == 10);

    // Search for a node
    assert(searchNode(list, 100) == NULL);
    Node* found = searchNode(list, 10);
    assert(found != NULL && found->data == 10);

    // Delete a node by value
    assert(deleteNode(list, 1000) == -1);
    assert(deleteNode(list, 10) == 0);

    // Delete a node by index
    assert(deleteNodeAt(list, 100) == -1);
    assert(deleteNodeAt(list, 2) == 0);

    // Display the list
    displayList(list);

    // Clean up
    memory_release(&list);
    assert(list == NULL);

    printf("All tests passed!\n");
}

int main() {
    // Test doubly circular linked list 
    test();

    return 0;
}
