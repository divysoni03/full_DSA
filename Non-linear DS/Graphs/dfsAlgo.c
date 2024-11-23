#include<stdio.h>

void DFS(int startingNode, int graph[][4], int *visited, int numberOfNodes) {
    printf(" %d ", startingNode);
    visited[startingNode] = 1; // Marking as visited

    for(int i = 0; i < numberOfNodes; i++) {
        // Checking if there is a connection and if the node is not visited
        if(graph[startingNode][i] == 1 && !visited[i]) {
            DFS(i, graph, visited, numberOfNodes); // Recursive DFS call
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
    DFS(0, graph, visited, 4);
    
    return 0;
}
