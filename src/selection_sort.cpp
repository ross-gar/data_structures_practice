#include <cstdint>
#include <stdexcept>
#include <iostream>

/*

*/
template <typename T>
void selection_sort(T *data_array, uint32_t size) {
    // Throw exception if size has an invalid value
    if (size <= 0) { throw std::invalid_argument("selection_sort called with size of 0"); }

    // Smallest number and its index
    T smallest_num;
    uint32_t smallest_num_idx;

    // Need to sort size-1 elements (the last remaining unsorted element does not need to be sorted)
    for (int i=0; i<=(size-2); i++) {

      // Initialize smallest number to the lowest unsorted index
      smallest_num     = *(data_array + i);
      smallest_num_idx = i;

      // Search through the unsorted indeces and find the smallest one
      for (int j=i; j <= (size-1); j++) {
        // Look for a smaller number and record it and its index if one is found
        if ( *(data_array + j) < smallest_num ) {
          smallest_num     = *(data_array + j);
          smallest_num_idx = j;
        }
      }

      // Move the smallest number to the front of the unsorted array section
      *(data_array + smallest_num_idx) = *(data_array + i);
      *(data_array + i)       = smallest_num;
    }
    return;
}