// Libraries
#include <iostream>
#include <string>

#include "node.hpp"

#pragma once

// Class for calculator-based linked list
class Calculator
{
    // Private variables
private:
    // Size stores the max_size of array
    int max_size;
    // Stores current size of calculator
    int current_size;

    // FIXME: KILL MEMORY IN DESTRUCTOR
    // Stores the head of the linked list
    Node *head;

public:
    // Constructor
    Calculator(int n);

    // Destructor
    ~Calculator();

    // TODO: Find better function names (not a fan of these ones)
    // To be called for input command DEF
    void insert_node(std::string x, double val);

    // To be called for input command REM
    void remove_node(std::string x);

    // To be called for other function purposes
    Node *find_node(std::string x);

    // To be called for input command PRT
    void print_node_value(std::string x);

    // To be called for input command Add
    void add_nodes(std::string x, std::string y, std::string z);

    // To be called for input command SUB
    void sub_nodes(std::string x, std::string y, std::string z);
};