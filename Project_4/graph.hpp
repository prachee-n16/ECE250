#pragma once

#include <vector>
#include <tuple>

class Graph {
    private:
        // Adjacency-list representation
        std::vector<std::tuple<int, int>> *adj_list;

    public:
        // Constructor
        Graph();
        // Destructor
        ~Graph();

        //Insert lots of nodes into graph
        void load_graph(int a, int b, int w);
        //Insert node into graph
        void insert_edge(int a, int b, int w);
        //Print edges from one node
        void print_adj_edges(int a);
        //Delete the node and related edges
        void delete_node(int a);
        //Find minimum spanning tree
        void find_mst();
        //Cost of minimum spanning tree
        void cost_mst();
};