#include <cstdint>

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------
const uint32_t array_size = 32;
const uint32_t initial_states [array_size] = {
    0x74345678, 0xad52345d, 0x12ff9372, 0x93847564, 0x3c284abc, 0x5f4a9d2c, 0x02d078ef, 0x29abef12,
    0x123ffa78, 0xafcb345d, 0x1a159372, 0x93fede64, 0xdc21237f, 0x54568d2c, 0x567078ef, 0x2a568f12,
    0xeef45678, 0xafff345d, 0x12ff7532, 0x12feed64, 0x123456fe, 0x5fefdd2c, 0x02d07ffe, 0x2345ef12,
    0x12fca678, 0xa123345d, 0x12a0a372, 0x9383dc64, 0xdc284abc, 0x5f4a9368, 0x021238ef, 0x2da67812
};
const uint32_t zero_array [array_size] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};
//------------------------------------------------------------------------------
// Function Definitions
//------------------------------------------------------------------------------
// Function for checking that an array has been sorted correctly
bool check_sort(uint32_t *data_array, uint32_t size);

//------------------------------------------------------------------------------
// Class Definitions
//------------------------------------------------------------------------------
// Class for generating random bits using a linear feedback shift register
class rand_lfsr {
    // Current LFSR state - 32 bit unsigned number
    uint32_t current_state;
    // Public Functions
    public:
    // Default constructor which sets the current state to 0
    rand_lfsr();
    // Constructor which takes a value to set the current value
    rand_lfsr(uint32_t init_val);
    // Load state of the LFSR with the given 32 bit unsigned value
    void load_state (uint32_t);
    // Shift LFSR and return the new state
    uint32_t shift_lfsr (void);
};

// Class for generating 32 bit random numbers using 32 LFSRs (linear feedback shift registers)
class rand_32bit_gen {
    // Array of 32 LFSRs
    rand_lfsr lfsr_array [32];
    // Public Functions
    public:
    // Default constructor which sets all of the LFSR states to 0
    rand_32bit_gen();
    // Load state of the LFSR with the given 32 bit unsigned value
    void load_state (uint32_t new_state, uint32_t index);
    // Shift LFSR and return the new state
    uint32_t get_new_val (void);
};
