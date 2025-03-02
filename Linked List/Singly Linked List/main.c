#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

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
    assert(list->tail->data == 2);

    // Add nodes at the tail
    addNodeAtTail(list, 3);
    addNodeAtTail(list, 4);
    addNodeAtTail(list, 5);
    assert(list->tail->data == 5);

    // Insert node at specific position
    insertNodeAt(list, 0, 0);
    assert(getNodeAt(list, 0) != NULL && getNodeAt(list, 0)->data == 0);
    insertNodeAt(list, 1, -100);
    assert(getNodeAt(list, 1) != NULL && getNodeAt(list, 1)->data == -100);
    insertNodeAt(list, 50, 50);
    assert(getNodeAt(list, 50) == NULL);

    // Search for a node
    assert(searchNode(list, 100) == NULL);
    Node* found = searchNode(list, -100);
    assert(found != NULL && found->data == -100);

    // Delete a node by value
    assert(deleteNode(list, 1000) == -1);
    assert(deleteNode(list, -100) == 0);
    assert(searchNode(list, -100) == NULL);

    // Delete a node by index
    assert(deleteNodeAt(list, 0) == 0);
    assert(deleteNodeAt(list, 5) == -1);
    assert(deleteNodeAt(list, 4) == 0);
    assert(list->head->data == 1);
    assert(list->tail->data == 4);

    // Remove head and tail
    removeHead(list);
    removeTail(list);
    assert(list->head->data == 2);
    assert(list->tail->data == 3);

    // Add more nodes
    addNode(list, 11);
    addNode(list, 12);
    addNode(list, 11);
    addNode(list, 13);
    addNode(list, 12);
    assert(getNodeAt(list, 0) != NULL && getNodeAt(list, 0)->data == 2);
    assert(getNodeAt(list, 1) != NULL && getNodeAt(list, 1)->data == 3);
    assert(getNodeAt(list, 2) != NULL && getNodeAt(list, 2)->data == 11);
    assert(getNodeAt(list, 3) != NULL && getNodeAt(list, 3)->data == 12);
    assert(getNodeAt(list, 4) != NULL && getNodeAt(list, 4)->data == 11);
    assert(getNodeAt(list, 5) != NULL && getNodeAt(list, 5)->data == 13);
    assert(getNodeAt(list, 6) != NULL && getNodeAt(list, 6)->data == 12);

    // Remove duplicates
    removeDuplicates(list);
    assert(getNodeAt(list, 0) != NULL && getNodeAt(list, 0)->data == 2);
    assert(getNodeAt(list, 1) != NULL && getNodeAt(list, 1)->data == 3);
    assert(getNodeAt(list, 2) != NULL && getNodeAt(list, 2)->data == 11);
    assert(getNodeAt(list, 3) != NULL && getNodeAt(list, 3)->data == 12);
    assert(getNodeAt(list, 4) != NULL && getNodeAt(list, 4)->data == 13);

    // Reverse the list
    reverseList(list);
    assert(getNodeAt(list, 0) != NULL && getNodeAt(list, 0)->data == 13);
    assert(getNodeAt(list, 1) != NULL && getNodeAt(list, 1)->data == 12);
    assert(getNodeAt(list, 2) != NULL && getNodeAt(list, 2)->data == 11);
    assert(getNodeAt(list, 3) != NULL && getNodeAt(list, 3)->data == 3);
    assert(getNodeAt(list, 4) != NULL && getNodeAt(list, 4)->data == 2);

    // Find the middle node
    assert(findMiddle(list) != NULL && findMiddle(list)->data == 11);
    removeHead(list);
    assert(findMiddle(list) != NULL && findMiddle(list)->data == 3);

    // Create another list and merge
    List* list2 = create();
    addNode(list2, 100);
    addNode(list2, 101);
    addNode(list2, 102);
    List* merged_list = mergeLists(list, list2);
    assert(searchNode(merged_list, 2)->next != NULL && searchNode(merged_list, 2)->next->data == 100);

    // Detect loop
    assert(detectLoop(list) == 0);

    // Clean up
    memory_release(&list);
    assert(list == NULL);

    printf("All tests passed.\n");
}

int main() {
    // Singly Linked List test
    test();

    return 0;
}
