#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 50

int graph[MAX_NODES][MAX_NODES];
int numberOfNodes;

void addPoint(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

void initializeGraph() {
    printf("Enter Number of Nodes :");
    scanf("%d", &numberOfNodes);

    for(int i=0.; i<numberOfNodes; i++) {
        for(int j=0; i< numberOfNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter Connections (-1 for termination): ");
    int from, to;
    while(1) {
        scanf("%d %d", &from, &to);
        if(from == -1 || to == -1) break;
        addPoint(from, to);
    }
}

void adjacencyMatrix() {
    for(int i=0;i <numberOfNodes; i++) {
        for(int j=0; j<numberOfNodes; j++) {
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();
    adjacencyMatrix();
    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;

void addEdge(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

void initializeGraph() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph (from to, -1 to stop): \n");
    int from, to;
    while(1) {
        scanf("%d %d", &from, &to);
        if (from == -1 || to == -1) break;
        addEdge(from, to);
    }
}

void adjacencyMatrix() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int choice;

    initializeGraph();

    do {
        printf("\nGraph Operations Menu:\n");
        printf("\n1. Adjacency Matrix");
        printf("\n0. Exit");
    
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adjacencyMatrix(numNodes);
                break;
            
            case 0:
                printf("Exiting program. GoodBye!\n");
                break;

            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}*/