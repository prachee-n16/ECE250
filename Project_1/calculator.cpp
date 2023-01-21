// Libraries
#include <iostream>
#include <string>

int main();

class Node
{
private:
    // Stores the value of Node
    double val;
    // Stores the name of Node
    std::string name;
    // Stores the next Node
    Node *next;

public:
    // Default Constructor
    Node()
    {
        val = 0;
        name = "";
        next = NULL;
    }

    // Parametrised Constructor
    Node(std::string s, double n)
    {
        name = s;
        val = n;
        next = NULL;
    }

    ~Node() {}

    // Setter and getter functions for each variable
    std::string get_name()
    {
        return name;
    };
    double get_value()
    {
        std::cout << val << std::endl;
        return val;
    };
    Node *get_next_node()
    {
        return next;
    };

    void set_name(std::string s)
    {
        name = s;
    };
    void set_value(double num)
    {
        val = num;
    };
    void set_next_node(Node *next_node)
    {
        next = next_node;
    };
};

// Class for calculator-based linked list
class Calculator
{
    // Private variables
private:
    // Size stores the max_size of array
    int max_size;
    // Stores current size of calculator
    int current_size;

    // FIXME: KILL MEMORY IN DESTRUCTOR
    // Stores the head of the linked list
    Node *head;
    // Stores the tail of the linked list
    Node *tail;

public:
    // Constructor
    Calculator(int n)
    {
        // Change size of linked list
        max_size = n;
        current_size = 0;
        head = NULL;
        tail = NULL;
    }

    // Destructor
    ~Calculator()
    {
    }

    // TODO: Find better function names (not a fan of these ones)
    // To be called for input command DEF
    void insert_node(std::string x, double val)
    {
        // If head is empty, add this to linked list
        if (head == NULL)
        {
            head = new Node(x, val);
            tail = head;
        }
        else
        {
            // If head is not empty, add it to end of linked list
            Node *temp = new Node(x, val);
            temp->set_next_node(head);
            head = temp;
            print_linked_list();
        }
    };

    // For testing purposes
    void print_linked_list()
    {
        Node *temp = head;
        while (temp->get_next_node() != NULL)
        {
            temp->get_value();
            temp = temp->get_next_node();
        }
    }

    // To be called for input command REM
    void remove_node(std::string x);

    // To be called for other function purposes
    void find_node(std::string x);

    // To be called for input command PRT
    void print_node_value(std::string x);

    // To be called for input command Add
    void add_nodes(std::string x, std::string y, std::string z);

    // To be called for input command SUB
    void sub_nodes(std::string x, std::string y, std::string z);

public:
};

int main()
{
    // Stores user's input command
    std::string command;
    // Calculator instance
    Calculator *calculator;

    while (std::cin >> command)
    {
        // First command to run always!
        if (command == "CRT")
        {
            int size;
            std::cin >> size;
            calculator = new Calculator(size);
        }
        else if (command == "DEF")
        {
            std::string name;
            double value;

            std::cin >> name;
            std::cin >> value;
            calculator->insert_node(name, value);
        }
        else if (command == "ADD")
        {
            int x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            std::cout << command << x << y << z << std::endl;
        }
        else if (command == "SUB")
        {
            int x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            std::cout << command << x << y << z << std::endl;
        }
        else if (command == "REM")
        {
            std::string name;

            std::cout << command << name << std::endl;
        }
        else if (command == "PRT")
        {
            std::string name;

            std::cout << command << name << std::endl;
        }
        else if (command == "EXT")
        {
            break;
        }
    }
}