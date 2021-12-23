#include "shell.h"

#include <math.h>
//Based on python code given in documentation by Professor Long

//sorts based off a decreasing gap
void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t gap_max = (log(3 + 2 * n) / log(3));

    for (uint32_t gap_val = gap_max; gap_val > 0; gap_val -= 1) {
        uint32_t gap = floor((pow(3, gap_val) - 1) / 2);
        for (uint32_t i = gap; i < n; i++) {

            uint32_t j = i, temp = move(stats, A[(int) i]);
            while ((j >= gap) && (cmp(stats, temp, A[(int) (j - gap)]) == -1)) {
                A[(int) j] = move(stats, A[(int) (j - gap)]);
                j -= gap;
            }
            A[j] = move(stats, temp);
        }
    }
}
