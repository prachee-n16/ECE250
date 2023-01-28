// Libraries
#include <iostream>
#include <string>

#include "node.hpp"

// Parametrised Constructor
Node::Node(std::string s, double n)
{
    name = s;
    val = n;
    p_next = nullptr;
}

Node::~Node() {
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
    return p_next;
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
    p_next = next_node;
};