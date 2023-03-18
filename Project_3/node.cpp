// Libraries
#include <iostream>
#include <string>
#include <vector>

#include "node.hpp"

Node::Node()
{
    p_prev = nullptr;
    letter = '\0';
    eow = false;
};

void Node::set_letter(char s)
{
    letter = s;
};

void Node::set_end(bool end)
{
    eow = end;
};

void Node::set_p_prev(Node *p)
{
    p_prev = p;
};

void Node::set_p_next(Node *p)
{
    p_next[int(p->get_letter()) - 65] = p;
};

char Node::get_letter()
{
    return letter;
};
Node *Node::get_p_prev()
{
    return p_prev;
};

Node **Node::get_p_next()
{
    return p_next;
};

bool Node::is_end()
{
    return eow;
}