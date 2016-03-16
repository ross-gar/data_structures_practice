#include <iostream>
#include <cstdint>
#include "../include/test_utils.h"

void merge_sort(uint32_t *data_array, uint32_t *working_array, uint32_t size);

int main() {
  // Array to be sorted and working space array
  uint32_t sort_me [array_size];
  uint32_t working_space [array_size];
  // Load arrays with 0s
  for (int i = 0; i <= (array_size-1); i++) {
    sort_me[i]       = 0x00000000;
    working_space[i] = 0x00000000;
  }

  rand_32bit_gen number_gen;
  // Loop through all LFSRs and load their initial states
  for (int i = 0; i <= (array_size-1); i++) {
    number_gen.load_state(initial_states[i], i);
  }
  
  // Main test loop
  const uint32_t number_iterations = 50;
  for (int i=0 ; i <= (number_iterations-1); i++) {
    std::cout << "Running iteration " << i+1 << " ... ";
      
    // Get new pseudorandom values for sorting array
    for (int i = 0; i <= (array_size-1); i++) {
      uint32_t val = number_gen.get_new_val();
      sort_me[i] = val;
    }
    
    /*
    for (int i = 0; i <= (array_size-1); i++) {
      std::cout << "Pre Sort Value " << i << " is: " << sort_me[i] << std::endl;
    }
    */
    
    // Call merge sort function
    merge_sort(sort_me, working_space, array_size);
    
    /*
    for (int i = 0; i <= (array_size-1); i++) {
      std::cout << "Sorted Value " << i << " is: " << sort_me[i] << std::endl;
    }
    */
    
    // Check sorted array
    bool result = check_sort(sort_me, array_size);
    if (result == true) { std::cout << "Test " << i+1 << " passed" << std::endl;}
    else {std::cout << "Test " << i+1 << " failed" << std::endl;}
  }
  
  return 1;
}