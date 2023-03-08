#pragma once

#include "node.hpp"

// Libraries
#include <iostream>
#include <string>

class Trie {
    private:
        Node* root;
        int num_words;
    public:
        // Constructor and destructor
        Trie();
        ~Trie();

        void insert_word(std::string word);
        void print_trie();
        void print_trie_helper(Node* current, std::string word);

        void is_empty();
        void size();
};