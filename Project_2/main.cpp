// Libraries
#include <iostream>
#include <string>

int main();

int main()
{
    // Stores user's input command
    std::string command;

    // Check to see if it's OPEN or ORDERED

    while (std::cin >> command)
    {
        if (command == "M")
        {
            int memory_size;
            int page_size;
            std::cin >> memory_size >> page_size;
        }
        else if (command == "INSERT")
        {
            int PID;
            std::cin >> PID;
        }
        else if (command == "SEARCH")
        {
            int PID;
            std::cin >> PID;
        }
        else if (command == "WRITE")
        {
            int PID;
            int ADDRESS;
            int value;
            std::cin >> PID >> ADDRESS >> value;
        }
        else if (command == "READ")
        {
            int PID;
            int ADDRESS;
            std::cin >> PID >> ADDRESS;
        }
        else if (command == "DELETE")
        {
            int PID;
            std::cin >> PID;
        }
        else if (command == "PRINT")
        {
            int m;
            std::cin >> m;
        }
        else if (command == "END")
        {
            break;
        }
    }
}