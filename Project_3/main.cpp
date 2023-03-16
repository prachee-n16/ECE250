#include "trie.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main();

int main() {
    // The trie structure
    Trie spellchecker;

    // Store user's input command
    string command;
    // Text file
    ifstream words("corpus.txt");

    // Store word from text file
    string addWord;

    while (cin >> command) {
        // Load words from a file
        if (command == "load") {
            while (words >> addWord) {
                spellchecker.insert_word(addWord, "LOAD");
            }
            words.close();
            std::cout << "success" << std::endl;
        } else if (command == "i") {
            string word;
            std::cin >> word;
            
            spellchecker.insert_word(word, "INSERT");
        } else if (command == "c") {
            string prefix;
            std::cin >> prefix;

            spellchecker.getWordCountWithPrefix(prefix);
        } else if (command == "e") {
            string word;
            std::cin >> word;

            spellchecker.deleteWord(word);
        } else if (command == "p") {
            spellchecker.print_trie();
        } else if (command == "spellcheck") {
            string word;
            std::cin >> word;
            
            spellchecker.spellcheckTrie(word);
        } else if (command == "empty") {
            spellchecker.is_empty();
        } else if (command == "clear") {
            spellchecker.deleteTrie();
            std::cout << "success" << std::endl;
        } else if (command == "size") {
            spellchecker.size();
        } else if (command == "exit") {
            break;
        }
    }
}