#include "process.hpp"
#include "SeparateChainingHT.hpp"

#include <iostream>
#include <string>

SeparateChainingHT::SeparateChainingHT(int memory_size, int page_size)
{
    // Hash table with size of m
    HT_size = memory_size / page_size;
    process = new Process[HT_size]{};

    // Initialize memory array
    memory = new int[memory_size];
    // Check what pages are used
    pages_used = new int[page_size];
    N = memory_size;
    P = page_size;

    std::cout << "success" << std::endl;
}

SeparateChainingHT::~SeparateChainingHT(){};

// Insert PID and allocate memory
void SeparateChainingHT::insert_PID(int id){};

// Search for key PID in Hash table
void SeparateChainingHT::search_PID(int id){};

// Write a value to memory
void SeparateChainingHT::write_PID(int id, int addr_virtual, int value){};

// Read a value from memory
void SeparateChainingHT::read_PID(int id, int addr_virtual){};

// Delete a key PID from hash table
void SeparateChainingHT::delete_PID(int id){};

// Print  a key PID from hash table
void SeparateChainingHT::print_PID(int id){};