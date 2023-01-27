// Libraries
#include <iostream>
#include <string>

#include "node.hpp"

Node::Node()
{
    val = 0;
    name = "";
    next = NULL;
}

// Parametrised Constructor
Node::Node(std::string s, double n)
{
    name = s;
    val = n;
    next = NULL;
}

Node::~Node() {
    delete next;
    next = nullptr;
}

// Setter and getter functions for each variable

// Getter functions for each variable
std::string Node::get_name()
{
    return name;
};
double Node::get_value()
{
    return val;
};
Node *Node::get_next_node()
{
    return next;
};

// Setter functions for each variable
void Node::set_name(std::string s)
{
    name = s;
};
void Node::set_value(double num)
{
    val = num;
};
void Node::set_next_node(Node *next_node)
{
    next = next_node;
};