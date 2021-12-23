#include "heap.h"

#include <math.h>
#include <stdbool.h>
//This program is based off of the python code given via documentation from Professor Long

//helper function returns largest child branch
int max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    if ((right <= last) && (cmp(stats, A[right - 1], A[left - 1]) > 0)) {
        return right;
    }
    return left;
}

//sorts so the largest node in the heap is on top
void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    bool found = false;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);

    while ((mother <= floor(last / 2)) && !found) {
        if (cmp(stats, A[mother - 1], A[great - 1]) < 0) {
            swap(stats, &A[(int) (mother - 1)], &A[(int) (great - 1)]);
            mother = great;
            great = max_child(stats, A, mother, last);
        } else {
            found = true;
        }
    }
}

//organizes the array into heaps
void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    for (uint32_t father = last / 2; father > first - 1; father--) {
        fix_heap(stats, A, father, last);
    }
}

//sorts the array
void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t first = 1;
    build_heap(stats, A, first, n);
    for (uint32_t leaf = n; leaf > first; leaf--) {
        swap(stats, &A[(int) (first - 1)], &A[(int) (leaf - 1)]);
        fix_heap(stats, A, first, leaf - 1);
    }
}
