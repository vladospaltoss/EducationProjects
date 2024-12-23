#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} stack;

void push(stack** top, int data) {
    stack* newitem = (stack*)malloc(sizeof(stack)); 
    newitem->data = data;
    newitem->next = *top;
    *top = newitem;
}

int pop(stack** top) {
    if (*top == NULL) {
        printf("stack is empty\n");
        return 0;
    }
    stack * buf = *top;
    int deldata = buf->data;
    *top = buf->next;
    free(buf);
    return  deldata;
}

void printstack(stack* top) {
    while (top != NULL) {
        printf("Stack = %d, ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    stack* top = NULL; 
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);

    printstack(top);
    while (top) {
        printf("deleted data is: %d\n", pop(&top)); 
    }
    return 0;
} 
