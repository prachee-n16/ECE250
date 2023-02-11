#include "process.hpp"
#include "SeparateChainingHT.hpp"

#include <iostream>
#include <string>
#include <vector>

SeparateChainingHT::SeparateChainingHT(int memory_size, int page_size)
{
    // Hash table with size of m
    HT_size = memory_size / page_size;

    // Initialize memory array
    memory = new int[memory_size]{0};
    // Check what pages are used
    pages_used = new int[HT_size]{0};
    N = memory_size;
    P = page_size;

    current_pages_used = 0;

    // Hashtable where each element is a vector of Process objects
    process = new std::vector<Process *>[HT_size] {};

    std::cout << "success" << std::endl;
}

SeparateChainingHT::~SeparateChainingHT()
{
    for (int i = 0; i < HT_size; i++)
    {
        for (int j = 0; j < process[i].size(); j++)
        {
            delete process[i][j];
        }
        process[i].clear();
    }

    delete[] process;
    delete[] memory;
    delete[] pages_used;

    memory = nullptr;
    pages_used = nullptr;
    process = nullptr;
};

// Insert PID and allocate memory
void SeparateChainingHT::insert_PID(unsigned int id)
{
    // TODO: Check if hash table is full
    if (current_pages_used == N / P)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // Set probe using given hash function
    int probe = id % HT_size;
    // Store where it should go into vector to be ordered
    int index = -3;
    // Go through vector and ensure PID doesn't already exist
    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i]->get_PID() == id)
        {
            std::cout << "failure" << std::endl;
            return;
        }

        // While index has not been set
        if (index == -3)
        {
            if (process[probe][i]->get_PID() < id)
            {
                index = i;
            }
        }
    };

    // When inserting PID, I am setting page ID always as probe.
    // I need to add a check to see if there is space elsewhere in memory
    Process *proc = new Process;
    proc->set_isProcessCreated(true);
    proc->set_PID(id);

    if (pages_used[probe] == 0)
    {
        proc->set_addr_physical(probe * P);
        pages_used[probe] = 1;
    }
    else
    {
        //Find space in memory array for this process
        for (int i = 0; i < HT_size; i++)
        {
            if (pages_used[i] == 0)
            {
                proc->set_addr_physical(i * P);
                pages_used[i] = 1;
                break;
            }
        }
    }

    current_pages_used += 1;
    //We never encountered a ID greater than what we have right now
    if (index == -3)
    {
        process[probe].push_back(proc);
    }
    else
    {
        process[probe].insert(process[probe].begin() + index, proc);
    }

    std::cout << "success" << std::endl;
};

// Search for key PID in Hash table
void SeparateChainingHT::search_PID(unsigned int id)
{
    // Set probe using given hash function
    int probe = id % HT_size;

    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i]->get_PID() == id)
        {
            std::cout << "found " << id << " in " << probe << std::endl;
            return;
        }
    };

    std::cout << "not found" << std::endl;
};

// Write a value to memory
void SeparateChainingHT::write_PID(unsigned int id, int addr_virtual, int value)
{
    // Checks if virtual address in space
    if (addr_virtual > (P - 1))
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // Set probe using given hash function
    int probe = id % HT_size;
    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i]->get_PID() == id)
        {
            int index = process[probe][i]->get_addr_physical() + addr_virtual;
            memory[index] = value;
            std::cout << "success" << std::endl;
            return;
        }
    }

    // Did not find PID
    std::cout << "failure" << std::endl;
};

// Read a value from memory
void SeparateChainingHT::read_PID(unsigned int id, int addr_virtual)
{
    // Checks if virtual address in space
    if (addr_virtual > P - 1)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // Set probe using given hash function
    int probe = id % HT_size;
    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i]->get_PID() == id)
        {
            int index = process[probe][i]->get_addr_physical() + addr_virtual;
            std::cout << addr_virtual << " " << memory[index] << std::endl;
            return;
        }
    }

    // Did not find PID
    std::cout << "failure" << std::endl;
};

// Delete a key PID from hash table
void SeparateChainingHT::delete_PID(unsigned int id)
{
    // Set probe using given hash function
    int probe = id % HT_size;

    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i]->get_PID() == id)
        {
            pages_used[process[probe][i]->get_addr_physical() / P] = 0;
            current_pages_used -= 1;

            Process *proc = process[probe][i];

            process[probe].erase(process[probe].begin() + i);

            delete proc;
            proc = nullptr;

            std::cout << "success" << std::endl;
            return;
        }
    }

    // Did not find PID
    std::cout << "failure" << std::endl;
};

// Print a key PID from hash table
void SeparateChainingHT::print_PID(int m)
{
    if (process[m].size() == 0)
    {
        std::cout << "chain is empty" << std::endl;
        return;
    }

    // Set probe using given hash function
    for (int i = 0; i < process[m].size(); i++)
    {
        if (i == process[m].size() - 1)
        {
            std::cout << process[m][i]->get_PID();
        }
        else
        {
            std::cout << process[m][i]->get_PID() << " ";
        }
    }
    std::cout << std::endl;
};