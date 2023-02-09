#include "process.hpp"

// Constructor
Process::Process(int id, int address)
{
    PID = id;
    addr_physical = address;
}

// Destructor
Process::~Process()
{
}

// Setter and getter functions for each variable
void Process::set_PID(int id)
{
    PID = id;
};
void Process::set_addr_physical(int address)
{
    addr_physical = address;
};

int Process::get_PID(){
    return PID;
};
int Process::get_addr_physical(){
    return addr_physical;
};