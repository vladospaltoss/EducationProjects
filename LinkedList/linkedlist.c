#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node * next;
} Node;

Node* createnewNode(int data) {
 Node* newnode = (Node*)malloc(sizeof(Node));
 newnode->data = data;
 newnode->next = NULL;
 return newnode;
}

void addtohead(Node** head, int data) {
  Node* newNode = createnewNode(data);
  newNode->next = *head;
  *head = newNode;
}

void addtoend(Node* head, int data) {
  while (head->next != NULL) {
    head = head->next;
  }
  Node* newNode = createnewNode(data);
  head->next = newNode;
}

void printList(Node* head) {
  while (head != NULL) {
    printf("data of total is: %d\n", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int pop(Node** head) {
  if (*head == NULL) {
    printf("head is NULL");
    return 0;
  }
  Node* buf = *head;
  int pdata = buf->data;
  *head = buf->next;
  free(buf);  
  return pdata;
}

int del_last(Node* head) {
  int deldata;
  if (head->next == NULL) {
    deldata = head->data;
    free(head);
    return deldata;
  } 
  while (head->next->next != NULL) {
    head = head->next;
  }
  deldata = head->next->data;
  free(head->next);
  head->next = NULL;
  return deldata;
}

int del_of_value(Node* head, int value) {
  int deldata = 0;
  while (head != NULL) {
    if (head->next->data == value) {
     deldata = head->next->data;
     head->next = head->next->next;
     free(head->next);
    } 
    else {
      printf("value dosnt exist\n"); 
    }
    return deldata;
  }
}

void len(Node* head) {
  int i = 0;
  while (head != NULL) {
    head = head->next;
    i++;
  }  
  printf("len of the list is: %d\n", i);
}

int indexofval(Node* head, int value) {
 int i = 0;
 while (head->data != value) {
    head = head->next;
    i++;
 }
 printf("Index of value %d is: %d\n", value, i);
 return i;
}

int valueofindex(Node* head, int indx) {
 int i = 0; 
 while (i != indx) {
    head = head->next;
    i++;
 }
 printf("Value of index %d is: %d\n", indx, head->data);
 return head->data;
}

int main() {


  Node* head = createnewNode(10);
  addtohead(&head, 20);
  addtohead(&head, 30);
  addtohead(&head, 40);
  addtoend(head, 5);

  printList(head);
  valueofindex(head, 2);
  valueofindex(head, 0);
  valueofindex(head, 1);
  valueofindex(head, 3);
  valueofindex(head, 4);
  free(head);
  



}

