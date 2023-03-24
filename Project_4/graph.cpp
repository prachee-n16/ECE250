#include <vector>
#include <tuple>
#include <iostream>
#include "graph.hpp"

// Constructor
Graph::Graph()
{
    adj_list = new std::vector<std::tuple<int, int>>[50000];
};
// Destructor
Graph::~Graph()
{
    delete[] adj_list;
};

// Insert lots of nodes into graph
void Graph::load_graph(int a, int b, int w){};

// Insert node into graph
void Graph::insert_edge(int a, int b, int w)
{
    // Check if this edge is in the graph
    // We only need to check one node

    // If there are no adjacent nodes
    if (adj_list[a].size() != 0 || adj_list[b].size() != 0)
    {
        // Check which list has fewer adjacent nodes
        if (adj_list[a].size() >= adj_list[b].size())
        {
            for (int i = 0; i < adj_list[b].size(); i++)
            {
                if (std::get<0>(adj_list[b][i]) == a) {
                    std::cout << "failure" << std::endl;
                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < adj_list[a].size(); i++)
            {
                if (std::get<0>(adj_list[a][i]) == b) {
                    std::cout << "failure" << std::endl;
                    return;
                }
            }
        }
    }

    // Two edges to insert into the vector!

    // Consider a as the source node
    // Consider b as the destination node
    // The edge tuple is
    std::tuple<int, int> edge = std::make_tuple(b, w);
    adj_list[a].push_back(edge);

    // Consider b as the source node
    // Consider a as the destination node
    // The edge tuple is
    edge = std::make_tuple(a, w);
    adj_list[b].push_back(edge);
    std::cout << "success" << std::endl;
};

// Print edges from one node
void Graph::print_adj_edges(int a){
    if (adj_list[a].size() == 0) {
        std::cout << "failure" << std::endl;
        return;
    }

    for (int i = 0; i < adj_list[a].size(); i++) {
        int b = std::get<0>(adj_list[a][i]);
        std::cout << b << " ";
    }
    std::cout << std::endl;
};

// Delete the node and related edges
void Graph::delete_node(int a){
    if (adj_list[a].size() == 0) {
        std::cout << "failure" << std::endl;
        return;
    }
    
    // For all adjacent nodes
    for (int i = adj_list[a].size() - 1; i >= 0; i--) { 
        int b = std::get<0>(adj_list[a][i]);

        // Remove a from adjacent list of adjacent node
        for (int j = 0; j < adj_list[b].size(); j++) {
            // Find a
            if (std::get<0>(adj_list[b][j]) == a) {
                adj_list[b].erase(adj_list[b].begin() + j);
                j = adj_list[b].size();
            }
        }
        // Remove from adjacent list of a
        adj_list[a].erase(adj_list[a].begin() + i);
    }
    
    std::cout << "success" << std::endl;
};

// Find minimum spanning tree
void Graph::find_mst(){
    //Kruskal I suppose?
    
};

// Cost of minimum spanning tree
void Graph::cost_mst(){

};