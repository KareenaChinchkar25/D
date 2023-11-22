#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int arr[], int n, int pos, int element) {
    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return;
    }

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = element;
    n++;
    printf("Element inserted successfully\n");
}

void deleteElement(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Element deleted successfully\n");
}

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n = 0, choice, pos, element;

    while (1) {
        printf("\n1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &pos);

                printf("Enter element to insert: ");
                scanf("%d", &element);

                insertElement(arr, n, pos, element);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                deleteElement(arr, n, pos);
                break;

            case 3:
                displayArray(arr, n);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
