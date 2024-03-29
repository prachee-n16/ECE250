#include "trie.hpp"
#include "node.hpp"

#include <iostream>
#include <string>

// Constructor
Trie::Trie()
{
    // Root of the binary tree
    root = new Node();
    // Number of words is 0
    num_words = 0;
};

// Destructor
Trie::~Trie()
{
    deleteTrie();
    delete root;
};

// Insert a word into tree
void Trie::insert_word(std::string word, std::string type)
{
    try {
        // If the word has a lower case letter
        for (int i = 0; i < word.length(); i++) {
            if (!(65 <= word[i] && word[i] <= 90)) {
                throw illegal_exception();
                return;
            }
        }

        // Go through the entire word
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
            // If already existing, 
            else
            {
                // Move to the next node
                current = children[int(word[i]) - 65];
            }
        }
        // If this was already a word
        if (current->is_end() == true)
        {
            if (type == "INSERT"){
            std::cout << "failure" << std::endl;
            }
        }
        else
        {
            // Make this the end of word
            // Add it to total count
            current->set_end(true);
            num_words++;
            if (type == "INSERT") {
                std::cout << "success" << std::endl;
            }
        }
    } catch (const illegal_exception &e)
    {
        std::cout << e.what() << std::endl;
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
        // check if word being entered is lower case
        for (int i = 0; i < word.length(); i++)
        {
            if (!(65 <= int(word[i]) && int(word[i]) <= 90))
            {
                throw illegal_exception();
            }
        }

        // if empty trie
        if (num_words == 0)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        Node *current = root;
        // find the last node with this word
        for (int i = 0; i < word.length(); i++)
        {
            Node **children = current->get_p_next();

            if (children[int(word[i]) - 65] == nullptr)
            {
                std::cout << "failure" << std::endl;
                return;
            }
            current = children[int(word[i]) - 65];
        }

        // current is now this end of word
        Node **children = current->get_p_next();

        // check if this is the end of a word
        if (current->is_end() == false)
        {
            std::cout << "failure" << std::endl;
            return;
        }

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

        current->set_end(false);
        Node *parent = current->get_p_prev();

        // if it's the case that there are nothing next,
        // work backwards and delete the nodes
        for (int i = word.size() - 1; i > 1; i--)
        {
            parent = current->get_p_prev();

            children = parent->get_p_next();

            children[int(word[i]) - 65] = nullptr;

            if (parent->is_end() == true) {
                std::cout << "success" << std::endl;
                num_words -= 1;
                delete current;
                current = nullptr;
                return;
            }

            for (int i = 0; i < 26; i++)
            {
                // if there is something next
                if (children[i] != nullptr)
                {
                    std::cout << "success" << std::endl;
                    num_words -= 1;
                    delete current;
                    current = nullptr;
                    return;
                }
            }
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
        std::cout << e.what() << std::endl;
    }
};

void Trie::deleteTrie()
{
    // Set current pointer to be root
    Node *current = root;
    // Set children here
    Node **children = current->get_p_next();

    // For loop where we go through every child
    for (int i = 0; i < 26; i++)
    {
        // If there is a non-null node
        if (children[i] != nullptr)
        {
            // Find it's children nodes and delete them
            deleteTrie_helper(children[i]);
            // Delete this child node
            delete children[i];
            children[i] = nullptr;
        }
    }
    // We have cleared trie so number of words = 0
    num_words = 0;
}

void Trie::deleteTrie_helper(Node *current)
{
    // Find child of given node
    Node **children = current->get_p_next();

    for (int i = 0; i < 26; i++)
    {
        // If this is non-null child
        if (children[i] != nullptr)
        {
            // Find it's children
            deleteTrie_helper(children[i]);
            // Delete this node
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

        for (int i = 0; i < prefix.length(); i++) {
            if (!(65 <= prefix[i] && prefix[i] <= 90)) {
                throw illegal_exception();
                return;
            }
        }

        for (int i = 0; i < prefix.length(); i++)
        {
            Node **children = current->get_p_next();
            
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
        std::cout << e.what() << std::endl;
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
    std::string prefix = "";

    for (int i = 0; i < word.length(); i++)
    {
        Node **children = current->get_p_next();
        // if the first letter is not in the trie
        if (children[int(word[i]) - 65] == nullptr && i == 0)
        {  
            std::cout << std::endl;
            return;
        } else if (children[int(word[i]) - 65] == nullptr) {
            // if we find a letter does not exist
            if (current->is_end() == true)
            {
                std::cout << prefix << " ";
            }
            print_trie_helper(current, prefix);
            std::cout << std::endl;
            return;
        }

        prefix += word[i];
        current = children[int(word[i]) - 65];
    }

    // on the last node check if word is in trie
    if (current->is_end() == true) {
        std::cout << "correct" << std::endl;
    } else {
        print_trie_helper(current, prefix);
        std::cout << std::endl;
    }
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