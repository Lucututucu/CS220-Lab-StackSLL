/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Stack ADT implemented using linked list
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"
#include "listAsLinkedList.h"

void stackPush(StackAsLinkedList* stack, double element) {
    insertElementLinkedList(stack, 0, element);
}

double stackPop(StackAsLinkedList* stack) {
    int popElement = getElementLinkedList(stack, 0);
    deleteElementLinkedList(stack, 0);
    return popElement;
}

bool stackIsEmpty(StackAsLinkedList* stack) {
    if (lengthOfLinkedList(stack) == 0) {
        return true;
    }
    return false;
}

bool stackIsFull(StackAsLinkedList* stack) {
    return false;
}

StackAsLinkedList* stackInit() {
    return createLinkedList();
}

void deleteStack(StackAsLinkedList* stack) {
    deleteLinkedList(stack);
}

double stackPeek(StackAsLinkedList* stack) {
    getElementLinkedList(stack, 0);
}

int stackSize(StackAsLinkedList* stack) {
    return lengthOfLinkedList(stack);
}

void stackPrint(StackAsLinkedList* stack) {
    printLinkedList(stack);
}
