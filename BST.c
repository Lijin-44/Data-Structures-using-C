#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

/* Create new node */
struct node* newNode(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

/* Insert */
struct node* insert(struct node *root, int x) {
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

/* Find / Search */
void find(struct node *root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }

    if (root->data == key) {
        printf("Element found\n");
        return;
    }

    if (key < root->data)
        find(root->left, key);
    else
        find(root->right, key);
}

/* Find minimum */
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* Delete */
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Inorder */
void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder */
void preorder(struct node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder */
void postorder(struct node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int ch, x;
    struct node *root = NULL;

    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Find\n");
        printf("3. Delete\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                printf("Enter element to find: ");
                scanf("%d", &x);
                find(root, x);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 4:
                inorder(root); printf("\n");
                break;
            case 5:
                preorder(root); printf("\n");
                break;
            case 6:
                postorder(root); printf("\n");
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
