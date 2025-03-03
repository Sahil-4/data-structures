#ifndef DOUBLY_CIRCULAR_LIST_H
#define DOUBLY_CIRCULAR_LIST_H

/// @brief Doubly Circular Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

/// @brief Linked List data structure
typedef struct {
    Node* head;
    int size;
} List;

/// @brief creates a new Linked List
/// @return new Linked List
List* create();

/// @brief frees all nodes in the list
/// @param list pointer to the list
void memory_release(List** list);

/// @brief adds a node at the head of the list
/// @param list pointer to the list
/// @param value node data
/// @return new node that is added at the head
Node* addNodeAtHead(List* list, int value);

/// @brief adds a node at the tail of the list
/// @param list pointer to the list
/// @param value node data
/// @return new node that is added at the tail
Node* addNodeAtTail(List* list, int value);

/// @brief inserts a node at a specific position in the list
/// @param list pointer to the list
/// @param index zero-based index where the node will be inserted
/// @param value node data
/// @return new node that is inserted at the specified position
Node* insertNodeAt(List* list, int index, int value);

/// @brief deletes a node from the list
/// @param list pointer to the list
/// @param value value of the node to be deleted
/// @return 0 if deletion is successful, -1 if node not found
int deleteNode(List* list, int value);

/// @brief deletes a node at a specific position in the list
/// @param list pointer to the list
/// @param index zero-based index of the node to be deleted
/// @return 0 if deletion is successful, -1 if index is out of bounds
int deleteNodeAt(List* list, int index);

/// @brief searches for a node in the list
/// @param list pointer to the list
/// @param value value of the node to search for
/// @return pointer to the node if found, NULL otherwise
Node* searchNode(List* list, int value);

/// @brief displays all nodes in the list
/// @param list pointer to the list
void displayList(List* list);

/// @brief gets the size of the list
/// @param list pointer to the list
/// @return the number of nodes in the list
int getSize(List* list);

/// @brief checks if the list is empty
/// @param list pointer to the list
/// @return 1 if the list is empty, 0 otherwise
int isEmpty(List* list);

#endif
