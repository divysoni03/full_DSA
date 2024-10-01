#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nMemory allocation failed, please try again.");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a node
struct Node* insertNode(struct Node* root, int data) {
    if(root == NULL) return createNode(data); // If root is NULL, insert new node as the root

    if(data < root->data) {
        root->left = insertNode(root->left, data); // Insert in the left subtree
    } else if(data > root->data) {
        root->right = insertNode(root->right, data); // Insert in the right subtree
    }
    return root; // Return the root node
}

// Pre-order traversal
void preOrder(struct Node* root) {
    if(root != NULL) {
        printf(" %d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// In-order traversal
void inOrder(struct Node* root) {
    if(root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    }
}

// Post-order traversal
void postOrder(struct Node* root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->data);
    }
}

// Function to search for a node with specific data
struct Node* searchNode(struct Node* root, int data) {
    if(root == NULL || root->data == data) { // Either found the node or reached a leaf
        return root;
    }
    
    if(data < root->data) {
        return searchNode(root->left, data); // Search in the left subtree
    } else {
        return searchNode(root->right, data); // Search in the right subtree
    }
}

// Function to print the tree in a 2D view
void printTree(struct Node* root, int space) {
    if(root == NULL) return;
    
    space += 4;
    printTree(root->right, space);
    
    for(int i = 4; i < space; i++) printf(" "); // Add spaces for formatting
    printf("%d\n", root->data); // Print node data
    
    printTree(root->left, space); // Print left subtree
}

int height(struct Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

struct Node* deleteNode(struct Node* root, int data) {
    if(root == NULL) return root; // if it becomes null then return null

    if(data < root->data) { // if the data is in the left portion then call recursively to left portion
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) { // if the data is in the right portion call recursively to right portion
        root->right = deleteNode(root->right, data);
    }
    else { // if we find the node which we are searching for then it won't be any left or right
        if(root->left == NULL) { // if the left portion is null then make the right portion best successor

        
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) { // if the right node is null then left will be the next successor
            struct Node* temp = root->left; // store left and then return to the parent root -> of root
            free(root);
            return temp; // returning 
        }

        struct Node* temp = root->right;
        while(temp != NULL) {
            temp = temp->left; // going left till reaches null in the right node of the root Node
        }
        root->data = temp->data; // transferring the last node(best successor) data to the root node which will be deleted
        root->right = deleteNode(root->right, temp->data); // it will delete the node after making successor
    }

    return root; //final return
}

void findMinMax(struct Node* root, int *min, int *max) {
    struct Node* temp = root;
    while(root->left != NULL) {
        *min = root->data;
        root = root->left; // moving into left direction to find the min value
    }

    while(temp->right != NULL) {
        *max = temp->data;
        temp = temp->right; // moving right direction to find the max value
    }
}

void pruneTree(struct Node** root) {
    if(*root != NULL) {
        struct Node* temp = root;
        pruneTree(&((*root)->left)); // calling left side nodes
        pruneTree(&((*root)->right)); // calling right side nodes
        free(temp);
        *root = NULL; // so no-one can access the past root node and root node will remain NULL like starting
    }
}

int main() {
    struct Node* root = NULL; // The root of the tree
    int choice = INT_MIN, data;

    // Loop through menu choices
    do {
        system("cls"); // Clears the console screen
        printTree(root, 0);
        printf("\n1. Insert Node\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Search for data\n6. Print Tree\n0. Exit\nEnter Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                root = insertNode(root, data); // Insert node in BST
                break;
            case 2:
                printf("\nIn-order Traversal: ");
                inOrder(root);
                printf("\n");
                system("pause");
                break;
            case 3:
                printf("\nPre-order Traversal: ");
                preOrder(root);
                printf("\n");
                system("pause");
                break;
            case 4:
                printf("\nPost-order Traversal: ");
                postOrder(root);
                printf("\n");
                system("pause");
                break;
            case 5:
                printf("\nEnter data to search: ");
                scanf("%d", &data);
                if(searchNode(root, data) != NULL) {
                    printf("\n%d found in the tree.\n", data);
                } else {
                    printf("\n%d not found in the tree.\n", data);
                }
                system("pause");
                break;
            case 6:
                printTree(root, 0);
                system("pause");
                break;
            case 0:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid input, please try again.\n");
                system("pause");
                break;
        }
    } while(choice != 0);
    
    return 0;
}