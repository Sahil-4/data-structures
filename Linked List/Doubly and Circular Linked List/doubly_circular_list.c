#include <stdio.h>
#include <stdlib.h>
#include "doubly_circular_list.h"

List* create() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void memory_release(List** list) {
    if (list == NULL || *list == NULL) return;

    Node* current = (*list)->head;
    Node* next;

    for (int i = 0; i < (*list)->size; i++) {
        next = current->next;
        free(current);
        current = next;
    }

    free(*list);
    *list = NULL;
}

Node* addNodeAtHead(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;

    if (list->size == 0) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    }
    else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        list->head->prev = newNode;
        tail->next = newNode;
        list->head = newNode;
    }

    list->size++;
    return newNode;
}

Node* addNodeAtTail(List* list, int value) {
    if (list->size == 0) {
        return addNodeAtHead(list, value);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;

    Node* tail = list->head->prev;
    newNode->next = list->head;
    newNode->prev = tail;
    tail->next = newNode;
    list->head->prev = newNode;

    list->size++;
    return newNode;
}

Node* insertNodeAt(List* list, int index, int value) {
    if (index < 0 || index > list->size) return NULL;
    if (index == 0) return addNodeAtHead(list, value);
    if (index == list->size) return addNodeAtTail(list, value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    list->size++;
    return newNode;
}

int deleteNode(List* list, int value) {
    if (list->size == 0) return -1;

    Node* current = list->head;
    for (int i = 0; i < list->size; i++) {
        if (current->data == value) {
            if (list->size == 1) {
                list->head = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == list->head) {
                    list->head = current->next;
                }
            }

            free(current);
            list->size--;
            return 0;
        }
        current = current->next;
    }

    return -1;
}

int deleteNodeAt(List* list, int index) {
    if (index < 0 || index >= list->size) return -1;

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (list->size == 1) {
        list->head = NULL;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == list->head) {
            list->head = current->next;
        }
    }

    free(current);
    list->size--;
    return 0;
}

Node* searchNode(List* list, int value) {
    Node* current = list->head;
    for (int i = 0; i < list->size; i++) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayList(List* list) {
    Node* current = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("(head)\n");
}

int getSize(List* list) {
    return list->size;
}

int isEmpty(List* list) {
    return list->size == 0;
}
