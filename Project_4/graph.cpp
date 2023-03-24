#include <vector>
#include <tuple>
#include <iostream>
#include "graph.hpp"

// Constructor
Graph::Graph(){};
// Destructor
Graph::~Graph(){};

// Insert lots of nodes into graph
void Graph::load_graph(int a, int b, int w){};
// Insert node into graph
void Graph::insert_edge(int a, int b, int w){
    std::cout << a << b << w << std::endl;
};

// Print edges from one node
void Graph::print_adj_edges(int a){};
// Delete the node and related edges
void Graph::delete_node(int a){};
// Find minimum spanning tree
void Graph::find_mst(){};
// Cost of minimum spanning tree
void Graph::cost_mst(){};