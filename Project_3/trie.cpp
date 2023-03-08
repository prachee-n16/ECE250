#include "trie.hpp"
#include "node.hpp"

// Libraries
#include <iostream>
#include <string>

Trie::Trie()
{
    // Root of the binary tree
    root = new Node();
};

Trie::~Trie(){

};

void Trie::insert_word(std::string word)
{
    Node *current = root;
    for (int i = 0; i < word.length(); i++)
    {
        Node **children = current->get_p_next();
        // New node being added to the tree
        if (children[int(word[i])-65] == nullptr)
        {
            Node *next = new Node();
            next->set_letter(word[i]);
            next->set_p_prev(current);
            current->set_p_next(next);
            current = next;
        } else {
            current = children[int(word[i])-65];
        }
    }
    current->set_end();
    num_words++;
};

// Recursive DFS search
void Trie::print_trie()
{
    Node *current = root;
    Node **children = current->get_p_next();
    std::string word = "";

    // Take the root and go through 26 letters
    for (int i = 0; i < 26; i++)
    {
        // if one of the letter is there
        if (children[i] != nullptr)
        {
            word = children[i]->get_letter();
            // Check children and the word we are working on
            print_trie_helper(children[i], word);
            word.pop_back();
        }
    }
    std::cout << std::endl;
}

void Trie::print_trie_helper(Node *current, std::string word)
{
    Node **children = current->get_p_next();
    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            word += children[i]->get_letter();
            if (children[i]->is_end() == true)
            {
                std::cout << word << " ";
            }
            print_trie_helper(children[i], word);
            word.pop_back();
        }
    }
}

void Trie::is_empty() {
    if (num_words == 0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

void Trie::size() {
    std::cout << num_words << std::endl;
}