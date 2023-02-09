#pragma once

class Process {
    private:
    //FIXME: Is it okay to name it CAPITAL PID here?
        // Stores the Process ID
        int PID;
        // Stores the physical address
        int addr_physical;

    public:
        //Constructor and Destructor
        Process(int id, int address);
        ~Process();

        // Setter and getter functions for each variable
        void set_PID(int id);
        void set_addr_physical(int address);

        int get_PID();
        int get_addr_physical();
};