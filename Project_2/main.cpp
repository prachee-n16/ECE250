// Libraries
#include <iostream>
#include <string>

#include "OpenAddressedHT.hpp"
#include "SeparateChainingHT.hpp"

int main();

int main()
{
    // Stores user's input command
    std::string command;
    // Stores and checks if it's OPEN or ORDERED
    std::string hash_type;

    // OpenAddressed hash table instance
    if (hash_type == "OPEN")
    {
        OpenAddressedHT *hashtable;

        while (std::cin >> command)
        {
            if (command == "M")
            {
                int memory_size;
                int page_size;
                std::cin >> memory_size >> page_size;
                hashtable = new OpenAddressedHT(memory_size, page_size);
            }
            else if (command == "INSERT")
            {
                int PID;
                std::cin >> PID;
                hashtable->insert_PID(PID);
            }
            else if (command == "SEARCH")
            {
                int PID;
                std::cin >> PID;
                hashtable->search_PID(PID);
            }
            else if (command == "WRITE")
            {
                int PID;
                int ADDRESS;
                int value;
                std::cin >> PID >> ADDRESS >> value;
                hashtable->write_PID(PID, ADDRESS, value);
            }
            else if (command == "READ")
            {
                int PID;
                int ADDRESS;
                std::cin >> PID >> ADDRESS;
                hashtable->read_PID(PID, ADDRESS);
            }
            else if (command == "DELETE")
            {
                int PID;
                std::cin >> PID;
                hashtable->delete_PID(PID);
            }
            else if (command == "END")
            {
                break;
            }
        }
        delete hashtable;
    }

    if (hash_type == "ORDERED")
    {
        SeparateChainingHT* ordered_hashtable;
        while (std::cin >> command)
        {
            if (command == "M")
            {
                int memory_size;
                int page_size;
                std::cin >> memory_size >> page_size;
                ordered_hashtable = new SeparateChainingHT(memory_size, page_size);
            }
            else if (command == "INSERT")
            {
                int PID;
                std::cin >> PID;
                ordered_hashtable->insert_PID(PID);
            }
            else if (command == "SEARCH")
            {
                int PID;
                std::cin >> PID;
                ordered_hashtable->search_PID(PID);
            }
            else if (command == "WRITE")
            {
                int PID;
                int ADDRESS;
                int value;
                std::cin >> PID >> ADDRESS >> value;
                ordered_hashtable->write_PID(PID, ADDRESS, value);
            }
            else if (command == "READ")
            {
                int PID;
                int ADDRESS;
                std::cin >> PID >> ADDRESS;
                ordered_hashtable->read_PID(PID, ADDRESS);
            }
            else if (command == "DELETE")
            {
                int PID;
                std::cin >> PID;
                ordered_hashtable->delete_PID(PID);
            }
            else if (command == "END")
            {
                break;
            }
        }
        delete ordered_hashtable;
    }
}