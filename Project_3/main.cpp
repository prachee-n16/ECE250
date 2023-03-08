#include "trie.hpp"
// Libraries
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
        if (command == "load") {
            while (words >> addWord) {
                spellchecker.load_file(addWord);
            }
            words.close();
            std::cout << "success" << std::endl;
        } else if (command == "i") {
            string word;
            std::cin >> word;
            
            spellchecker.insert_word(word);
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
        } else if (command == "size") {
            spellchecker.size();
        } else if (command == "exit") {
            break;
        }
    }
}