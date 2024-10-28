#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int findLargest(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root ? root->key : -1; // Return -1 if tree is empty
}

int findSmallest(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root ? root->key : -1; // Return -1 if tree is empty
}

int main() {
    struct Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    
    printf("Inorder traversal: ");
    inorder(root); // Output: 20 30 40 50 70
    printf("\nPreorder traversal: ");
    preorder(root); // Output: 50 30 20 40 70
    printf("\nPostorder traversal: ");
    postorder(root); // Output: 20 40 30 70 50

    printf("\nLargest: %d\n", findLargest(root));
    printf("Smallest: %d\n", findSmallest(root));

    // Delete a node
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);

    printf("Inorder after deletion: ");
    inorder(root); // Output should reflect the deletion

    return 0;
}
