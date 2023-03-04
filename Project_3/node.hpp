// Libraries
#include <iostream>
#include <string>

using namespace std;

#pragma once

class Node {
    private:
        // Stores the parent of the node
        Node *p_prev;
        // Stores the child of the node
        Node *p_next;
        // Stores the value (letter) at this node
        std::string letter;

    public:
        // Getter and setter functions for private variables
        Node();
        ~Node();

        void set_letter(std::string s);
        void set_p_prev(Node *p);
        void set_p_next(Node *p);

        std::string get_letter();
        Node* get_p_prev();
        Node* get_p_next();
};