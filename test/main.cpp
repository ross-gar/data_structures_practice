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
  // Variable and constant declarations
  //---------------------------------------------------------------
  // Define number of algorithmns to be tested and their names
  const int num_algos = 5;
  const std::string algo_names[num_algos] = {"merge sort", "bubble sort", "comb sort", "heap_sort", "selection_sort"};

  // Define number of test iterations
  const uint32_t number_iterations = 1000;
  
  // Switch to turn on verbose reporting of results
  const bool verbose_mode = false;

  // Array to be sorted and working space array
  uint32_t sort_me [array_size];
  uint32_t working_space [array_size];

  //---------------------------------------------------------------
  // Variable setup
  //---------------------------------------------------------------
  // Load arrays with 0s
  for (int i = 0; i <= (array_size-1); i++) {
    sort_me[i]       = 0x00000000;
    working_space[i] = 0x00000000;
  }

  // Instantiate random number generator
  rand_32bit_gen number_gen;
  // Loop through all LFSRs and load their initial states
  for (int i = 0; i <= (array_size-1); i++) {
    number_gen.load_state(initial_states[i], i);
  }

  //---------------------------------------------------------------
  // Main test loops
  //---------------------------------------------------------------
  // Test all algorithms
  for (int i = 0; i < num_algos; i++) {
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Running " << number_iterations << " tests of " << algo_names[i] << std::endl;

    // Perform sort and check loops
    for (int iter = 0 ; iter < number_iterations; iter++) {
      // Call function to get new pseudorandom values for sorting array
      randomize_data(sort_me, &number_gen, array_size);

      // Call appropriate sort function
      switch (i){
        case 0 : merge_sort(sort_me, working_space, array_size); break;
        case 1 : bubble_sort(sort_me, array_size); break;
        case 2 : comb_sort(sort_me, array_size); break;
        case 3 : heap_sort(sort_me, array_size); break;
        case 4 : selection_sort(sort_me, array_size); break;
        default : std::cout << "Warning: no matching sort found in iteration " << iter << std::endl;
      }

      // Check sorted array
      bool result = check_sort(sort_me, array_size);
      if (result == false) {std::cout << "Test " << iter+1 << " of " << algo_names[i] <<" failed" << std::endl;}
      else if (result == true && verbose_mode == true) {std::cout << "Test " << iter+1 << " of " << algo_names[i] << " passed" << std::endl;}
    }
    std::cout <<  algo_names[i] << " tests complete" << std::endl;
  }

  return 1;
}