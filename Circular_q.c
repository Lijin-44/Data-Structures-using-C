#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

/* Insert */
void insert() {
    int x;
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = x;
}

/* Delete */
void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

/* Display */
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

/* Count */
void count() {
    int c = 0, i;
    if (front == -1) {
        printf("Count = 0\n");
        return;
    }

    i = front;
    while (1) {
        c++;
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("Count = %d\n", c);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
