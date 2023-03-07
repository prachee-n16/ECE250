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
                // Insert word here!
            }
            words.close();
            cout << "success" << endl;

        } else if (command == "i") {
            string word;
            std::cin >> word;
            
            spellchecker.insert_word(word);
        } else if (command == "c") {

        } else if (command == "e") {

        } else if (command == "p") {
            spellchecker.print_trie();
        } else if (command == "spellcheck") {

        } else if (command == "empty") {

        } else if (command == "clear") {

        } else if (command == "size") {

        } else if (command == "exit") {
            break;
        }
    }
}