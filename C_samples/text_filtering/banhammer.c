#include "ht.h"
#include "bf.h"
#include "messages.h"
#include "parser.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>
#include <ctype.h>

#define OPTIONS "ht:f:sp"
#define WORD    "[a-zA-Z0-9'_-]+"

//converts all letters in a string to lowercase
// Based on code from tutorialspoint.com
// link: https://www.tutorialspoint.com/c_standard_library/c_function_tolower.htm
void to_lowercase(char *string) {
    int i = 0;
    while (string[i]) {
        string[i] = tolower(string[i]);
        i++;
    }
    return;
}

int main(int argc, char **argv) {
    int opt = 1;
    bool h = false;
    bool s = false;
    bool p = false;
    uint32_t t_size = 65536;
    uint32_t f_size = 1048576;
    char *badspeaker = "badspeak.txt";
    char *newspeaker = "newspeak.txt";
    regex_t expression;
    //if statement based on example code from Professor Long in assignment documentaion
    if (regcomp(&expression, WORD, REG_EXTENDED)) {
        fprintf(stderr, "Failed to compile regex.\n");
        return 1;
    }

    FILE *badfile;
    FILE *newfile;

    //parse user inputs
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': h = true; break;
        case 's': s = true; break;
        case 'p': p = true; break;
        case 't': t_size = atoi(optarg); break;
        case 'f': f_size = atoi(optarg); break;
        }
    }

    //help page
    if (h) {
        printf("SYNOPSIS\n   A word filtering program for the GPRSC.\n");
        printf("   Filters out and reports bad words parsed from stdin.\n\n");
        printf("USAGE\n  %s [-hs] [-t size] [-f size]\n\n", argv[0]);
        printf("OPTIONS\n  -h              Program usage and help.\n");
        printf("  -s           Print program statistics.\n");
        printf("  -t size      Specify hash table size (default: 2^16).\n");
        printf("  -f size      Specify Bloom filter size (default: 2^20).\n");
        return 0;
    }
    //open badspeak and newspeak files
    newfile = fopen(newspeaker, "r");
    if (newfile == NULL) {
        perror("Error opening file.");
        return 0;
    }
    badfile = fopen(badspeaker, "r");
    if (badfile == NULL) {
        fclose(newfile);
        perror("Error opening file.");
        return 0;
    }
    //initialize bloom filter, two bst nodes and hashtable
    BloomFilter *bloom = bf_create(f_size);
    HashTable *table = ht_create(t_size);
    Node *badspeak_found = bst_create();
    Node *oldspeak_found = bst_create();
    char oldspeak[60];
    char newspeak[60];
    //scan in badspeak and add it into the bloomfilter/hashtable
    while (fscanf(badfile, "%s\n", oldspeak) != EOF) {
        bf_insert(bloom, oldspeak);
        ht_insert(table, oldspeak, NULL);
    }
    fclose(badfile);
    //scan in newspeak/oldspeak pairs, insert oldspeak into bloomfilter and both into hashtable
    while (fscanf(newfile, "%s %s\n", oldspeak, newspeak) != EOF) {
        bf_insert(bloom, oldspeak);
        ht_insert(table, oldspeak, newspeak);
    }
    fclose(newfile);

    char *wordcheck;
    //read through stdin to look for criminal words
    while ((wordcheck = next_word(stdin, &expression)) != NULL) {
        to_lowercase(wordcheck);
        if (bf_probe(bloom, wordcheck)) {
            Node *found_node = ht_lookup(table, wordcheck);
            if (found_node) {
                if (found_node->newspeak) {
                    oldspeak_found = bst_insert(oldspeak_found, wordcheck, found_node->newspeak);
                } else {
                    badspeak_found = bst_insert(badspeak_found, wordcheck, NULL);
                }
            }
        }
    }
    regfree(&expression);
    if (s) {
        printf("Average BST size: %f\n", ht_avg_bst_size(table));
        printf("Average BST height: %f\n", ht_avg_bst_height(table));
        printf("Average branches traversed: %f\n", (float) branches / lookups);
        printf("Hash table load: %f%%\n", ((float) ht_count(table) / ht_size(table)) * 100);
        printf("Bloom filter load: %f%%\n", ((float) bf_count(bloom) / bf_size(bloom)) * 100);
    } else if (p) {
        printf("%f Avg BST height, ", ht_avg_bst_size(table));
        printf("%u Bloom filter Size, ", bf_size(bloom));
        printf("%u Hash Table Size, ", ht_size(table));
        printf("%lu Hash table lookups \n", lookups);
    } else if (oldspeak_found && badspeak_found) {
        printf("%s", mixspeak_message);
        bst_print(badspeak_found);
        bst_print(oldspeak_found);
    } else if (oldspeak_found) {
        printf("%s", goodspeak_message);
        bst_print(oldspeak_found);
    } else if (badspeak_found) {
        printf("%s", badspeak_message);
        bst_print(badspeak_found);
    }
    ht_delete(&table);
    bf_delete(&bloom);
    bst_delete(&badspeak_found);
    bst_delete(&oldspeak_found);
    return 0;
}
