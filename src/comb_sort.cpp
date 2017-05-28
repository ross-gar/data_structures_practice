#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <math.h>
/*
  Comb sort is a generalized bubble sort where the spread between the two
  compared elements is variable.
*/
template <typename T>
void comb_sort(T *data_array, uint32_t size, double shrink_factor = 1.3) {
    // Throw exception if size has an invalid value
    if (size <= 0) { throw std::invalid_argument("comb_sort called with size of 0"); }
    // Boolean which tracks if two elements have been swapped on the current iteration
    bool element_swapped = false;
    // Sort done
    bool sort_done = false;
    // Temporary storage for swapping of elements of type T
    T temp;
    // Comb spread
    uint32_t spread = size;

    while (sort_done == false) {
        element_swapped = false;
        spread = floor(spread/shrink_factor); // Compute new spread rounded down to nearest integer.
        if (spread == 0) { spread = 1; } // Don't allow spreads of 0
        //std::cout << "Starting comb with spread: " << spread << std::endl;
        // Iterate through elements 0 to size-1-spread
        for (int i = 0; i<= (size-1-spread); i++) {
            // Lower index value is higher than higher index value, need to be swapped
            if ( *(data_array + i) > *(data_array + i + spread) ) {
                element_swapped = true;
                // Swap two elements
                temp = *(data_array + i + spread);
                *(data_array + i + spread) = *(data_array + i);
                *(data_array + i) = temp;
            }
        }
        // If no elements were swapped on a pass through the array when the spread is 1, sort is done
        if (element_swapped == false && spread == 1) {sort_done = true;}
    }
    return;
}
