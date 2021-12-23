#include "path.h"

#include "stack.h"
#include "vertices.h"

#include <stdlib.h>

//This structure is given via code from Professor Long
struct Path {
    Stack *vertices; // The vertices comprising the path.
    uint32_t length; // The total length of the path.
};

Path *path_create(void) {
    Path *p = (Path *) malloc(sizeof(Path));
    if (p) {
        p->length = 0;
        p->vertices = stack_create(VERTICES);
        if (!p->vertices) {
            free(p);
            p = NULL;
        }
    }
    return p;
}

void path_delete(Path **p) {
    stack_delete(&((*p)->vertices));
    free(*p);
    *p = NULL;
    return;
}

bool path_push_vertex(Path *p, uint32_t v, Graph *G) {
    if (stack_empty(p->vertices)) {
        if (stack_push(p->vertices, v)) {
            return true;
        }
    }
    uint32_t start = 0;
    stack_peek(p->vertices, &start);
    if (graph_has_edge(G, start, v)) {
        if (stack_push(p->vertices, v)) {
            p->length += graph_edge_weight(G, start, v);
            graph_mark_visited(G, v);
            return true;
        }
    }
    return false;
}

bool path_pop_vertex(Path *p, uint32_t *v, Graph *G) {
    if (!stack_pop(p->vertices, v)) {
        return false;
    }
    uint32_t start = 0;
    stack_peek(p->vertices, &start);
    p->length -= graph_edge_weight(G, start, *v);
    graph_mark_unvisited(G, *v);
    return true;
}

uint32_t path_vertices(Path *p) {
    return stack_size(p->vertices);
}

uint32_t path_length(Path *p) {
    return p->length;
}

void path_copy(Path *dst, Path *src) {
    stack_copy(dst->vertices, src->vertices);
    dst->length = src->length;
    return;
}

void path_print(Path *p, FILE *outfile, char *cities[]) {
    fprintf(outfile, "Path length: %u\nPath: ", p->length);
    stack_print(p->vertices, outfile, cities);
    return;
}
