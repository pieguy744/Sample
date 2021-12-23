#include "node.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//creates new bst node
Node *node_create(char *oldspeak, char *newspeak) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n && oldspeak) {
        n->oldspeak = strdup(oldspeak);
        if (newspeak) {
            n->newspeak = strdup(newspeak);
        } else {
            n->newspeak = NULL;
        }
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

//frees all the memory in a bst node
void node_delete(Node **n) {
    if (*n) {
        free((*n)->oldspeak);
        if ((*n)->newspeak) {
            free((*n)->newspeak);
        }
        free(*n);
        *n = NULL;
    }
    return;
}

//prints the oldspeak and newspeak (if applicable)
void node_print(Node *n) {
    if (!n) {
        printf("NULL\n");
        return;
    }
    if (n->newspeak) {
        printf("%s -> %s\n", n->oldspeak, n->newspeak);
    } else {
        printf("%s\n", n->oldspeak);
    }
    return;
}
