#include "bv.h"

#include <stdlib.h>
#include <stdio.h>

//stuct given from Professor Long in assignment documentation
struct BitVector {
    uint32_t length;
    uint8_t *vector;
};

//builds new bit vector ADT
BitVector *bv_create(uint32_t length) {
    BitVector *bv = (BitVector *) malloc(sizeof(BitVector));
    if (bv) {
        bv->length = length;
        bv->vector = (uint8_t *) calloc((length / 8) + 1, sizeof(uint8_t));
    }
    return bv;
}

//frees bv pointer and everything allocated in it
void bv_delete(BitVector **bv) {
    if (*bv) {
        free((*bv)->vector);
        free(*bv);
        *bv = NULL;
    }
}

//returns the length of the bitvector
uint32_t bv_length(BitVector *bv) {
    return bv->length;
}

//sets the bit at index i to 1
bool bv_set_bit(BitVector *bv, uint32_t i) {
    if (i < bv->length) {
        uint32_t index = i / 8;
        uint8_t bit = i % 8;
        bv->vector[index] |= (1 << bit);
        return true;
    }
    return false;
}

//sets the bit at index i to 0
bool bv_clr_bit(BitVector *bv, uint32_t i) {
    if (i < bv->length) {
        uint32_t index = i / 8;
        uint8_t bit = i % 8;
        bv->vector[index] &= ~(1 << bit);
        return true;
    }
    return false;
}

//returns true if the bit at index i is 1 and false otherwise
bool bv_get_bit(BitVector *bv, uint32_t i) {
    if (i < bv->length) {
        uint32_t index = i / 8;
        uint8_t bit = i % 8;
        uint8_t temp = bv->vector[index] & (1 << bit);
        temp = (temp >> bit);
        if (temp == 1) {
            return true;
        }
    }
    return false;
}

//prints out each bit in the vector in a line
void bv_print(BitVector *bv) {
    for (uint32_t i = 0; i < bv->length; i++) {
        if (bv_get_bit(bv, i)) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    printf("\n");
    return;
}
