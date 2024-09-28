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
        printf("\nMemory Allocation failed. Please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BinaryTree {
    int index;
};

// Build the tree, pass BinaryTree 'b' by reference
struct Node* jbuildTree(struct BinaryTree* b, int nodes[]) {
    b->index++;  // Increment index

    if(nodes[b->index] == -1) return NULL;  // -1 means no node

    struct Node* newNode = createNode(nodes[b->index]);  // Create a new node with current value
    newNode->left = buildTree(b, nodes);   // Recursively build the left subtree
    newNode->right = buildTree(b, nodes);  // Recursively build the right subtree

    return newNode;  // Return the created node
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if(root == NULL) return;  // Base case

    inorderTraversal(root->left);
    printf(" %d ", root->data);
    inorderTraversal(root->right);
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if(root == NULL) return;  // Base case

    printf(" %d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if(root == NULL) return;  // Base case

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf(" %d ", root->data);
}

int main() {
    int nodes[] = {1, 2, 3, -1, -1, 4, -1, -1, 3, -1, 5, -1, -1, -1};  // Tree node array
    struct BinaryTree myTree;
    myTree.index = -1;  // Initialize index to -1

    struct Node* root = buildTree(&myTree, nodes);  // Build the tree, pass BinaryTree by reference

    // Print the tree in different orders
    printf("In-order Traversal of the Tree:\n");
    inorderTraversal(root);  // In-order traversal
    printf("\nPre-order Traversal of the Tree:\n");
    preorderTraversal(root);  // Pre-order traversal
    printf("\nPost-order Traversal of the Tree:\n");
    postorderTraversal(root);  // Post-order traversal
    
    return 0;
}
