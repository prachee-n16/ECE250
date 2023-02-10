#include "process.hpp"

// Constructor
Process::Process()
{
    PID = 0;
    addr_physical = 0;
    isProcessCreated = false;
}

// Destructor
Process::~Process()
{
}

// Setter and getter functions for each variable
void Process::set_PID(unsigned int id)
{
    PID = id;
};

void Process::set_addr_physical(int address)
{
    addr_physical = address;
};

void Process::set_isProcessCreated(bool does_process_exist)
{
    isProcessCreated = does_process_exist;
};

unsigned int Process::get_PID()
{
    return PID;
};


int Process::get_addr_physical()
{
    return addr_physical;
};

bool Process::get_isProcessCreated()
{
    return isProcessCreated;
}