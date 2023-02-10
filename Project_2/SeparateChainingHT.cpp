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
    memory = new int[memory_size];
    // Check what pages are used
    pages_used = new int[page_size];
    N = memory_size;
    P = page_size;

    // Hashtable where each element is a vector of Process objects
    process = new std::vector<Process>[HT_size];

    std::cout << "success" << std::endl;
}

SeparateChainingHT::~SeparateChainingHT(){};

// Insert PID and allocate memory
void SeparateChainingHT::insert_PID(int id)
{
    // TODO: Check if hash table is full
    if (current_pages_used == N / P)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // Set probe using given hash function
    int probe = id % HT_size;

    // CODE
    // What I want to do is access the process at probe index
    // Push back a new process object
    // So let's make that process object
    Process *proc = new Process;
    proc->set_isProcessCreated(true);
    proc->set_PID(id);
    proc->set_pageID(probe);
    proc->set_addr_physical(probe * P);
    proc->set_pageID(probe);
    pages_used[probe] = 1;

    current_pages_used += 1;

    process[probe].push_back(*proc);
    std::cout << "success" << std::endl;
};

// Search for key PID in Hash table
void SeparateChainingHT::search_PID(int id)
{
    // Set probe using given hash function
    int probe = id % HT_size;

    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i].get_PID() == id)
        {
            std::cout << "found " << id << " in " << probe << std::endl;
            return;
        }
    };

    std::cout << "not found" << std::endl;
};

// Write a value to memory
void SeparateChainingHT::write_PID(int id, int addr_virtual, int value)
{
    // Checks if virtual address in space
    if (addr_virtual > P)
    {
        std::cout << "failure" << std::endl;
    }

    // Set probe using given hash function
    int probe = id % HT_size;
    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i].get_PID() == id)
        {
            int index = process[probe][i].get_addr_physical() + addr_virtual;
            memory[index] = value;
            std::cout << "success" << std::endl;
            return;
        }
    }

    // Did not find PID
    std::cout << "failure" << std::endl;
};

// Read a value from memory
void SeparateChainingHT::read_PID(int id, int addr_virtual)
{
    // Checks if virtual address in space
    if (addr_virtual > P)
    {
        std::cout << "failure" << std::endl;
    }

    // Set probe using given hash function
    int probe = id % HT_size;
    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i].get_PID() == id)
        {
            int index = process[probe][i].get_addr_physical() + addr_virtual;
            std::cout << addr_virtual << " " << memory[index] << std::endl;
            return;
        }
    }

    // Did not find PID
    std::cout << "failure" << std::endl;
};

// Delete a key PID from hash table
void SeparateChainingHT::delete_PID(int id)
{
    // Set probe using given hash function
    int probe = id % HT_size;

    for (int i = 0; i < process[probe].size(); i++)
    {
        if (process[probe][i].get_PID() == id)
        {
            pages_used[probe] = 0;
            current_pages_used -= 1;
            process[probe].erase(process[probe].begin()+i);
            return;
        }
    }
};

// Print  a key PID from hash table
void SeparateChainingHT::print_PID(int id){
    
};