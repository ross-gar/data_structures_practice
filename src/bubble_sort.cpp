#include <cstdint>
#include <stdexcept>
#include <iostream>

/*
  Simple bubble sort. Loops through array and swaps adjacent elements
  repeatedly until the array is sorted.
*/
template <typename T>
void bubble_sort(T *data_array, uint32_t size) {
    // Throw exception if size has an invalid value
    if (size <= 0) { throw std::invalid_argument("bubble_sort called with size of 0"); }
    // Boolean which tracks if two elements have been swapped on the current iteration
    bool element_swapped = false;
    // Sort done
    bool sort_done = false;
    // Temporary storage for swapping of elements of type T
    T temp;
    while (sort_done == false) {
        element_swapped = false;
        // Iterate through elements 0 to size-2
        for (int i = 0; i<= (size-2); i++) {
            // Lower index value is higher than higher index value, need to be swapped
            if ( *(data_array + i) > *(data_array + i + 1) ) {
                element_swapped = true;
                // Swap two elements
                temp = *(data_array + i + 1);
                *(data_array + i + 1) = *(data_array + i);
                *(data_array + i) = temp;
            }
        }
        // If no elements were swapped on the last pass through the array, sort is done
        if (element_swapped == false) {sort_done = true;}
    }
    return;
}