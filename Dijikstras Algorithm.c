#include <stdio.h>  
#include <limits.h>

#define INF 9999  
#define MAX 10  

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {  
    int cost[MAX][MAX], distance[MAX];  
    int visited_nodes[MAX], counter, minimum_distance, next_node, i, j;  
  
    // Creating cost matrix  
    for (i = 0; i < size; i++)  
        for (j = 0; j < size; j++)  
            if (Graph[i][j] == 0)  
                cost[i][j] = INF;  
            else  
                cost[i][j] = Graph[i][j];  
  
    for (i = 0; i < size; i++) {  
        distance[i] = cost[start][i];  
        visited_nodes[i] = 0;  
    }  
  
    distance[start] = 0;  
    visited_nodes[start] = 1;  
    counter = 1;  
  
    while (counter < size - 1) {  
        minimum_distance = INF;  
  
        for (i = 0; i < size; i++)  
            if (distance[i] < minimum_distance && !visited_nodes[i]) {  
                minimum_distance = distance[i];  
                next_node = i;  
            }  
  
        visited_nodes[next_node] = 1;  
        for (i = 0; i < size; i++)  
            if (!visited_nodes[i])  
                if (minimum_distance + cost[next_node][i] < distance[i]) {  
                    distance[i] = minimum_distance + cost[next_node][i];  
                }  
        counter++;  
    }  
  
    // Printing the distance  
    printf("\nShortest distances from the starting node:\n");
    for (i = 0; i < size; i++)  
        if (i != start) {  
            printf("Node %d: %d\n", i, distance[i]);  
        }  
}

int main() {  
    int size=6, source;  
    
    int Graph[MAX][MAX] = {{0, 10, 0, 0, 5, 0}, 
                        {10, 0, 1, 0, 2, 3}, 
                        {0, 1, 0, 4, 0, 0}, 
                        {0, 0, 4, 0, 6, 7}, 
                        {5, 2, 0, 6, 0, 0}, 
                        {0, 3, 0, 7, 0, 0}};
    
    
    printf("Enter the starting node: ");
    scanf("%d", &source);
    
    DijkstraAlgorithm(Graph, size, source);  
  
    return 0;  
}
