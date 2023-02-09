#pragma once

class Process {
    private:
    //FIXME: Is it okay to name it CAPITAL PID here?
        // Stores the Process ID
        int PID;
        // Stores the physical address
        int addr_physical;
        //Boolean to check if PID is assigned or not
        bool isProcessCreated;
        //Integer to store which page# process is assigned to
        int pageID;

    public:
        //Constructor and Destructor
        Process();
        ~Process();

        // Setter and getter functions for each variable
        void set_PID(int id);
        void set_addr_physical(int address);
        void set_isProcessCreated(bool does_process_exist);
        void set_pageID(int id);

        int get_PID();
        int get_addr_physical();
        int get_pageID();
        bool get_isProcessCreated();
};