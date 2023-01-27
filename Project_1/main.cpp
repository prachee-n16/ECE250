// Libraries
#include <iostream>
#include <string>

#include "calculator.hpp"
#include "node.hpp"

int main();

int main()
{
    // Stores user's input command
    std::string command;
    // Calculator instance
    Calculator *calculator;

    while (std::cin >> command)
    {
        // First command to run always!
        if (command == "CRT")
        {
            int size;
            std::cin >> size;
            calculator = new Calculator(size);
        }
        else if (command == "DEF")
        {
            std::string name;
            double value;

            std::cin >> name;
            std::cin >> value;
            calculator->insert_node(name, value);
        }
        else if (command == "ADD")
        {
            std::string x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            calculator->arithmetic_op_nodes(x, y, z, "ADD");
        }
        else if (command == "SUB")
        {
            std::string x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            calculator->arithmetic_op_nodes(x, y, z, "SUB");
        }
        else if (command == "REM")
        {
            std::string name;

            std::cin >> name;

            calculator->remove_node(name);
        }
        else if (command == "PRT")
        {
            std::string name;

            std::cin >> name;

            calculator->print_node_value(name);
        }
        else if (command == "END")
        {
            break;
        }
    }

    delete calculator;
}