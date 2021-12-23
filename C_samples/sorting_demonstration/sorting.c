#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aeisqr:n:p:h:"
typedef enum { HEAP, INSERT, QUICK, SHELL } Sorts;

int main(int argc, char **argv) {
    Stats stat;
    reset(&stat);
    Set sort = empty_set();
    int opt = 0;
    bool h = false;
    Set all = empty_set();
    all = insert_set(HEAP, all);
    all = insert_set(SHELL, all);
    all = insert_set(INSERT, all);
    all = insert_set(QUICK, all);
    uint32_t seed = 13371453;
    uint32_t size = 100;
    uint32_t elements = 100;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': sort = union_set(sort, all); break;
        case 'e': sort = insert_set(HEAP, sort); break;
        case 'i': sort = insert_set(INSERT, sort); break;
        case 's': sort = insert_set(SHELL, sort); break;
        case 'q': sort = insert_set(QUICK, sort); break;
        case 'r': seed = atoi(optarg); break;
        case 'n': size = atoi(optarg); break;
        case 'p': elements = atoi(optarg); break;
        case 'h': h = true; break;
        }
    }

    // test aray that unsorted will be copied into before each sort function
    uint32_t *sort_test;
    sort_test = (uint32_t *) malloc(size * sizeof(uint32_t));
    if (sort_test == NULL) {
        size = 100;
        sort_test = (uint32_t *) malloc(size * sizeof(uint32_t));
    }

    if (elements > size) {
        elements = size;
    }

    srandom(seed);
    for (uint32_t i = 0; i < size; i++) {
        sort_test[i] = random() & 0x3FFFFFFF;
    }

    if (member_set(HEAP, sort)) {
        reset(&stat);
        heap_sort(&stat, sort_test, size);
        printf("Heap Sort , %d elements , %lu moves , %lu  compares\n", size, stat.moves,
            stat.compares);
        for (uint32_t i = 0; (i < size) & (i < elements); i++) {
            uint32_t sizecheck = sort_test[i];
            for (uint32_t j = 0; j < 9; j++) {
                sizecheck /= 10;
                if (sizecheck == 0) {
                    printf(" ");
                }
            }
            printf("   %d", sort_test[i]);
            if (((i + 1) % 5 == 0) | (i == size - 1)) {
                printf("\n");
            }
        }
    }
    if (member_set(INSERT, sort)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            sort_test[i] = random() & 0x3FFFFFFF;
        }
        reset(&stat);
        insertion_sort(&stat, sort_test, size);
        printf("Insertion Sort , %d elements , %lu moves , %lu  compares\n", size, stat.moves,
            stat.compares);
        for (uint32_t i = 0; (i < size) && (i < elements); i++) {
            uint32_t sizecheck = sort_test[i];
            for (uint32_t j = 0; j < 9; j++) {
                sizecheck /= 10;
                if (sizecheck == 0) {
                    printf(" ");
                }
            }
            printf("   %d", sort_test[i]);
            if (((i + 1) % 5 == 0) | (i == size - 1)) {
                printf("\n");
            }
        }
    }
    if (member_set(SHELL, sort)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            sort_test[i] = random() & 0x3FFFFFFF;
        }
        reset(&stat);
        shell_sort(&stat, sort_test, size);
        printf("Shell Sort , %d elements , %lu moves , %lu  compares\n", size, stat.moves,
            stat.compares);
        for (uint32_t i = 0; (i < size) && (i < elements); i++) {
            uint32_t sizecheck = sort_test[i];
            for (uint32_t j = 0; j < 9; j++) {
                sizecheck /= 10;
                if (sizecheck == 0) {
                    printf(" ");
                }
            }
            printf("   %d", sort_test[i]);
            if (((i + 1) % 5 == 0) | (i == size - 1)) {
                printf("\n");
            }
        }
    }
    if (member_set(QUICK, sort)) {
        srandom(seed);
        for (uint32_t i = 0; i < size; i++) {
            sort_test[i] = random() & 0x3FFFFFFF;
        }
        reset(&stat);
        quick_sort(&stat, sort_test, size);
        printf("Quick Sort , %d elements , %lu moves , %lu compares\n", size, stat.moves,
            stat.compares);
        for (uint32_t i = 0; (i < size) & (i < elements); i++) {
            uint32_t sizecheck = sort_test[i];
            for (uint32_t j = 0; j < 9; j++) {
                sizecheck /= 10;
                if (sizecheck == 0) {
                    printf(" ");
                }
            }
            printf("   %d", sort_test[i]);
            if (((i + 1) % 5 == 0) | (i == size - 1)) {
                printf("\n");
            }
        }
    }
    if (h || (sort == empty_set())) {
        printf("SYNOPSIS\n   A collection of comparison-based sorting algorithms.\n\n");
        printf("USAGE\n   %s [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n\n", argv[0]);
        printf("OPTIONS\n  -h              display program help and usage.\n");
        printf("  -a              enable all sorts.\n");
        printf("  -e              enable Heap Sort.\n  -i              enable Insertion Sort.\n");
        printf("  -s              enable Shell Sort.\n  -q              enable Quick Sort.\n");
        printf("  -n length       specify number of array elements (default: 100).\n");
        printf("  -p elements     specify number of elements to print (default: 100).\n");
        printf("  -r seed         specify random seed (default: 13371453).\n");
    }
    free(sort_test);
    return 0;
}
