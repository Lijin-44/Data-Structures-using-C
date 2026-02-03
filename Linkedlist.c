#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at beginning */
void insert() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

/* Delete from beginning */
void delete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted successfully\n");
}

/* Traversal */
void traverse() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Count */
void count() {
    struct node *temp = head;
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
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: traverse(); break;
            case 4: count(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
