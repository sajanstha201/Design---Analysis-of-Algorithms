#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 6 
void dijkstra(int graph[V][V], int src);
int minDistance(int dist[], int visited[]);
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array to store the shortest distance from src to i
    int visited[V]; // Array to keep track of visited vertices
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Shortest distances from vertex %d to all other vertices:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance = %d\n", i, dist[i]);
    }
}
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
int main() {
    int graph[V][V]; // Weighted graph representation
    int source_vertex; // Source vertex for shortest path calculation
    printf("Enter the weighted graph (%d x %d matrix):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source_vertex);
    dijkstra(graph, source_vertex);
    return 0;
}
