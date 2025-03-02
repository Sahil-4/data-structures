#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/// @brief Singly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/// @brief Linked List data structure
typedef struct {
    Node* head;
    Node* tail;
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

/// @brief adds a new node at the end of given List list
/// @param list pointer to the list in which new node will be added at the end
/// @param value node data
/// @return new node that is added 
Node* addNode(List* list, int value);

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

/// @brief Remove the head node of the list 
/// @param list pointer to the list 
void removeHead(List* list);

/// @brief Remove the tail node of the list 
/// @param list pointer to the list 
void removeTail(List* list);

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

/// @brief reverses the linked list
/// @param list pointer to the list
void reverseList(List* list);

/// @brief retrieves the nth node in the list
/// @param list pointer to the list
/// @param index zero-based index of the node to retrieve
/// @return pointer to the nth node, or NULL if index is out of bounds
Node* getNodeAt(List* list, int index);

/// @brief removes duplicate nodes from the list
/// @param list pointer to the list
void removeDuplicates(List* list);

/// @brief finds the middle node of the list
/// @param list pointer to the list
/// @return pointer to the middle node, or NULL if the list is empty
Node* findMiddle(List* list);

/// @brief merges two linked lists
/// @param list1 pointer to the first list
/// @param list2 pointer to the second list
/// @return pointer to the merged list
List* mergeLists(List* list1, List* list2);

/// @brief Detect if there is a loop in the list 
/// @param list pointer to the list
/// @return 1 if a loop is detected, 0 otherwise 
int detectLoop(List* list);

#endif
