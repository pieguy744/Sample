#include "bst.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

uint64_t branches = 0;

//creates a null node pointer
Node *bst_create(void) {
    return NULL;
}

//returns the height of the bst based at the root
uint32_t bst_height(Node *root) {
    if (!root) {
        return 0;
    }
    uint32_t height = 1;
    uint32_t left = 0;
    uint32_t right = 0;
    if (root->left != NULL) {
        left += bst_height(root->left);
    }
    if (root->right != NULL) {
        right += bst_height(root->right);
    }
    if (left > right) {
        height += left;
    } else {
        height += right;
    }
    return height;
}

//returns the size of the bst based at the root
uint32_t bst_size(Node *root) {
    if (!root) {
        return 0;
    }
    uint32_t size = 1;
    if (root->left != NULL) {
        size += bst_size(root->left);
    }
    if (root->right != NULL) {
        size += bst_size(root->right);
    }
    return size;
}

//returns the node containing oldspeak, or NULL if oldspeak isn't in the bst
Node *bst_find(Node *root, char *oldspeak) {
    if (root) {
        Node *check_right = NULL;
        Node *check_left = NULL;
        if (strcmp(root->oldspeak, oldspeak) == 0) {
            return root;
        }
        if (strcmp(root->oldspeak, oldspeak) > 0 && root->left) {
            branches += 1;
            check_left = bst_find(root->left, oldspeak);
        }
        if (strcmp(root->oldspeak, oldspeak) < 0 && root->right) {
            branches += 1;
            check_right = bst_find(root->right, oldspeak);
        }
        if (check_left) {
            return check_left;
        } else if (check_right) {
            return check_right;
        }
    }
    return NULL;
}

//insert a node into the bst in lexographical order
Node *bst_insert(Node *root, char *oldspeak, char *newspeak) {
    if (root) {
        if (strcmp(root->oldspeak, oldspeak) == 0) {
            return root;
        } else if (strcmp(root->oldspeak, oldspeak) > 0) {
            branches++;
            root->left = bst_insert(root->left, oldspeak, newspeak);
        } else {
            root->right = bst_insert(root->right, oldspeak, newspeak);
            branches++;
        }
        return root;
    }
    return node_create(oldspeak, newspeak);
}

//prints the bst through inorder traversal order
void bst_print(Node *root) {
    if (root) {
        if (root->left) {
            bst_print(root->left);
        }
        node_print(root);
        if (root->right) {
            bst_print(root->right);
        }
    }
    return;
}

//calls node_delete() for every node in the tree using post order traversal
void bst_delete(Node **root) {
    if (*root) {
        if ((*root)->left) {
            bst_delete(&((*root)->left));
        }
        if ((*root)->right) {
            bst_delete(&((*root)->right));
        }
        node_delete(root);
    }
    return;
}
