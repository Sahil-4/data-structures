#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List* create() {
    List* list = (List*)malloc(sizeof(List));

    if (list == NULL) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void memory_release(List** list) {
    if (list == NULL || *list == NULL) return;

    Node* current = (*list)->head;
    Node* next;

    while (current != NULL) {
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
    newNode->next = list->head;
    list->head = newNode;

    if (list->tail == NULL) {
        list->tail = newNode;
    }
    list->size++;

    return newNode;
}

Node* addNodeAtTail(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    }

    list->tail = newNode;

    if (list->head == NULL) {
        list->head = newNode;
    }

    list->size++;

    return newNode;
}

Node* addNode(List* list, int value) {
    if (list == NULL) return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    }
    else {
        list->head = newNode;
    }

    list->tail = newNode;
    list->size++;

    return newNode;
}

Node* insertNodeAt(List* list, int index, int value) {
    if (index < 0 || index > list->size) return NULL;
    if (index == 0) return addNodeAtHead(list, value);
    if (index == list->size) return addNodeAtTail(list, value);

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) return NULL;

    newNode->data = value;
    newNode->next = current->next;

    current->next = newNode;

    list->size++;

    return newNode;
}

int deleteNode(List* list, int value) {
    if (list->head == NULL) return -1;
    if (list->head->data == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return 0;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) return -1;

    Node* temp = current->next;
    current->next = current->next->next;
    if (temp == list->tail) {
        list->tail = current;
    }
    free(temp);

    list->size--;

    return 0;
}

int deleteNodeAt(List* list, int index) {
    if (index < 0 || index >= list->size) return -1;
    if (index == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return 0;
    }

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    if (temp == list->tail) {
        list->tail = current;
    }
    free(temp);

    list->size--;

    return 0;
}

void removeHead(List* list) {
    if (list->head == NULL) return;

    Node* temp = list->head;
    list->head = list->head->next;

    free(temp);

    list->size--;
}

void removeTail(List* list) {
    if (list->head == NULL) return;
    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    Node* current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }
    free(list->tail);

    current->next = NULL;
    list->tail = current;

    list->size--;
}

Node* searchNode(List* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getSize(List* list) {
    return list->size;
}

int isEmpty(List* list) {
    return list->size == 0;
}

void reverseList(List* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    list->tail = list->head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

Node* getNodeAt(List* list, int index) {
    if (index < 0 || index >= list->size) return NULL;

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current;
}

void removeDuplicates(List* list) {
    if (list->head == NULL) return;

    Node* current = list->head;
    while (current != NULL && current->next != NULL) {
        Node* runner = current;

        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;

                if (temp == list->tail) {
                    list->tail = runner;
                }
                free(temp);
                list->size--;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

Node* findMiddle(List* list) {
    if (list->head == NULL) return NULL;

    Node* slow = list->head;
    Node* fast = list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

List* mergeLists(List* list1, List* list2) {
    List* mergedList = create();
    Node* current1 = list1->head;
    Node* current2 = list2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data <= current2->data) {
            addNodeAtTail(mergedList, current1->data);
            current1 = current1->next;
        }
        else {
            addNodeAtTail(mergedList, current2->data);
            current2 = current2->next;
        }
    }
    while (current1 != NULL) {
        addNodeAtTail(mergedList, current1->data);
        current1 = current1->next;
    }
    while (current2 != NULL) {
        addNodeAtTail(mergedList, current2->data);
        current2 = current2->next;
    }

    return mergedList;
}

int detectLoop(List* list) {
    if (list->head == NULL) return 0;

    Node* slow = list->head;
    Node* fast = list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }

    return 0;
}
