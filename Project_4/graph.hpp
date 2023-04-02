#pragma once

#include <vector>
#include <tuple>

class Graph {
    private:
        // Adjacency-list representation
        // a b w
        std::vector<std::tuple<int, int, int>> *adj_list;
        // Priority Queue
        std::vector<std::tuple<int, int, int>> Q;
        // Stores a cached value of the mst
        int costMST = -1;
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
        // Find the cost of MST
        void cost_mst();

        void heap_sort(std::vector<std::tuple<int, int, int>> p);
        void heapify(std::vector<std::tuple<int, int, int>> &q, int n, int i);
};

// Illegal exception class
class illegal_exception : public std::exception {
    public:
        const char* what() const noexcept override {
            return "illegal argument";
        };
};