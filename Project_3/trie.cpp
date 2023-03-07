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
    /** TODO:
     *  Need to make sure that if I insert two same letters, both of them are not being added (m and m u know)
     *  Create print function to test this out
     */

    // Temp will store where we are when inserting letters
    Node *current = root;

    for (int i = 0; i < word.length(); i++)
    {
        // Check to see if we need to add node or does it already exist
        if (current->return_child(word[i]) == nullptr)
        {
            // Will store the next one!
            Node *next = new Node();
            next->set_letter(word[i]);
            next->set_p_prev(current);
            current->set_p_next(next);
            current = next;
        }
        else
        {
            // If this node already exists
            Node *next = current->return_child(word[i]);
            current->set_p_next(next);
            current = next;
        }
    }
    current->set_end();
};

// Recursive DFS search
void Trie::print_trie()
{
    // Temp will store where we are when inserting letters
    Node *current = root;
    Node **children = current->get_p_next();
    std::string word = "";

    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            std::cout << children[i]->get_letter();
            word = children[i]->get_letter();
            print_trie_helper(children[i], word);
            std::cout << std::endl;
        }
    }
}

void Trie::print_trie_helper(Node *current, std::string word)
{
    if (current->get_p_next() != nullptr)
    {
        Node **children = current->get_p_next();
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != nullptr)
            {
                word += children[i]->get_letter();

                std::cout << children[i]->get_letter();
                if (children[i]->get_end() == true)
                {
                    std::cout << word << " ";
                }
                print_trie_helper(children[i], word);
            }
        }
    };
    return;
}