#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void union_set(Subset subsets[], int x, int y) {
    int root_x = find(subsets, x);
    int root_y = find(subsets, y);

    if (subsets[root_x].rank < subsets[root_y].rank) {
        subsets[root_x].parent = root_y;
    } else if (subsets[root_x].rank > subsets[root_y].rank) {
        subsets[root_y].parent = root_x;
    } else {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

int compare_edge(const void* a, const void* b) {
    Edge* edge_a = (Edge*) a;
    Edge* edge_b = (Edge*) b;
    return edge_a->w - edge_b->w;
}

Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    return graph;
}

void add_edge(Graph* graph, int u, int v, int w) {
    Edge edge = { u, v, w };
    graph->edges[graph->num_edges++] = edge;
}

Graph* kruskal_mst(Graph* graph) {
    int num_vertices = graph->num_vertices;
    Edge result[num_vertices];
    int e = 0, i = 0;

    qsort(graph->edges, graph->num_edges, sizeof(Edge), compare_edge);

    Subset subsets[num_vertices];
    for (int v = 0; v < num_vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < num_vertices - 1 && i < graph->num_edges) {
        Edge next_edge = graph->edges[i++];

        int u = find(subsets, next_edge.u);
        int v = find(subsets, next_edge.v);

        if (u != v) {
            result[e++] = next_edge;
            union_set(subsets, u, v);
        }
    }

    Graph* mst = create_graph(num_vertices, e);
    for (int i = 0; i < e; i++) {
        Edge edge = result[i];
        add_edge(mst, edge.u, edge.v, edge.w);
    }

    return mst;
}

int main() {
    //int num_vertices, num_edges;
    //scanf("%d %d", &num_vertices, &num_edges);
    Graph* graph = create_graph(4, 5);  // grafo com 4 vértices e 5 arestas
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 2, 6);
    add_edge(graph, 0, 3, 5);
    add_edge(graph, 1, 3, 15);
    add_edge(graph, 2, 3, 4);

    // Graph* graph = create_graph(num_vertices, num_edges);
    // for (int i = 0; i < num_edges; i++) {
    //     int u, v, w;
    //     scanf("%d %d %d", &u, &v, &w);
    //     add_edge(graph, u, v, w);
    // }

    Graph* mst = kruskal_mst(graph);

    printf("Árvore Geradora Mínima (AGM):\n");
    for (int i = 0; i < mst->num_edges; i++) {
        Edge edge = mst->edges[i];
        printf("%d - %d (peso %d)\n", edge.u, edge.v, edge.w);
    }

    return 0;
}