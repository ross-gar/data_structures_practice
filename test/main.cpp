//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdint>
#include "../include/test_utils.h"
// Include sort sources files here because they are template functions
#include "../src/merge_sort.cpp"
#include "../src/bubble_sort.cpp"
#include "../src/comb_sort.cpp"

//------------------------------------------------------------------------------
// Main test function
//------------------------------------------------------------------------------
int main() {
  // Switch to turn on verbose reporting of results
  const bool verbose_mode = false;

  // Array to be sorted and working space array
  uint32_t sort_me [array_size];
  uint32_t working_space [array_size];
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

  // Main test loops
  const uint32_t number_iterations = 1000;
  //---------------------------------------------------------------
  // Merge Sort Test
  //---------------------------------------------------------------
  std::cout << "Running " << number_iterations << " tests of merge_sort" << std::endl;
  for (int i=0 ; i <= (number_iterations-1); i++) {
    if (verbose_mode == true) { std::cout << "Running merge sort iteration " << i+1 << " ... "; }

    // Call function to get new pseudorandom values for sorting array
    randomize_data(sort_me, &number_gen, array_size);

    // Call merge sort function
    merge_sort(sort_me, working_space, array_size);

    // Check sorted array
    bool result = check_sort(sort_me, array_size);
    if (result == false) {std::cout << "Test " << i+1 << " failed" << std::endl;}
    else if (result == true && verbose_mode == true) {std::cout << "Test " << i+1 << " passed" << std::endl;}
  }
  std::cout << "merge_sort tests complete" << std::endl;

  //---------------------------------------------------------------
  // Bubble Sort Test
  //---------------------------------------------------------------
  std::cout << "Running " << number_iterations << " tests of bubble_sort" << std::endl;
  for (int i=0 ; i <= (number_iterations-1); i++) {
    if (verbose_mode == true) { std::cout << "Running bubble_sort iteration " << i+1 << " ... "; }

    // Call function to get new pseudorandom values for sorting array
    randomize_data(sort_me, &number_gen, array_size);

    // Call bubble sort function
    bubble_sort(sort_me, array_size);

    // Check sorted array
    bool result = check_sort(sort_me, array_size);
    if (result == false) {std::cout << "Test " << i+1 << " failed" << std::endl;}
    else if (result == true && verbose_mode == true) {std::cout << "Test " << i+1 << " passed" << std::endl;}
  }
  std::cout << "bubble_sort tests complete" << std::endl;

  //---------------------------------------------------------------
  // Comb Sort Test
  //---------------------------------------------------------------
  std::cout << "Running " << number_iterations << " tests of comb_sort" << std::endl;
  for (int i=0 ; i <= (number_iterations-1); i++) {
    if (verbose_mode == true) { std::cout << "Running comb_sort iteration " << i+1 << " ... "; }

    // Call function to get new pseudorandom values for sorting array
    randomize_data(sort_me, &number_gen, array_size);

    // Call comb sort function
    comb_sort(sort_me, array_size);

    // Check sorted array
    bool result = check_sort(sort_me, array_size);
    if (result == false) {std::cout << "Test " << i+1 << " failed" << std::endl;}
    else if (result == true && verbose_mode == true) {std::cout << "Test " << i+1 << " passed" << std::endl;}
  }
  std::cout << "comb_sort tests complete" << std::endl;

  return 1;
}