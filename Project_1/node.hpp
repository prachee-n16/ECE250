// Libraries
#include <iostream>
#include <string>

#pragma once

class Node
{
private:
    // Stores the value of Node
    double val;
    // Stores the name of Node
    std::string name;
    // Stores the next Node
    Node *next;

public:
    // Default Constructor
    Node();
    // Parameterized Constructor
    Node(std::string s, double n);
    // Destructor
    ~Node();

    // Setter and getter functions for each variable
    std::string get_name();
    double get_value();
    Node *get_next_node();

    void set_name(std::string s);
    void set_value(double num);
    void set_next_node(Node *next_node);
};
