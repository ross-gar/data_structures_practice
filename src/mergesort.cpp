#include <cstdint>
#include <stdexcept>
#include <iostream>

/*
    Example input array:
    [10 23 5 8 72 24 35]
    where the provided pointer points to the first element (10) at address x1000.
    We want to call the merge_sort function recursively on the following two sub arrays:
    A: [10 23 5 8] size of 4, address x1000
    B: [72 24 35]  size of 3, address x1004
    Thus, the B address is (A address) + (A size)
    The two recursive calls should return with the A and B arrays as follows:
    A: [5 8 10 23]
    B: [24 35 72]
    To combine them we need to recombine the two sub arrays by looping through every
    element of the original input array (7 elements).
    

*/
void merge_sort(uint32_t *data_array, uint32_t *working_array, uint32_t size) {
    //std::cout << "Merge sort called with size of: " << size << std::endl;
    // Throw exception if size has an invalid value
    if (size <= 0) { throw std::invalid_argument("merge_sort called with size of 0"); }
    // Only need to do sorting if size is greater than 1
    if (size > 1) {
        // Size of sub arrays
        uint32_t size_a, size_b = 0;
        // Counters used when recombining the sub arrays
        uint32_t idx_a, idx_b = 0;
        // Check if size is even
        if (size % 2 == 0) {
            // Since size is even, both sub array sizes will be size/2;
            size_a = size/2;
            size_b = size/2;
        }
        else {
            // If odd, one will have (size-1)/2, and the other will have (size+1)/2
            size_a = (size-1)/2;
            size_b = (size+1)/2;
        }
        // Call merge sort on sub arrays
        merge_sort( data_array       , working_array       , size_a);
        merge_sort( data_array+size_a, working_array+size_a, size_b);
        
        // Recombine the sorted sub arrays
        for (int i = 0; i<= (size-1); i++) {
            // All elements of sub array A used, fill rest of array with B's elements
            if (idx_a = size_a-1) {
                *(working_array + i) = *(data_array + size_a + idx_b);
                idx_b ++;
            }
            // All elements of sub array B used, fill rest of array with A's elements
            else if (idx_b = size_b-1) {
                *(working_array + i) = *(data_array + idx_a);
                idx_a ++;
            }
            // Have elements of both sub arrays that still need to be used
            else {
                // sub array A's element is smaller than B's
                if ( *(data_array + idx_a) < *(data_array + size_a + idx_b) ) {
                    *(working_array + i) = *(data_array + idx_a);
                    idx_a ++;
                }
                // sub array B's element is less than or equal to A's
                else {
                    *(working_array + i) = *(data_array + size_a + idx_b);
                    idx_b ++;
                }
            }
        }
        
        // Done recombining sorted sub arrays, now need to move elements out of the working array memory
        // space and back into the data array
        for (int i = 0; i<= (size-1); i++) {
            *(data_array + i) = *(working_array + i);
        }
        return;
    }
    // Reached here if size is 1, no sorting needed.
    return;
}