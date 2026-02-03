#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

/* Create new node */
struct node* newNode(int x) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

/* Insertion (level order) */
void insert() {
    int x;
    printf("Enter element to insert: ");
    scanf("%d", &x);

    struct node *n = newNode(x);

    if (root == NULL) {
        root = n;
        return;
    }

    struct node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        struct node *temp = q[front++];

        if (temp->left == NULL) {
            temp->left = n;
            return;
        } else
            q[rear++] = temp->left;

        if (temp->right == NULL) {
            temp->right = n;
            return;
        } else
            q[rear++] = temp->right;
    }
}

/* Inorder traversal */
void inorder(struct node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

/* Preorder traversal */
void preorder(struct node *r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

/* Postorder traversal */
void postorder(struct node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

/* Find deepest node */
struct node* deepestNode() {
    struct node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    struct node *temp = NULL;

    while (front < rear) {
        temp = q[front++];
        if (temp->left) q[rear++] = temp->left;
        if (temp->right) q[rear++] = temp->right;
    }
    return temp;
}

/* Delete deepest node */
void deleteDeepest(struct node *dnode) {
    struct node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        struct node *temp = q[front++];

        if (temp->left) {
            if (temp->left == dnode) {
                free(temp->left);
                temp->left = NULL;
                return;
            }
            q[rear++] = temp->left;
        }

        if (temp->right) {
            if (temp->right == dnode) {
                free(temp->right);
                temp->right = NULL;
                return;
            }
            q[rear++] = temp->right;
        }
    }
}

/* Delete operation */
void deleteNode() {
    int key;
    printf("Enter element to delete: ");
    scanf("%d", &key);

    if (root == NULL) {
        printf("Tree empty\n");
        return;
    }

    struct node *q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    struct node *keyNode = NULL, *temp;

    while (front < rear) {
        temp = q[front++];
        if (temp->data == key)
            keyNode = temp;

        if (temp->left) q[rear++] = temp->left;
        if (temp->right) q[rear++] = temp->right;
    }

    if (keyNode) {
        struct node *dnode = deepestNode();
        keyNode->data = dnode->data;
        deleteDeepest(dnode);
        printf("Node deleted\n");
    } else {
        printf("Element not found\n");
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n--- Binary Tree ---\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: inorder(root); printf("\n"); break;
            case 3: preorder(root); printf("\n"); break;
            case 4: postorder(root); printf("\n"); break;
            case 5: deleteNode(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
