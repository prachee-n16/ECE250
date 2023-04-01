#include <iostream>
#include <string>
#include <fstream>

#include "graph.hpp"

using namespace std;

int main();

int main()
{
    // Store user's input command
    string command;
    Graph *powerGrid = new Graph();

    while (cin >> command)
    {
        if (command == "LOAD")
        {
            string fName;
            int n, a, b, w;
            cin >> fName;
            ifstream fin(fName.c_str()); // Note that we are using the variable as the filename
            fin >> n;

            while (fin >> a >> b >> w)
            {
                powerGrid->load_graph(a, b, w);
            }
            std::cout << "success" << std::endl;
        }
        else if (command == "INSERT")
        {
            int a, b, w;
            cin >> a >> b >> w;

            powerGrid->insert_edge(a, b, w);
        }
        else if (command == "PRINT")
        {
            int a;
            cin >> a;

            powerGrid->print_adj_edges(a);
        }
        else if (command == "DELETE")
        {
            int a;
            cin >> a;

            powerGrid->delete_node(a);
        }
        else if (command == "MST")
        {
            powerGrid->find_mst();
        }
        else if (command == "COST")
        {
            powerGrid->cost_mst();
        }
        else if (command == "END")
        {
            break;
        }
    }
    delete powerGrid;
}