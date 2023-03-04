#include "node.hpp"

Node::Node(){};
Node::~Node(){};

void Node::set_letter(std::string s){
    letter = s;
};
void Node::set_p_prev(Node *p){
    p_prev = p;
};
void Node::set_p_next(Node *p){
    p_next = p;
};

std::string Node::get_letter(){
    return letter;
};
Node* Node::get_p_prev(){
    return p_prev;
};
Node* Node::get_p_next(){
    return p_next;
};