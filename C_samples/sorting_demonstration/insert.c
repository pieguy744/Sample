#include "insert.h"
//This program is based off of the python code given via documentation from Professor Long
// sorts an array by moving the out of place value backwards until it's in it's place.
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (uint32_t i = 1; i < n; i++) {
        uint32_t j = i, temp = A[i];
        while ((j > 1) & (cmp(stats, temp, A[j - 1]) < 0)) {
            A[j] = move(stats, A[j - 1]);
            j -= 1;
        }
        if ((j == 1) & (cmp(stats, temp, A[j - 1]) < 0)) {
            A[j] = move(stats, A[0]);
            j -= 1;
        }
        A[j] = temp;
    }
}
