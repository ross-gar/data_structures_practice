#include <cstdint>

//------------------------------------------------------------------------------
// Class Definitions
//------------------------------------------------------------------------------
// Linked list node class
// template <class T>
class link_list_node {
    private:
    // Data at this node
    uint32_t node_data;
    // Pointers to the previous and next nodes
    link_list_node * next_node;
    link_list_node * previous_node;

    // Public Functions
    public:
    // Constructor defaults to 0 node data and null next and previous node pointers
    link_list_node(uint32_t node_data = 0, link_list_node * next_node = 0, link_list_node * previous_node_node = 0);
    // Get and set data functions
    uint32_t get_data();
    void set_data(uint32_t data);
    // Get and set next and previous nodes
    link_list_node * get_next_node();
    link_list_node * get_previous_node();
    void set_next_node (link_list_node * next_node);
    void set_previous_node (link_list_node * previous_node);
};

