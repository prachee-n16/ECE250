#include "trie.hpp"
#include "node.hpp"

// Libraries
#include <iostream>
#include <string>

Trie::Trie()
{
    // Root of the binary tree
    root = new Node();
    num_words = 0;
};

Trie::~Trie()
{
    deleteTrie();
    delete root;
};

void Trie::insert_word(std::string word)
{
    try
    {
        Node *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            Node **children = current->get_p_next();
            // New node being added to the tree
            if (children[int(word[i]) - 65] == nullptr)
            {
                Node *next = new Node();
                next->set_letter(word[i]);
                next->set_p_prev(current);
                current->set_p_next(next);
                current = next;
            }
            else
            {
                current = children[int(word[i]) - 65];
            }
        }
        if (current->is_end() == true)
        {
            std::cout << "failure" << std::endl;
        }
        else
        {
            current->set_end(true);
            num_words++;
            std::cout << "success" << std::endl;
        }
    }
    catch (const illegal_exception &e)
    {
    }
};

void Trie::load_file(std::string word)
{
    try
    {
        Node *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            Node **children = current->get_p_next();
            // New node being added to the tree
            if (children[int(word[i]) - 65] == nullptr)
            {
                Node *next = new Node();
                next->set_letter(word[i]);
                next->set_p_prev(current);
                current->set_p_next(next);
                current = next;
            }
            else
            {
                current = children[int(word[i]) - 65];
            }
        }
        if (current->is_end() == false)
        {
            current->set_end(true);
            num_words++;
        }
    }
    catch (const illegal_exception &e)
    {
    }
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
            if (children[i]->is_end() == true)
            {
                std::cout << word << " ";
            }
            // Check children and the word we are working on
            print_trie_helper(children[i], word);
            word.pop_back();
        }
    }
    if (num_words != 0)
    {
        std::cout << std::endl;
    }
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

void Trie::deleteWord(std::string word)
{
    try
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (!(65 <= int(word[i]) && int(word[i]) <= 90))
            {
                throw illegal_exception();
            }
        }
        if (num_words == 0)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        Node *current = root;

        for (int i = 0; i < word.length(); i++)
        {
            Node **children = current->get_p_next();

            if (children[int(word[i]) - 65] == nullptr)
            {
                std::cout << "failure" << std::endl;
                num_words -= 1;
                return;
            }
            current = children[int(word[i]) - 65];
        }

        Node **children = current->get_p_next();

        // so check if there's any thing next
        for (int i = 0; i < 26; i++)
        {
            // if there is something next
            if (children[i] != nullptr)
            {
                // just delete this stop here
                current->set_end(false);
                std::cout << "success" << std::endl;
                num_words -= 1;
                return;
            }
        }

        // if it's the case that there are nothing next,
        // work backwards and delete the nodes
        for (int i = 1; i < word.size(); i++)
        {
            Node *parent = current->get_p_prev();
            delete current;
            current = parent;
        }
        children = current->get_p_next();
        children[int(word[1]) - 65] = nullptr;

        std::cout << "success" << std::endl;
        num_words -= 1;
    }
    catch (const illegal_exception &e)
    {
    }
};

void Trie::deleteTrie()
{
    Node *current = root;
    Node **children = current->get_p_next();

    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            deleteTrie_helper(children[i]);
            delete children[i];
            children[i] = nullptr;
        }
    }
    num_words = 0;
}

void Trie::deleteTrie_helper(Node *current)
{
    Node **children = current->get_p_next();

    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            if (children[i]->is_end() == true)
            {
                break;
            }
            deleteTrie_helper(children[i]);
            delete children[i];
            children[i] = nullptr;
        }
    }
}

void Trie::getWordCountWithPrefix(std::string prefix)
{
    try
    {
        Node *current = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            Node **children = current->get_p_next();
            if (!(65 <= int(prefix[i]) && int(prefix[i]) <= 90))
            {
                throw illegal_exception();
            }
            if (children[int(prefix[i]) - 65] == nullptr)
            {
                // no prefix there
                std::cout << "not found" << std::endl;
                return;
            }
            current = children[int(prefix[i]) - 65];
        }

        int count = 0;
        if (current->is_end() == true)
            count++;
        getWordCountWithPrefixhelper(current, &count);
        std::cout << "count is " << count << std::endl;
    }
    catch (const illegal_exception &e)
    {
    }
};

void Trie::getWordCountWithPrefixhelper(Node *current, int *count)
{
    Node **children = current->get_p_next();
    for (int i = 0; i < 26; i++)
    {
        if (children[i] != nullptr)
        {
            if (children[i]->is_end() == true)
            {
                (*count)++;
            }
            getWordCountWithPrefixhelper(children[i], count);
        }
    }
}

void Trie::spellcheckTrie(std::string word)
{
    Node *current = root;
    // check if word is there
    for (int i = 0; i < word.length(); i++)
    {
        Node **children = current->get_p_next();
        if (children[int(word[i]) - 65] == nullptr)
        {
            // no prefix there
            std::cout << std::endl;
            return;
        }
        current = children[int(word[i]) - 65];
    }

    if (current->is_end() == true)
    {
        std::cout << "correct" << std::endl;
        return;
    }

    
    print_trie_helper(current, word);
    
    std::cout << std::endl;
}

void Trie::is_empty()
{
    if (num_words == 0)
    {
        std::cout << "empty " << 1 << std::endl;
    }
    else
    {
        std::cout << "empty " << 0 << std::endl;
    }
}

void Trie::size()
{
    std::cout << "number of words is " << num_words << std::endl;
}