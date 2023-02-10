#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "process.hpp"

class SeparateChainingHT
{
private:
    // Memory array
    int *memory;

    // Hash table of process id's
    std::vector<Process> *process;

    // Maximum size of hash table
    int HT_size;

    // Maximum page size
    int P;
    // Virtual memory array
    int *pages_used;
    // Current capacity for pages
    int current_pages_used;

    // Maximum memory size
    int N;

public:
    // Constructor and Destructor
    SeparateChainingHT(int memory_size, int page_size);
    ~SeparateChainingHT();

    // Insert PID and allocate memory
    void insert_PID(int id);

    // Search for key PID in Hash table
    void search_PID(int id);

    // Write a value to memory
    void write_PID(int id, int addr_virtual, int value);

    // Read a value from memory
    void read_PID(int id, int addr_virtual);

    // Delete a key PID from hash table
    void delete_PID(int id);

    // Print  a key PID from hash table
    void print_PID(int id);
};