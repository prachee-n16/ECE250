#pragma once

#include "process.hpp"

class OpenAddressedHT
{
private:
    // Memory array
    int *memory;

    // Hash table of process id's
    Process *process;

    // Maximum size of hash table
    int HT_size;

    // Maximum page size
    int P;
    //Virtual memory array
    int *pages_used;
    //Current capacity for pages
    int current_pages_used;

    // Maximum memory size
    int N;

public:
    // Constructor and Destructor
    OpenAddressedHT(int memory_size, int page_size);
    ~OpenAddressedHT();

    // Insert PID and allocate memory
    void insert_PID(unsigned int id);

    // Search for key PID in Hash table
    void search_PID(unsigned int id);

    // Write a value to memory
    void write_PID(unsigned int id, int addr_virtual, int value);

    // Read a value from memory
    void read_PID(unsigned int id, int addr_virtual);

    // Delete a key PID from hash table
    void delete_PID(unsigned int id);
};