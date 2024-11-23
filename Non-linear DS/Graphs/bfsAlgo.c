#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

void BFS(int startingNode, int graph[][4], int visited[], int numberOfNodes) {
    int queue[MAX_NODES], front = 0, rear = 0;

    queue[rear++] = startingNode;
    visited[startingNode] = 1;

    printf("\n BFS Traversal :");
    while(front < rear) {
        int curr = queue[front++];
        printf(" %d ", curr);
        
        for(int i=0; i<numberOfNodes; i++) {
            if(graph[curr][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    // Define the graph as a 2D array
    int graph[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 0}
    };
    
    // Define the visited array
    int visited[4] = {0}; // All nodes initially not visited (0)

    // Perform DFS starting from node 0
    BFS(0, graph, visited, 4);
    
    return 0;
}