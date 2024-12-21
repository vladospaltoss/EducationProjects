#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

Node* createnewnode(int data) {
  Node* newnode = (Node*) malloc(sizeof(Node));
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

void addtohead(Node** head, Node** tail, int data) {
  Node* newnode = createnewnode(data); 
  newnode->next = *head;
  if (*head != NULL) {
    (*head)->prev = newnode;      
  }
  if (*tail == NULL) {
    *tail = newnode; 
  }
  *head = newnode;
}

void addtotail(Node** head, Node** tail, int data) {
  Node* newnode = createnewnode(data); 
  newnode->prev = *tail;
  if (*tail != NULL) {
    (*tail)->next = newnode;      
  }
  if (*head == NULL) {
    *head = newnode; 
  }
  *tail = newnode;
}

void printlist(Node* head, Node* tail) {
  while (head != NULL) {
    printf("data is: %d\n", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void printreversedlist(Node* head, Node* tail) {
  while (head != NULL) {
    tail = head;
    head = head->next;
  } 
  while (tail != NULL) {
    printf("data is: %d\n", tail->data); 
    tail = tail->prev;
  }
  printf("NULL\n");
}

int lenoflist(Node* head) {
  int i;
  while (head != NULL) {
    head = head->next;
    i++;
  }
  return i;
}

int delfirst(Node** head) {
  if (*head == NULL) {
    printf("list is empty");
  } 
  Node* buf = *head;
  int deldata = buf->data;
  *head = (*head)->next;
  (*head)->prev = NULL;
  free(buf);
  return deldata;
}

int dellast(Node* tail) {
  if (tail == NULL) {
    return 0;
  }
  if (tail->next == NULL) {
    int deldata = tail->data;
    free(tail);
    return deldata;
  } 
  while (tail->next->next != NULL) {
    tail = tail->next;
  }
  Node* buf = tail->next;
  int deldata = buf->data;
  tail->next = NULL;
  free(buf);
  return deldata;
}

void makeroundlist(Node** head, Node** tail) {
  while ((*tail)!= NULL) {
    (*tail) = (*tail)->next; 
  } 
  (*tail)->next = *head;
  (*head)->prev = *tail;
}

void islistrounded(Node* head) {
  for (int i = 0; i < lenoflist(head) + 1; i++) {
    head = head->next;
    if (head == NULL) {
      printf("List is not rounded\n"); 
      break;
    }
  } 
  printf("List is rounded\n");
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;
  addtohead(&head, &tail, 30);
  addtohead(&head, &tail, 40);
  addtohead(&head, &tail, 50);
  addtotail(&head, &tail, 20);
  addtotail(&head, &tail, 10);
  addtotail(&head, &tail, 10);
  addtotail(&head, &tail, 10);
  printlist(head, tail);
  islistrounded(head);
  makeroundlist(&head, &tail);
  islistrounded(head);
  free(head);
  free(tail);
}
