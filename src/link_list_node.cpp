#include <cstdint>
#include "../include/link_list_node.h"

//------------------------------------------------------------------------------
// link_list_node implementation
//------------------------------------------------------------------------------
// Constructor
link_list_node::link_list_node(uint32_t node_data, link_list_node * next_node, link_list_node * previous_node_node) {
  next_node     = next_node;
  previous_node = previous_node_node;
  node_data     = node_data;
}

// Get node data
uint32_t link_list_node::get_data() {
  return node_data;
}

// Set node data
void link_list_node::set_data(uint32_t data) {
  node_data = data;
}

// Get and set next and previous nodes
link_list_node * link_list_node::get_next_node() {
  return next_node;
}
link_list_node * link_list_node::get_previous_node() {
  return previous_node;
}
void link_list_node::set_next_node (link_list_node * next_node) {
  next_node = next_node;
}
void link_list_node::set_previous_node (link_list_node * previous_node) {
  previous_node = previous_node;
}