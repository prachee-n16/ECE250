#include <vector>
#include <tuple>
#include <iostream>

#include "graph.hpp"

// Constructor
Graph::Graph()
{
    adj_list = new std::vector<std::tuple<int, int, int>>[50001];
};

// Destructor
Graph::~Graph()
{
    delete[] adj_list;
};

// Insert lots of nodes into graph
void Graph::load_graph(int a, int b, int w){
    try {
        // illegal argument?
        if (a > 50000 || a <= 0) {
            throw illegal_exception();
        }
        if (b > 50000 || b <= 0) {
            throw illegal_exception();
        }
        if (w<= 0) {
            throw illegal_exception();
        }

        costMST = -1;

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
                    if (std::get<1>(adj_list[b][i]) == a)
                    {
                        return;
                    }
                }
            }
            else
            {
                for (int i = 0; i < adj_list[a].size(); i++)
                {
                    if (std::get<1>(adj_list[a][i]) == b)
                    {
                        return;
                    }
                }
            }
        }

        // Two edges to insert into the vector!

        // Consider a as the source node
        // Consider b as the destination node
        // The edge tuple is
        std::tuple<int, int, int> edge = std::make_tuple(a, b, w);
        adj_list[a].push_back(edge);

        // Consider b as the source node
        // Consider a as the destination node
        // The edge tuple is
        edge = std::make_tuple(b, a, w);
        adj_list[b].push_back(edge);
    } catch (const illegal_exception &e) {
        // We don't print here!
    }
};

// Insert node into graph
void Graph::insert_edge(int a, int b, int w)
{
    try {
        // Check if this edge is in the graph
        // We only need to check one node
        // illegal argument?
        if (a > 50000 || a <= 0) {
            throw illegal_exception();
        }
        if (b > 50000 || b <= 0) {
            throw illegal_exception();
        }
        if (w <= 0) {
            throw illegal_exception();
        }

        costMST = -1;

        // If there are no adjacent nodes
        if (adj_list[a].size() != 0 || adj_list[b].size() != 0)
        {
            // Check which list has fewer adjacent nodes
            if (adj_list[a].size() >= adj_list[b].size())
            {
                for (int i = 0; i < adj_list[b].size(); i++)
                {
                    if (std::get<1>(adj_list[b][i]) == a)
                    {
                        std::cout << "failure" << std::endl;
                        return;
                    }
                }
            }
            else
            {
                for (int i = 0; i < adj_list[a].size(); i++)
                {
                    if (std::get<1>(adj_list[a][i]) == b)
                    {
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
        std::tuple<int, int, int> edge = std::make_tuple(a, b, w);
        adj_list[a].push_back(edge);

        // Consider b as the source node
        // Consider a as the destination node
        // The edge tuple is
        edge = std::make_tuple(b, a, w);
        adj_list[b].push_back(edge);
        std::cout << "success" << std::endl;
    } catch (const illegal_exception &e) {
        std::cout << e.what() << std::endl;
    }
};

// Print edges from one node
void Graph::print_adj_edges(int a)
{
    try {
        if (a > 50000 || a <= 0) {
            throw illegal_exception();
        }

        if (adj_list[a].size() == 0)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        costMST = -1;

        for (int i = 0; i < adj_list[a].size(); i++)
        {
            int b = std::get<1>(adj_list[a][i]);
            std::cout << b << " ";
        }
        std::cout << std::endl;
    } catch (const illegal_exception &e) {
        std::cout << e.what() << std::endl;
    }
};

// Delete the node and related edges
void Graph::delete_node(int a)
{
    try {
        if (a > 50000 || a <= 0) {
            throw illegal_exception();
        }

        if (adj_list[a].size() == 0)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        costMST = -1;

        // For all adjacent nodes
        for (int i = adj_list[a].size() - 1; i >= 0; i--)
        {
            int b = std::get<1>(adj_list[a][i]);

            // Remove a from adjacent list of adjacent node
            for (int j = 0; j < adj_list[b].size(); j++)
            {
                // Find a
                if (std::get<1>(adj_list[b][j]) == a)
                {
                    adj_list[b].erase(adj_list[b].begin() + j);
                    j = adj_list[b].size();
                }
            }
            // Remove from adjacent list of a
            adj_list[a].erase(adj_list[a].begin() + i);
        }

        std::cout << "success" << std::endl;
    } catch (const illegal_exception &e) {
        std::cout << e.what() << std::endl;
    }
};

// Find minimum spanning tree
void Graph::find_mst()
{
    Q.clear();

    // Copy of the adjacent list to use
    std::vector<std::tuple<int, int, int>>* mst_adj_list = new std::vector<std::tuple<int, int, int>>[50001];
    // Store's MST
    // Store's MST
    int mst[50001]{0};
    int mst_size = 0;

    int n = 0;
    for (int i = 0; i < 50000; i++)
    {
        if (adj_list[i].size() != 0)
        {
            mst_adj_list[i] = adj_list[i];
            n++;
        }
    }

    if (n == 0 ){
        std::cout << "failure" << std::endl;
        delete[] mst_adj_list;
        return;
    }
    
    // Find a vertex in the graph
    for (int i = 0; i < 50000; i++)
    {
        if (!mst_adj_list[i].empty())
        {
            // get all of it's edges
            heap_sort(mst_adj_list[i]);
            break;
        }
    }

    int cost = 0;
    // this while loop is a joke rn for testing purposes
    while (mst_size != n || Q.size() == 0)
    {
        
        // Extract minimum from the queue
        std::tuple<int, int, int> u = Q[0];
        Q.erase(Q.begin());

        
        // If vertex has already been considered
        // Don't consider it
        // if both nodes are not already considered in MST
        
        int a_found = 0;
        int b_found = 0;
        
        if (mst[std::get<0>(u)] == 1) {
            a_found = 1;
        } 
        if (mst[std::get<1>(u)] == 1) {
            b_found = 1;
        } 

        if(a_found == 0) {
            mst[std::get<0>(u)] = 1;
            mst_size++;
        }
        if (b_found == 0) {
            mst[std::get<1>(u)] = 1;
            mst_size++;
        }
        if (a_found == 1) {
            if (b_found == 1) {
                continue;
            }
        }

        // Print out this edge being added to MST
        std::cout << std::get<0>(u) << " " << std::get<1>(u) << " " << std::get<2>(u) << " ";
        // Print out this edge being added to MST
        cost += std::get<2>(u);

        // Remove edge from list
        int a = std::get<0>(u);
        for (int i = 0; i < mst_adj_list[a].size(); i++) {
            if (std::get<1>(mst_adj_list[a][i]) == std::get<1>(u)) {
                mst_adj_list[a].erase(mst_adj_list[a].begin() + i);
                break;
            }
        }

        // Remove edge from adjacency list of other node
        int b = std::get<1>(u);
        for (int i = 0; i < mst_adj_list[b].size(); i++)
        {
            if (std::get<1>(mst_adj_list[b][i]) == std::get<0>(u))
            {
                mst_adj_list[b].erase(mst_adj_list[b].begin() + i);
                break;
            }
        }

        // Check if edge is in priority queue
        // If so, remove it
        if (mst_size != n){
            for (int i = 0; i < Q.size(); i++) {
                if (std::get<1>(Q[i]) == a && std::get<0>(Q[i]) == b) {
                    Q.erase(Q.begin() + i);
                }
            }
        }
        // Next, we take edges adjacent to b and add to Q
        heap_sort(mst_adj_list[std::get<1>(u)]);
    }
    delete[] mst_adj_list;
    costMST = cost;
    std::cout << std::endl;
};

void Graph::heap_sort(std::vector<std::tuple<int, int, int>> p)
{
    if (Q.size() == 0)
    {
        Q = p;
    }
    else
    {
        Q.insert(Q.end(), p.begin(), p.end());
    }

    // Let's build a heap first
    for (int i = (Q.size() / 2); i >= 0; i--)
    {
        heapify(Q, Q.size(), i);
    }

    // actual heap sort algorithm
    for (int i = Q.size() - 1; i >= 0; i--)
    {
        swap(Q[0], Q[i]);
        heapify(Q, i, 0);
    }
}

void Graph::heapify(std::vector<std::tuple<int, int, int>> &q, int n, int i)
{
    int minimum = i;
    int l = 2 * minimum + 1;
    int r = 2 * minimum + 2;

    if (l < n && std::get<2>(q[l]) > std::get<2>(q[minimum]))
    {
        minimum = l;
    }

    if (r < n && std::get<2>(q[r]) > std::get<2>(q[minimum]))
    {
        minimum = r;
    }

    if (minimum != i)
    {
        swap(q[i], q[minimum]);
        heapify(q, n, minimum);
    }
};


// Find minimum spanning tree
void Graph::cost_mst()
{
    Q.clear();

    // Copy of the adjacent list to use
    std::vector<std::tuple<int, int, int>>* mst_adj_list = new std::vector<std::tuple<int, int, int>>[50001];
    // Store's MST
    int mst[50001]{0};
    int mst_size = 0;

    int n = 0;
    for (int i = 0; i < 50000; i++)
    {
        if (adj_list[i].size() != 0)
        {
            mst_adj_list[i] = adj_list[i];
            n++;
        }
    }

    if (n == 0 ){
        std::cout << "cost is 0" << std::endl;
        delete[] mst_adj_list;
        return;
    }

    if (costMST > 0) {
        std::cout << "cost is " << costMST << std::endl;
        delete[] mst_adj_list;
        return;
    }

    // Find a vertex in the graph
    for (int i = 0; i < 50000; i++)
    {
        if (!mst_adj_list[i].empty())
        {
            // get all of it's edges
            heap_sort(mst_adj_list[i]);
            break;
        }
    }

    int cost = 0;
    // this while loop is a joke rn for testing purposes
    while (mst_size != n || Q.size() == 0)
    {
        // Extract minimum from the queue
        std::tuple<int, int, int> u = Q[0];
        Q.erase(Q.begin());
        
        // If vertex has already been considered
        // Don't consider it
        // if both nodes are not already considered in MST
        
        int a_found = 0;
        int b_found = 0;

        if (mst[std::get<0>(u)] == 1) {
            a_found = 1;
        } 
        if (mst[std::get<1>(u)] == 1) {
            b_found = 1;
        } 

        if(a_found == 0) {
            mst[std::get<0>(u)] = 1;
            mst_size++;
        }
        if (b_found == 0) {
            mst[std::get<1>(u)] = 1;
            mst_size++;
        }
        if (a_found == 1) {
            if (b_found == 1) {
                continue;
            }
        }

        // Print out this edge being added to MST
        cost += std::get<2>(u);

        // Remove edge from list
        int a = std::get<0>(u);
        for (int i = 0; i < mst_adj_list[a].size(); i++) {
            if (std::get<1>(mst_adj_list[a][i]) == std::get<1>(u)) {
                mst_adj_list[a].erase(mst_adj_list[a].begin() + i);
                break;
            }
        }

        // Remove edge from adjacency list of other node
        int b = std::get<1>(u);
        for (int i = 0; i < mst_adj_list[b].size(); i++)
        {
            if (std::get<1>(mst_adj_list[b][i]) == std::get<0>(u))
            {
                mst_adj_list[b].erase(mst_adj_list[b].begin() + i);
                break;
            }
        }

        // Check if edge is in priority queue
        // If so, remove it
        if (mst_size != n){
            for (int i = 0; i < Q.size(); i++) {
                if (std::get<1>(Q[i]) == a && std::get<0>(Q[i]) == b) {
                    Q.erase(Q.begin() + i);
                }
            }
        }
        // Next, we take edges adjacent to b and add to Q
        heap_sort(mst_adj_list[std::get<1>(u)]);
    }
    delete[] mst_adj_list;

    std::cout << "cost is " << cost << std::endl;
    costMST = cost;
}