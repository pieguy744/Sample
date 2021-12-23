#include "stack.h"

#include <stdlib.h>

//This structure is given via code from Professor Long
struct Stack {
    uint32_t top; // Index of the next empty slot.
    uint32_t capacity; // Number of items that can be pushed.
    uint32_t *items; // Array of items , each with type uint32_t.
};

//This function was given in assignment documentation by Professor Long.
//creates new stack structure
Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (uint32_t *) calloc(capacity, sizeof(uint32_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

//This function was given in assignment documentation by Professor Long.
//Deletes given stack structure
void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}

bool stack_empty(Stack *s) {
    if (s->top == 0) {
        return true;
    }
    return false;
}

bool stack_full(Stack *s) {
    if (s->top == s->capacity) {
        return true;
    }
    return false;
}

uint32_t stack_size(Stack *s) {
    return s->top;
}

bool stack_push(Stack *s, uint32_t x) {
    if (stack_full(s)) {
        return false;
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

bool stack_pop(Stack *s, uint32_t *x) {
    if (stack_empty(s)) {
        return false;
    }
    if (s->top == 1) {
        *x = s->items[0];
    } else {
        *x = s->items[(int) ((s->top) - 1)];
    }
    s->top--;
    return true;
}

bool stack_peek(Stack *s, uint32_t *x) {
    if (stack_empty(s)) {
        return false;
    }
    *x = s->items[(s->top) - 1];
    return true;
}

void stack_copy(Stack *dst, Stack *src) {
    for (uint32_t i = 0; i < src->top; i++) {
        dst->items[i] = src->items[i];
    }
    dst->top = src->top;
    return;
}

void stack_print(Stack *s, FILE *outfile, char *cities[]) {
    for (uint32_t i = 0; i < s->top; i += 1) {
        fprintf(outfile, "%s", cities[s->items[i]]);
        if (i + 1 != s->top) {
            fprintf(outfile, " -> ");
        }
    }
    fprintf(outfile, "\n");
}
