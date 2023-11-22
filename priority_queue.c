#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  int priority;
  struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void insert(int data, int priority) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->priority = priority;
  newNode->next = NULL;

  if (front == NULL) {
    front = newNode;
    rear = newNode;
  } else {
    if (priority > front->priority) {
      newNode->next = front;
      front = newNode;
    } else {
      Node *temp = front;
      while (temp->next != NULL && temp->next->priority >= priority) {
        temp = temp->next;
      }

      newNode->next = temp->next;
      temp->next = newNode;

      if (newNode->next == NULL) {
        rear = newNode;
      }
    }
  }
}

void delete() {
  if (front == NULL) {
    printf("Priority queue is empty\n");
    return;
  }

  Node *temp = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  printf("Deleted element: %d (Priority: %d)\n", temp->data, temp->priority);
  free(temp);
}

void display() {
  if (front == NULL) {
    printf("Priority queue is empty\n");
    return;
  }

  Node *temp = front;
  printf("Priority Queue: ");

  while (temp != NULL) {
    printf("%d (Priority: %d) ", temp->data, temp->priority);
    temp = temp->next;
  }

  printf("\n");
}

int checkPriority(int data) {
  if (front == NULL) {
    return -1;
  }

  Node *temp = front;
  while (temp != NULL) {
    if (temp->data == data) {
      return temp->priority;
    }

    temp = temp->next;
  }

  return -1;
}

int main() {
  int choice, data, priority;

  while (1) {
    printf("\nPriority Queue Operations:\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Display priority queue\n");
    printf("4. Check priority of an element\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);

      printf("Enter priority: ");
      scanf("%d", &priority);

      insert(data, priority);
      break;

    case 2:
      delete();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("Enter data to check its priority: ");
      scanf("%d", &data);

      priority = checkPriority(data);

      if (priority == -1) {
        printf("Element not found in the priority queue\n");
      } else {
        printf("Priority of %d is %d\n", data, priority);
      }

      break;

    case 5:
      exit(0);

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
