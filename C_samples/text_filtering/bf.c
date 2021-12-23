#include "bf.h"
#include "salts.h"
#include "speck.h"

#include <stdlib.h>

//stuct given from Professor Long in assignment documentation
struct BloomFilter {
    uint64_t primary[2]; // Primary hash function salt.
    uint64_t secondary[2]; // Secondary hash function salt.
    uint64_t tertiary[2]; // Tertiary hash function salt.
    BitVector *filter;
};

//builds new Bloomfilter ADT
BloomFilter *bf_create(uint32_t size) {
    BloomFilter *bf = (BloomFilter *) malloc(sizeof(BloomFilter));
    if (bf) {
        bf->primary[0] = SALT_PRIMARY_LO;
        bf->primary[1] = SALT_PRIMARY_HI;
        bf->secondary[0] = SALT_SECONDARY_LO;
        bf->secondary[1] = SALT_SECONDARY_HI;
        bf->tertiary[0] = SALT_TERTIARY_LO;
        bf->tertiary[1] = SALT_TERTIARY_HI;
        bf->filter = bv_create(size);
    }
    return bf;
}

//frees memory allocated in the bf pointer
void bf_delete(BloomFilter **bf) {
    if (*bf) {
        bv_delete(&(*bf)->filter);
        free(*bf);
        *bf = NULL;
    }
    return;
}

//returns the size of the filter (i.e. the length of the inner bitvector)
uint32_t bf_size(BloomFilter *bf) {
    return bv_length(bf->filter);
}

//inserts the oldspeak into the bloomfilter
void bf_insert(BloomFilter *bf, char *oldspeak) {
    uint32_t i;
    i = hash(bf->primary, oldspeak) % bv_length(bf->filter);
    bv_set_bit(bf->filter, i);
    i = hash(bf->secondary, oldspeak) % bv_length(bf->filter);
    bv_set_bit(bf->filter, i);
    i = hash(bf->tertiary, oldspeak) % bv_length(bf->filter);
    bv_set_bit(bf->filter, i);
    return;
}

//checks if the oldspeak matches all of the possible hashes
bool bf_probe(BloomFilter *bf, char *oldspeak) {
    uint32_t a, b, c;
    a = hash(bf->primary, oldspeak) % bv_length(bf->filter);
    b = hash(bf->secondary, oldspeak) % bv_length(bf->filter);
    c = hash(bf->tertiary, oldspeak) % bv_length(bf->filter);
    if (bv_get_bit(bf->filter, a) && bv_get_bit(bf->filter, b) && bv_get_bit(bf->filter, c)) {
        return true;
    }
    return false;
}

//counts all of the set bits in the bloomfilter
uint32_t bf_count(BloomFilter *bf) {
    uint32_t count = 0;
    for (uint32_t i = 0; i < bf_size(bf); i++) {
        if (bv_get_bit(bf->filter, i)) {
            count++;
        }
    }
    return count;
}

//prints the bitvector in the filter
void bf_print(BloomFilter *bf) {
    bv_print(bf->filter);
    return;
}
