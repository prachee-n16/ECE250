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

        void insert_word(std::string word, std::string type);
        void print_trie();
        void print_trie_helper(Node* current, std::string word);

        void is_empty();
        void size();
        void getWordCountWithPrefix(std::string prefix);
        void getWordCountWithPrefixhelper(Node *current, int *count);

        void deleteWord(std::string word);
        void deleteTrie();
        void deleteTrie_helper(Node *current);

        void spellcheckTrie(std::string word);
};