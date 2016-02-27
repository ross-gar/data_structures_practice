#include <cstdint>

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
