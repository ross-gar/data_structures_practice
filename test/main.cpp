//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdint>
#include <string>
#include "../include/test_utils.h"
// Include sort sources files here because they are template functions
#include "../src/merge_sort.cpp"
#include "../src/bubble_sort.cpp"
#include "../src/comb_sort.cpp"
#include "../src/heap_sort.cpp"
#include "../src/selection_sort.cpp"

//------------------------------------------------------------------------------
// Main test function
//------------------------------------------------------------------------------
int main() {
  //---------------------------------------------------------------
  // Random Number Generator Setup
  //---------------------------------------------------------------
  // Instantiate random number generator
  rand_32bit_gen number_gen;
  // Loop through all LFSRs and load their initial states
  // 32 initial states for generating uint32_t numbers
  for (int i = 0; i <= (32-1); i++) {
    number_gen.load_state(initial_lfsr_states[i], i);
  }

  //---------------------------------------------------------------
  // Main test loops
  //---------------------------------------------------------------
  for (int x=0; x < num_array_sizes; x++) {
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Using array size of " << array_sizes[x] << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    
    // Create array to be sorted and working space array
    uint32_t * sort_me;
    sort_me = new uint32_t [array_sizes[x]];
    uint32_t * working_space;
    working_space = new uint32_t [array_sizes[x]];

    // Load arrays with 0s
    for (int i = 0; i <= (array_sizes[x]-1); i++) {
      sort_me[i]       = 0x00000000;
      working_space[i] = 0x00000000;
    }

    // Test all algorithms
    for (int i = 0; i < num_algos; i++) {
      std::cout << "\tRunning " << number_iterations << " tests of " << algo_names[i] << std::endl;

      // Perform sort and check loops
      for (int iter = 0 ; iter < number_iterations; iter++) {
        // Call function to get new pseudorandom values for sorting array
        randomize_data(sort_me, &number_gen, array_sizes[x]);

        // Call appropriate sort function
        switch (i){
          case 0 : merge_sort(sort_me, working_space, array_sizes[x]); break;
          case 1 : bubble_sort(sort_me, array_sizes[x]); break;
          case 2 : comb_sort(sort_me, array_sizes[x]); break;
          case 3 : heap_sort(sort_me, array_sizes[x]); break;
          case 4 : selection_sort(sort_me, array_sizes[x]); break;
          default : std::cout << "Warning: no matching sort found in iteration " << iter << std::endl;
        }

        // Check sorted array
        bool result = check_sort(sort_me, array_sizes[x]);
        if (result == false) {std::cout << "Test " << iter+1 << " of " << algo_names[i] <<" failed" << std::endl;}
        else if (result == true && verbose_mode == true) {std::cout << "Test " << iter+1 << " of " << algo_names[i] << " passed" << std::endl;}
      }
      std::cout << "\t" <<  algo_names[i] << " tests complete" << std::endl;
    } // algorithm loop

    // Release memory used for arrays
    delete[] sort_me;
    delete[] working_space;

  } // number of array sizes loop
  return 1;
}