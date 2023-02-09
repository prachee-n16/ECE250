// Libraries
#include <iostream>
#include <string>

#include "OpenAddressedHT.hpp"

int main();

int main()
{
    // Stores user's input command
    std::string command;

    // Check to see if it's OPEN or ORDERED
    //TODO: Currently operating under the assumption everything is open addressing

    //OpenAddressed hash table instance
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