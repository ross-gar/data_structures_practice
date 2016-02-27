#include <cstdint>
#include <iostream>
#include <stdexcept>
#include "../include/test_utils.h"

rand_32bit_gen::rand_32bit_gen() {
    // Load all LFSRs with 0s
    for (int i = 0; i <= 31; i++) {
        lfsr_array[i].load_state(0x0000000);
    }
}

void rand_32bit_gen::load_state (uint32_t new_state, uint32_t index) {
    // Check for out of range index
    if (index < 0 || index >31) {
        throw std::invalid_argument("Invalid index in call to rand_32bit_gen::load_state.");
    }
    // Index is in range
    else {
        lfsr_array[index].load_state(new_state);
    }
}

uint32_t rand_32bit_gen::get_new_val (void) {
    uint32_t new_val = 0x00000000;
    uint32_t masked_val = 0x00000000;
    // Loop through all LFSRs
    for (int i = 0; i <= 31; i++) {
        // Get random bit from LFSR in array and mask off the lowest bit (set all bits except for the first to 0)
        masked_val = (lfsr_array[i].shift_lfsr()) & 1;
        // Take the masked value (random bit), shift it by i (0=>31) bits and bitwise OR it to the new value
        new_val = new_val | ( (masked_val & 1) << i);
    }
    return new_val;
}