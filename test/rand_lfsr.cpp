#include <cstdint>
#include <iostream>
#include "../include/test_utils.h"

void rand_lfsr::load_state(uint32_t value) {
    current_state = value;
    //std::cout << "Setting new LFSR value: 0x" << std::hex << current_state << std::endl;
}

uint32_t rand_lfsr::shift_lfsr(void) {
    // Feedback polonomial for 32 bits:
    // x^32 + x^22 + x^2 + x^1 + 1
    // Create new bit to be appended to the current state
    // Assuming that the right most bit is 0 and the left most bit is bit 31
    unsigned new_bit = ((current_state >> 31) & 1 ) ^ ((current_state >> 21) & 1 ) ^ ((current_state >> 1) & 1 ) ^ (current_state & 1 );
    current_state = (current_state << 1) | new_bit;
    return current_state;
}

rand_lfsr::rand_lfsr() {
    current_state = 0x0000000;
    //std::cout << "Initializing new LFSR with value: 0x" << std::hex << current_state << std::endl;
}

rand_lfsr::rand_lfsr(uint32_t init_val) {
    current_state = init_val;
    //std::cout << "Initializing new LFSR with value: 0x" << std::hex << current_state << std::endl;
}