#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory allocation failed, please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node* insertNode(struct Node* root, int data) {
    if(root == NULL) return createNode(data);

    if(data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void inOrder(struct Node* root) {
    if(root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}
void preOrder(struct Node* root) {
    if(root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}
struct Node* searchNode(struct Node* root, int data) {
    if(root == NULL && root->data == data) return root; // found the node

    if(data < root->data) {
        return searchNode(root->left, data); // for searching on the left side
    }
    else {
        return searchNode(root->right, data); // for searching on the right side
    }
}

void printTree(struct Node* root, int space) {
    if(root == NULL) return;

    space += 4;
    printTree(root->right, space);
    
    for(int i=4; i<space; i++) printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main() {
    struct Node* root = NULL;


    root = insertNode(root, 20);
    root = insertNode(root, 11);
    root = insertNode(root, 12);
    root = insertNode(root, 30);
    root = insertNode(root, 50);


    printTree(root, 0);


    printf("\n\n\nin-order : ");
    inOrder(root);
    printf("\n\n\npre-order :");
    preOrder(root);
    printf("\n\n\npost-order :");
    postOrder(root);

    printf(searchNode(root, 11) ? "\nfound it" : "\nnot found");

    
    return 0;
}