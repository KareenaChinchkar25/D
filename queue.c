#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int size;
    int *array;
};

void push(struct Queue *queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }

    queue->rear++;
    queue->array[queue->rear] = value;
}

int pop(struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = queue->array[queue->front];
    queue->front++;
    return value;
}

void display(struct Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }

    printf("\n");
}

int main() {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));

    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int *) malloc(size * sizeof(int));

    int choice;
    int value;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(queue, value);
                break;

            case 2:
                value = pop(queue);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                display(queue);
                break;

            case 4:
               exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(queue->array);
    free(queue);

    return 0;
}
