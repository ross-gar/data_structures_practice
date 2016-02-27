#include <iostream>
#include <cstdint>
#include "../include/test_utils.h"

int main() {
  rand_32bit_gen number_gen;
  // Initial LFSR states
  uint32_t initial_states [32] =
  {
    0x74345678, 0xad52345d, 0x12ff9372, 0x93847564, 0xdc284abc, 0x5f4a9d2c, 0x02d078ef, 0x2dabef12,
    0x123ffa78, 0xafcb345d, 0x12159372, 0x93fede64, 0xdc21237f, 0x54568d2c, 0x567078ef, 0x2d568f12,
    0xeef45678, 0xafff345d, 0x12ff7532, 0x93feed64, 0x123456fe, 0x5fefdd2c, 0x02d07ffe, 0x2345ef12,
    0x12fca678, 0xa123345d, 0x12aaa372, 0x9383dc64, 0xdc284abc, 0x5f4a9368, 0x021238ef, 0x2da67812
  };
  // Loop through all LFSRs and load their initial states
  for (int i = 0; i <= 31; i++) {
    number_gen.load_state(initial_states[i], i);
  }
  for (int i = 0; i <= 31; i++) {
    uint32_t val = number_gen.get_new_val();
    std::cout << "New value " << i << " is: " << val << std::endl;
  }
}