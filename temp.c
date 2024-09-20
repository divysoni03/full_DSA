#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory Allocation failed. please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct BinaryTree {
    int index;
};
struct Node* buildTree(struct BinaryTree b, int nodes[]) {
    b.index++;
    if(nodes[b.index] == -1) return NULL;

    struct Node* newNode = creatNode(nodes[b.index]);
    newNode->left = buildTree(b, nodes);
    newNode->right = buildTree(b, nodes);

    return newNode;
}

int main() {    
    int nodes[] = {1,2,3,-1,-1,4,-1,-1,3,-1,5,-1,-1,-1};
    struct BinaryTree myTree;
    myTree.index = -1;
    struct Node* root = buildTree(myTree, nodes);
    printf("root Node data : %d", root->data);
    printf("\ndata : %d", root->left->data);
    printf("\ndata : %d", root->left->left->data);
    printf("\ndata : %d", root->right->data);
    return 0;
}