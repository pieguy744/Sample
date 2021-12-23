#include "ht.h"
#include "salts.h"
#include "speck.h"

#include <stdlib.h>
#include <stdio.h>

uint64_t lookups = 0;

//stuct given from Professor Long in assignment documentation
struct HashTable {
    uint64_t salt[2];
    uint32_t size;
    Node **trees;
};

//builds new hash table
HashTable *ht_create(uint32_t size) {
    HashTable *ht = (HashTable *) malloc(sizeof(HashTable));
    if (ht) {
        ht->trees = (Node **) calloc(size, sizeof(Node *));
        ht->salt[0] = SALT_HASHTABLE_LO;
        ht->salt[1] = SALT_HASHTABLE_HI;
        ht->size = size;
    }
    return ht;
}

//prints out the contents of the hash table
void ht_print(HashTable *ht) {
    for (uint32_t i = 0; i < ht_size(ht); i++) {
        bst_print(ht->trees[i]);
    }
    return;
}

//frees all allocated memory
void ht_delete(HashTable **ht) {
    if (*ht) {
        for (uint32_t i = 0; i < ht_size(*ht); i++) {
            bst_delete(&(*ht)->trees[i]);
        }
        free((*ht)->trees);
        free(*ht);
        *ht = NULL;
    }
    return;
}

//returns the size of the hash table
uint32_t ht_size(HashTable *ht) {
    if (ht) {
        return ht->size;
    }
    return 0;
}

//searches for a node in the hashtable containing given oldspeak
Node *ht_lookup(HashTable *ht, char *oldspeak) {
    lookups++;
    if (ht) {
        uint32_t index = hash(ht->salt, oldspeak) % ht_size(ht);
        return bst_find(ht->trees[index], oldspeak);
    }
    return NULL;
}

//inserts new oldspeak/newspak into the hashtable
void ht_insert(HashTable *ht, char *oldspeak, char *newspeak) {
    lookups++;
    if (ht) {
        uint32_t index = hash(ht->salt, oldspeak) % ht_size(ht);
        ht->trees[index] = bst_insert(ht->trees[index], oldspeak, newspeak);
    }
    return;
}

//Returns the number of non-NULL binary search trees in the hash table.
uint32_t ht_count(HashTable *ht) {
    uint32_t count = 0;
    for (uint32_t i = 0; i < ht_size(ht); i++) {
        if (ht->trees[i]) {
            count++;
        }
    }
    return count;
}

//returns the average size of each of the non-NULL binary trees
double ht_avg_bst_size(HashTable *ht) {
    double size = 0;
    for (uint32_t i = 0; i < ht_size(ht); i++) {
        if (ht->trees[i]) {
            size += bst_size(ht->trees[i]);
        }
    }
    return size / ht_count(ht);
}

//returns the average size of each of the non-NULL binary trees
double ht_avg_bst_height(HashTable *ht) {
    double height = 0;
    for (uint32_t i = 0; i < ht_size(ht); i++) {
        if (ht->trees[i]) {
            height += bst_height(ht->trees[i]);
        }
    }
    return height / ht_count(ht);
}
