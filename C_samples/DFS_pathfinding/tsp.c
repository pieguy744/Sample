#include "graph.h"
#include "path.h"
#include "stack.h"
#include "vertices.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "hvui:o:"
static uint32_t recursions = 0;

void dfs(Graph *G, Path *curr, Path *shortest, char *cities[], bool verbose, FILE *outfile) {
    recursions++;
    //number of locations
    uint32_t loc_num = graph_vertices(G);
    for (uint32_t i = 0; i < loc_num; i++) {
        if ((i == 0 && path_vertices(curr) != loc_num) || graph_visited(G, i)) {
            continue;
        }
        if (path_push_vertex(curr, i, G)) { //push to the path
            uint32_t popped = 0;
            if (path_vertices(shortest) > 0 && path_length(curr) > path_length(shortest)) {
                path_pop_vertex(curr, &popped, G);
                break;
            }
            if (path_vertices(curr) == loc_num + 1) { //checks if path is complete
                if (path_vertices(shortest) == 0 || path_length(curr) < path_length(shortest)) {
                    path_copy(shortest, curr);
                }
                if (verbose) {
                    path_print(curr, outfile, cities);
                }
            } else {
                dfs(G, curr, shortest, cities, verbose, outfile);
            }
            path_pop_vertex(curr, &popped, G);
        }
    }
    if (path_length(curr) == 0) {
        path_print(shortest, outfile, cities);
    }
}

int main(int argc, char **argv) {
    int opt = 0;
    bool h = false;
    bool v = false;
    bool u = false;
    char *input = NULL;
    char *output = NULL;
    FILE *f_in = stdin;
    FILE *f_out = stdout;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': h = true; break;
        case 'v': v = true; break;
        case 'u': u = true; break;
        case 'i': input = optarg; break;
        case 'o': output = optarg; break;
        }
    }

    //help page
    if (h) {
        printf("SYNOPSIS\n  Traveling Salesman Problem using DFS.\n\n");
        printf("USAGE\n  %s [-u] [-v] [-h] [-i infile] [-o outfile]\n\n", argv[0]);
        printf("OPTIONS\n  -h              display program help and usage.\n");
        printf("  -u             Use undirected graph.\n");
        printf("  -v             Enable verbose printing.\n");
        printf("  -h             Program usage and help.\n");
        printf("  -i infile      Input containing graph (default: stdin)\n");
        printf("  -o outfile     Output of computed path (default: stdout)\n");
        return 0;
    }

    if (input) {
        f_in = fopen(input, "r");
        if (f_in == NULL) {
            perror("Error opening file, defaulting to stdin");
            f_in = stdin;
        }
    }
    if (output) {
        FILE *f_out = fopen(output, "w");
        if (f_out == NULL) {
            perror("Error opening file, defaulting to stdout.\n");
            f_out = stdout;
        }
    }
    //pointer that takes the stings pulled from the file line by line
    char pull[60];
    //pulls the first line dictating number of vertices
    fgets(pull, 60, f_in);
    uint32_t vertices = atoi(pull);
    if (vertices > VERTICES || vertices == 0) {
        perror("Error, invalid number of vertices.");
        return 0;
    }
    //pulls all of the names of the cities.
    char *cities[vertices];
    for (uint32_t i = 0; i < vertices; i++) {
        fgets(pull, 60, f_in);
        pull[strcspn(pull, "\n")] = 0;
        cities[i] = strdup(pull);
    }
    //create and fill graph stucture with given input
    Graph *G = graph_create(vertices, u);
    uint32_t i, j, k;
    int error = fscanf(f_in, "%u %u %u", &i, &j, &k);
    while (error != EOF) {
        if (error != 3) {
            perror("Error: input is malformed.\n");
            return 0;
        }
        graph_add_edge(G, i, j, k);
        error = fscanf(f_in, "%u %u %u", &i, &j, &k);
    }
    //close input file and open output file;
    fclose(f_in);
    f_in = NULL;

    
    //create path structures for the hamiltonian pash search
    Path *curr = path_create(), *shortest = path_create();
    path_push_vertex(curr, 0, G);
    dfs(G, curr, shortest, cities, v, f_out);
    fprintf(f_out, "Total recursive calls: %u\n", recursions);
    fclose(f_out);
    f_out = NULL;
    for (uint32_t i = 0; i < vertices; i++) {
        free(cities[i]);
    }

    graph_delete(&G);
    path_delete(&curr);
    path_delete(&shortest);
    return 0;
}
