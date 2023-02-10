#include "process.hpp"
#include "OpenAddressedHT.hpp"

#include <iostream>
#include <string>

// Constructor
OpenAddressedHT::OpenAddressedHT(int memory_size, int page_size)
{
    // Hash table with size of m
    HT_size = memory_size / page_size;

    process = new Process[HT_size]{};

    // Initialize memory array
    memory = new int[memory_size]{0};
    // Check what pages are used
    pages_used = new int[HT_size]{0};
    current_pages_used = 0;

    N = memory_size;
    P = page_size;

    std::cout << "success" << std::endl;
};

// Destructor
OpenAddressedHT::~OpenAddressedHT()
{
    delete[] memory;
    delete[] pages_used;
    delete[] process;

    memory = nullptr;
    pages_used = nullptr;
    process = nullptr;
};

// logic borrowed from ECE 250 Slides
// Insert a PID (key into hash table) and allocate memory
void OpenAddressedHT::insert_PID(unsigned int id)
{
    if (current_pages_used == N / P)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    for (int i = 0; i < HT_size; i++)
    {
        if (process[i].get_PID() == id)
        {
            std::cout << "failure" << std::endl;
            return;
        }
    }

    // Set probe and offset using given hash functions
    int probe = id % HT_size;
    int offset = (id / HT_size) % HT_size;
    // If the offset is even, add 1
    if (offset % 2 == 0)
        offset += 1;

    // While this index has not been accessed
    while (process[probe].get_isProcessCreated() == true)
    {
        probe = (probe + offset) % HT_size;
    };

    // FIXME: When adding to memory, do it in such a way that
    //  It's ordered from the get go
    //  Set PID and physical address
    process[probe].set_isProcessCreated(true);
    process[probe].set_PID(id);

    // If this memory has not already been assigned
    if (pages_used[probe] == 0)
    {
        process[probe].set_addr_physical(probe * P);
        pages_used[probe] = 1;
    }
    else
    {
        // Find space in memory array for this process
        for (int i = 0; i < HT_size; i++)
        {
            if (pages_used[i] == 0)
            {
                process[probe].set_addr_physical(i * P);
                pages_used[i] = 1;
                break;
            }
        }
    };

    current_pages_used += 1;
    std::cout << "success" << std::endl;
};

void OpenAddressedHT::search_PID(unsigned int id)
{
    // Set probe and offset using given hash functions
    int probe = id % HT_size;
    int offset = (id / HT_size) % HT_size;
    // If the offset is even, add 1
    if (offset % 2 == 0)
        offset += 1;

    int loop_count = 0;
    // If it has looped through all of hash table
    // Exit while loop
    while (loop_count != HT_size)
    {
        if (process[probe].get_PID() == id)
        {
            std::cout << "found " << id << " in " << probe << std::endl;
            return;
        };
        probe = (probe + offset) % HT_size;
        loop_count += 1;
    };

    std::cout << "not found" << std::endl;
};

void OpenAddressedHT::write_PID(unsigned int id, int addr_virtual, int value)
{
    // Checks if virtual address in space
    if (addr_virtual > P - 1)
    {
        std::cout << "failure" << std::endl;
        return;
    }
    // Set probe and offset using given hash functions
    int probe = id % HT_size;
    int offset = (id / HT_size) % HT_size;
    // If the offset is even, add 1
    if (offset % 2 == 0)
        offset += 1;

    int loop_count = 0;
    while ((process[probe].get_isProcessCreated() == true) && (loop_count != HT_size))
    {
        if (process[probe].get_PID() == id)
        {
            // FIXME: Index here should use page id we set
            //  Isn't physical address and page id same thing
            int index = process[probe].get_addr_physical() + addr_virtual;
            memory[index] = value;
            std::cout << "success" << std::endl;
            return;
        };
        probe = (probe + offset) % HT_size;
        loop_count += 1;
    };

    // Did not find PID
    std::cout << "failure" << std::endl;
};

void OpenAddressedHT::read_PID(unsigned int id, int addr_virtual)
{
    // Checks if virtual address in space
    if (addr_virtual > (P - 1))
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // Set probe and offset using given hash functions
    int probe = id % HT_size;
    int offset = (id / HT_size) % HT_size;
    // If the offset is even, add 1
    if (offset % 2 == 0)
        offset += 1;

    int loop_count = 0;

    while ((process[probe].get_isProcessCreated() == true) && (loop_count != HT_size))
    {
        if (process[probe].get_PID() == id)
        {
            int index = process[probe].get_addr_physical() + addr_virtual;
            std::cout << addr_virtual << " " << memory[index] << std::endl;
            return;
        };
        probe = (probe + offset) % HT_size;
        loop_count += 1;
    };

    // Did not find PID
    std::cout << "failure" << std::endl;
};

void OpenAddressedHT::delete_PID(unsigned int id)
{
    // Set probe and offset using given hash functions
    int probe = id % HT_size;
    int offset = (id / HT_size) % HT_size;
    // If the offset is even, add 1
    if (offset % 2 == 0)
        offset += 1;

    int loop_count = 0;
    while (loop_count != HT_size)
    {
        if (process[probe].get_PID() == id)
        {
            int index = process[probe].get_addr_physical();
            pages_used[index] = 0;
            current_pages_used -= 1;

            process[probe].set_isProcessCreated(false);
            process[probe].set_PID(0);
            process[probe].set_addr_physical(0);

            std::cout << "success" << std::endl;
            return;
        };
        probe = (probe + offset) % HT_size;
        loop_count += 1;
    };

    // Did not find PID
    std::cout << "failure" << std::endl;
};