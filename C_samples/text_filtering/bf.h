#pragma once

#include "bv.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct BloomFilter BloomFilter;

BloomFilter *bf_create(uint32_t size);

void bf_delete(BloomFilter **bf);

uint32_t bf_size(BloomFilter *bf);

void bf_insert(BloomFilter *bf, char *oldspeak);

bool bf_probe(BloomFilter *bf, char *oldspeak);

uint32_t bf_count(BloomFilter *bf);

void bf_print(BloomFilter *bf);
