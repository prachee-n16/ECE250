// Libraries
#include <iostream>
#include <string>
#include <vector>

#pragma once

class Node {
    private:
        // Stores the parent of the node
        Node *p_prev;
        // Stores the child of the node
        Node* p_next[26]{nullptr};
        // Stores the value (letter) at this node
        char letter;
        // Tells us whether it is the last letter of a word
        // End of word
        bool eow;

    public:
        // Getter and setter functions for private variables
        Node();
        ~Node();

        void set_letter(char s);
        void set_p_prev(Node *p);
        void set_p_next(Node *p);
        void set_end(bool end);

        char get_letter();
        Node* get_p_prev();
        Node** get_p_next();
        bool is_end();

        void reinitialize_node();
};

class illegal_exception : public std::exception {
    public:
        const char* what() const noexcept override {
            return "illegal argument";
        };
};