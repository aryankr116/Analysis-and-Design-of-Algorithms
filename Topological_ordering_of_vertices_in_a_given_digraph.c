#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Graph {
int vertices;
int adj[MAX_VERTICES][MAX_VERTICES];
int in_degree[MAX_VERTICES];
} Graph;
void initGraph(Graph *g, int vertices) {
g->vertices = vertices;
for (int i = 0; i < vertices; i++) {
g->in_degree[i] = 0;
for (int j = 0; j < vertices; j++) {
g->adj[i][j] = 0;
}
}
}
void addEdge(Graph *g, int u, int v) {
g->adj[u][v] = 1;
g->in_degree[v]++;
}
void topologicalSort(Graph *g) {
int queue[MAX_VERTICES], front = 0, rear = 0;
int topOrder[MAX_VERTICES];
int index = 0;
for (int i = 0; i < g->vertices; i++) {
if (g->in_degree[i] == 0) {
queue[rear++] = i;
}
}
while (front < rear) {
int u = queue[front++];
topOrder[index++] = u;
for (int v = 0; v < g->vertices; v++) {
if (g->adj[u][v] == 1) {
g->in_degree[v]--;
if (g->in_degree[v] == 0) {
queue[rear++] = v;
}
}
}
}
if (index != g->vertices) {
printf("Graph contains a cycle, topological sorting is not possible.\n");
return;
}
printf("Topological Sort: ");
for (int i = 0; i < g->vertices; i++) {
printf("%d ", topOrder[i]);
}
printf("\n");
}
int main() {
Graph g;
int vertices, edges, u, v;
printf("Enter number of vertices: ");
scanf("%d", &vertices);
initGraph(&g, vertices);
printf("Enter number of edges: ");
scanf("%d", &edges);
printf("Enter edges (u v) format (0-based index):\n");
for (int i = 0; i < edges; i++) {
scanf("%d %d", &u, &v);
addEdge(&g, u, v);
}
topologicalSort(&g);
return 0;
}
