#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push operation */
void push() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Pushed successfully\n");
}

/* Pop operation */
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
    printf("Popped successfully\n");
}

/* Traversal */
void traverse() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Count */
void count() {
    struct node *temp = top;
    int c = 0;

    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Number of elements = %d\n", c);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: count(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
