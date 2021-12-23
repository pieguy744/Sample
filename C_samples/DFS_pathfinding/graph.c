#include "graph.h"

#include "vertices.h"

#include <stdio.h>
#include <stdlib.h>

//This structure is given via code from Professor Long
struct Graph {
    uint32_t vertices; // Number of vertices.
    bool undirected; // Undirected graph?
    bool visited[VERTICES]; // Where have we gone?
    uint32_t matrix[VERTICES][VERTICES]; // Adjacency matrix.
};

//This function was given in assignment documentation by Professor Long.
//creates new graph structure
Graph *graph_create(uint32_t vertices, bool undirected) {
    Graph *G = (Graph *) calloc(1, sizeof(Graph));
    G->vertices = vertices;
    G->undirected = undirected;
    return G;
}

//This function was given in assignment documentation by Professor Long.
//Frees graph structure
void graph_delete(Graph **G) {
    free(*G);
    *G = NULL;
    return;
}

//returns number of vertices in a graph
uint32_t graph_vertices(Graph *G) {
    return G->vertices;
}

//adds an edge weight between two vertices
bool graph_add_edge(Graph *G, uint32_t i, uint32_t j, uint32_t k) {
    if (i < graph_vertices(G) && j < graph_vertices(G) && k > 0) {
        G->matrix[i][j] = k;
        if (G->undirected) {
            G->matrix[j][i] = k;
        }
        return true;
    }
    return false;
}

//checks if there is a nonzero edge weight between vertices
bool graph_has_edge(Graph *G, uint32_t i, uint32_t j) {
    if (i < graph_vertices(G) && j < graph_vertices(G) && G->matrix[i][j] > 0) {
        return true;
    }
    return false;
}

//returns the value of the edge weight between vertices
uint32_t graph_edge_weight(Graph *G, uint32_t i, uint32_t j) {
    if (i < graph_vertices(G) && j < graph_vertices(G)) {
        return G->matrix[i][j];
    } else {
        return 0;
    }
}

//checks if a vertex has been visited
bool graph_visited(Graph *G, uint32_t v) {
    if (v < G->vertices) {
        return G->visited[v];
    }
    return false;
}

//marks a vertex as visited
void graph_mark_visited(Graph *G, uint32_t v) {
    if (v < G->vertices) {
        G->visited[v] = true;
    }
    return;
}

//marks a vertex as unvisited
void graph_mark_unvisited(Graph *G, uint32_t v) {
    if (v < G->vertices) {
        G->visited[v] = false;
    }
    return;
}

//prints a representation of the graph
void graph_print(Graph *G) {
    if (G->undirected) {
    } else {
    }
    for (uint32_t i = 0; i < graph_vertices(G); i++) {
        for (uint32_t j = 0; j < graph_vertices(G); j++) {
            fprintf(stderr, "%u  ", graph_edge_weight(G, i, j));
        }
        fprintf(stderr, "\n");
    }
    for (uint32_t i = 0; i < graph_vertices(G); i++) {
        fprintf(stderr, "%d: %d  \n", i, graph_visited(G, i));
    }
}
