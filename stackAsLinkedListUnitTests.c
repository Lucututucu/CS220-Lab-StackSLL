/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Stack ADT implemented using linked list
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */

#include <stdio.h>
#include "stackAsLinkedList.h"

int main() {

    LinkedList *myStack = stackInit();

    for (int i = 0; i < 10; ++i) {
        stackPush(myStack, ((i + 37) * 73) % 100);
    }
    stackPrint(myStack);
    printf("Length %d", stackSize(myStack));
    
    printf("Stack is ");
    if (!stackIsEmpty(myStack)) {
        printf("not ");
    }
    printf("empty.\n");

    printf("Peek is %lf", stackPeek(myStack));
    printf("Pop is %lf", stackPop(myStack));
    printf("Pop is %lf", stackPop(myStack));
    printf("Pop is %lf", stackPop(myStack));
    printf("Pop is %lf", stackPop(myStack));
    printf("Pop is %lf", stackPop(myStack));

    stackPrint(myStack);
    printf("Length %d", stackSize(myStack));
    
    printf("Stack is ");
    if (!stackIsEmpty(myStack)) {
        printf("not ");
    }
    printf("empty.\n");


    // Insert Your Test Functions Here
    return 0;
    
}