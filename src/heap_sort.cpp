#include <cstdint>
#include <stdexcept>
#include <iostream>

/*
  heapify size argument is total size of heap array, index is the parent node (0 based)
*/
template <typename T>
void heapify(T *data_array, uint32_t size, uint32_t index) {
  // Throw exception if size has an invalid value
  if (size <= 0) { throw std::invalid_argument("heapify called with size of 0"); }

  // Compute indices for right and left children
  uint32_t left_child  = 2*index + 1;
  uint32_t right_child = 2*index + 2;

  //std::cout << "heapfiy called with index " << index << "; right child " << right_child << "; left child " << left_child << std::endl;

  // Only call heapify on children if their indices actually exist. Compare to
  // size-1 because size is not 0 based.
  if (left_child  <= (size-1)) { heapify(data_array, size, left_child ); }
  if (right_child <= (size-1)) { heapify(data_array, size, right_child); }

  // Now the children have been heaped (if they exist), now make sure the max value is at the parent.
  // Check if left child is valid and is larger than parent.
  if (left_child <= (size-1) && *(data_array + left_child) < *(data_array + index)) {
    // Swap left child and parent
    uint32_t temp              = *(data_array + index);
    *(data_array + index)      = *(data_array + left_child);
    *(data_array + left_child) = temp;
  }
  // Check if left child is valid and is larger than parent.
  if (right_child <= (size-1) && *(data_array + right_child) < *(data_array + index)) {
    // Swap right child and parent
    uint32_t temp              = *(data_array + index);
    *(data_array + index)      = *(data_array + right_child);
    *(data_array + right_child) = temp;
  }
  return;
}

template <typename T>
void heap_sort(T *data_array, uint32_t size) {
  // Throw exception if size has an invalid value
  if (size <= 0) { throw std::invalid_argument("heap_sort called with size of 0"); }
  
  // Need to call heapify (size-1) times
  for (int i=0; i < (size-1); i++) {
    heapify(data_array+i, size-i, 0);
  }
  return;
}