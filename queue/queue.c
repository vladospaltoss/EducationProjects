#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue* next;
} queue;

void enqueue(queue** top, int data) {
    queue* newitem = (queue*)malloc(sizeof(queue));
    newitem->data = data;
    newitem->next = *top;
    *top = newitem;
}

int dequeue(queue** top) {
    if (*top == NULL) {
        printf("Queue is empty\n");
        return 0; // Или другое значение, обозначающее пустую очередь
    }

    queue* current = *top;
    if (current->next == NULL) { // Единственный элемент в очереди
        int deldata = current->data;
        free(current);
        *top = NULL;
        return deldata;
    }

    // Найти предпоследний элемент
    while (current->next->next != NULL) {
        current = current->next;
    }

    int deldata = current->next->data;
    free(current->next);
    current->next = NULL;
    return deldata;
}

void printqueue(queue* top) {
    while (top != NULL) {
        printf("%d, ", top->data);
        top = top->next;
    }    
    printf("NULL\n");
}

int main() {
    queue* top = NULL;
    enqueue(&top, 1);
    enqueue(&top, 3);
    enqueue(&top, 3);
    enqueue(&top, 4);
    enqueue(&top, 5);

    printqueue(top);

    while (top) {
        printf("Dequeue: %d\n", dequeue(&top));
    }

    printqueue(top);

    return 0;
}
