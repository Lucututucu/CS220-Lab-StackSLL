/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * ===========================================================
 */

// Use your solution from previous labs

#include "listAsLinkedList.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*) malloc (sizeof(LinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->numberOfElements = 0;
    return newList;
}

void deleteLinkedList(LinkedList* list) {
    Node *current = list->head;
    Node *temp = list->head;
    for (int i = 0; i < list->numberOfElements; ++i) {
        current = current->next;
        free(temp);
        temp = current;
    }
    free(list);
}

void appendElementLinkedList(LinkedList* list, double element) {
    Node* new = (Node*) malloc(sizeof(Node));

    new->data = element;
    new->next = NULL;

    if (list->numberOfElements == 0) {
        list->head = new;
    } else {
        list->tail->next = new;
    }
    list->tail = new;
    list->numberOfElements++;
    return;
}


int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}


void printLinkedList(LinkedList* list) {
    Node *current = list->head;
    for (int i = 0; i < list->numberOfElements; ++i) {
        printf("%lf ", current->data);
        current = current->next;
    }
    printf("\n");
}


double getElementLinkedList(LinkedList* list, int position) {
    if (position >= list->numberOfElements) {
        printf("Out of range\n");
        return -1;
    }
    Node *current = list->head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->data;
}


void deleteElementLinkedList(LinkedList* list, int position) {
    int size = list->numberOfElements;
    if (size == 0) {
        return;
    } else if (size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->numberOfElements--;
        return;
    } else if (position == 0) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->numberOfElements--;
        return;
    } else if (size - 1 <= position) {
        Node* current = list->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        current->next = NULL;
        free(list->tail);
        list->tail = current;
        list->numberOfElements--;
        return;
    } else {
        Node* current = list->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        list->numberOfElements--;
        return;
    }
}


void insertElementLinkedList(LinkedList* list, int position, double element) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = element;

    if (list->numberOfElements == 0) {
        new->next = list->head;
        list->head = new;
        list->tail = new;
        list->numberOfElements++;
        return;
    }
    if (position == 0) {
        new->next = list->head;
        list->head = new;
        list->numberOfElements++;
        return;
    } else if (position >= list->numberOfElements) {
        appendElementLinkedList(list, element);
        return;
    } else {
        Node *current = list->head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
        list->numberOfElements++;
        return;
    }
}


void changeElementLinkedList(LinkedList* list, int position, double newElement) {
    Node *current = list->head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    current->data = newElement;
}


int findElementLinkedList(LinkedList* list, double element) {
    Node *current = list->head;
    int findIndex = 0;
    for (int i = 0; i < list->numberOfElements; ++i) {
        if (current->data == element) {
            return findIndex;
        } else {
            current = current->next;
            findIndex++;
        }
    }
    printf("Couldn't find\n");
    return -1;
}


void selSortLinkedList(LinkedList* list);


void insertSortLinkedList(LinkedList* list);

