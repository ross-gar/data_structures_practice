#include <cstdint>
#include <stdexcept>
#include <iostream>
#include "../include/test_utils.h"

//------------------------------------------------------------------------------
// check_sort implementation
//------------------------------------------------------------------------------
bool check_sort(uint32_t *data_array, uint32_t size) {
    // Loop through all elements starting with 1 and check that it is not
    // smaller than the one before it
    for (int i = 1; i <= (size-1); i++) {
        //     element i           the element before i
        if ( *(data_array + i) < *(data_array + i - 1) ) { return false;}
        if ( *(data_array + i) == *(data_array + i - 1) ) {
          std::cout << "Warning: Found identical values while checking array sort" << std::endl;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
// randomize_data implementation
//------------------------------------------------------------------------------
void randomize_data(uint32_t *data_array, rand_32bit_gen *number_gen, uint32_t size) {
    // Get new pseudorandom values
    for (int i = 0; i <= (size-1); i++) {
      // Call member function get_new_val of rand_32bit_gen
      uint32_t val = number_gen->get_new_val();
      *(data_array + i) = val;
    }
}

//------------------------------------------------------------------------------
// rand_lfsr implementation
//------------------------------------------------------------------------------
rand_lfsr::rand_lfsr() { current_state = 0x0000000; }

rand_lfsr::rand_lfsr(uint32_t init_val) { current_state = init_val; }

void rand_lfsr::load_state(uint32_t value) { current_state = value; }

uint32_t rand_lfsr::shift_lfsr(void) {
    // Feedback polonomial for 32 bits:
    // x^32 + x^22 + x^2 + x^1 + 1
    // Create new bit to be appended to the current state
    // Assuming that the right most bit is 0 and the left most bit is bit 31
    unsigned new_bit = ((current_state >> 31) & 1 ) ^ ((current_state >> 21) & 1 ) ^ ((current_state >> 1) & 1 ) ^ (current_state & 1 );
    current_state = (current_state << 1) | new_bit;
    return current_state;
}

//------------------------------------------------------------------------------
// rand_32bit_gen implementation
//------------------------------------------------------------------------------
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