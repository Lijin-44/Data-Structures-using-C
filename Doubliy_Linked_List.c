#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Insert at beginning */
void insert_begin() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

/* Insert at end */
void insert_end() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Delete from beginning */
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted from beginning\n");
}

/* Delete from end */
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end\n");
}

/* Traversal from beginning */
void traverse_begin() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Traversal from end */
void traverse_end() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* Display from both sides */
void display_both() {
    traverse_begin();
    traverse_end();
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
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Traversal from beginning\n");
        printf("6. Traversal from end\n");
        printf("7. Display from both sides\n");
        printf("8. Count\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: traverse_begin(); break;
            case 6: traverse_end(); break;
            case 7: display_both(); break;
            case 8: count(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
