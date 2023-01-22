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

public:
    // Constructor
    Calculator(int n)
    {
        // Change size of linked list
        max_size = n;
        current_size = 0;
        head = NULL;

        std::cout << "success" << std::endl;
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
        if (head == NULL && current_size != max_size)
        {
            head = new Node(x, val);
            std::cout << "success" << std::endl;
            current_size += 1;
        }
        else
        {
            if (find_node(x) == NULL && current_size != max_size)
            {
                // If head is not empty, add it to end of linked list
                Node *temp = new Node(x, val);
                temp->set_next_node(head);
                head = temp;
                std::cout << "success" << std::endl;
                current_size += 1;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
        }
    };

    // For testing purposes
    void print_linked_list()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->get_value();
            temp = temp->get_next_node();
        }
    }

    // To be called for input command REM
    void remove_node(std::string x)
    {
        // Node before removed node;
        Node *prev_r = head;
        Node *temp = head;

        current_size -= 1;

        while (temp != NULL)
        {
            if (temp->get_name() == x)
            {
                break;
            }
            prev_r = temp;
            temp = temp->get_next_node();
        }

        if (temp != NULL)
        {
            prev_r->set_next_node(temp->get_next_node());
            std::cout << "success" << std::endl;
        }
        else
        {
            std::cout << "failure" << std::endl;
        };
    };

    // To be called for other function purposes
    Node *find_node(std::string x)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->get_name() == x)
            {
                return temp;
            }
            temp = temp->get_next_node();
        }

        return NULL;
    };

    // To be called for input command PRT
    void print_node_value(std::string x)
    {
        Node *temp = find_node(x);
        if (temp != NULL)
        {
            std::cout << temp->get_value() << std::endl;
        }
        else
        {
            std::cout << "Variable " << x << " was not found." << std::endl;
        }
    };

    // To be called for input command Add
    void add_nodes(std::string x, std::string y, std::string z)
    {
        if (head == NULL) {
            std::cout << "failure" << std::endl;
        }
        // Stores the values that need to be added and keep sum
        double x1, y1;
        int variables_found = 0;

        Node *temp = head;
        Node *z1 = head;

        while (temp != NULL)
        {
            if (temp->get_name() == x)
            {
                variables_found += 1;
                x1 = temp->get_value();
            }
            else if (temp->get_name() == y)
            {
                variables_found += 1;
                y1 = temp->get_value();
            }
            else if (temp->get_name() == z)
            {
                variables_found += 1;
                z1 = temp;
            }
            temp = temp->get_next_node();
        }

        if (variables_found != 3)
        {
            z1->set_value(x1 + y1);
            std::cout << "success" << std::endl;
        }
        else
        {
            std::cout << "failure" << std::endl;
        }
    };

    // To be called for input command SUB
    void sub_nodes(std::string x, std::string y, std::string z)
    {
        if (head == NULL) {
            std::cout << "failure" << std::endl;
        }

        // Stores the values that need to be added and keep sum
        double x1, y1;
        Node *z1;
        int variables_found = 0;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->get_name() == x)
            {
                variables_found += 1;
                x1 = temp->get_value();
            }
            else if (temp->get_name() == y)
            {
                variables_found += 1;
                y1 = temp->get_value();
            }
            else if (temp->get_name() == z)
            {
                variables_found += 1;
                z1 = temp;
            }
            temp = temp->get_next_node();
        }

        if (variables_found != 3)
        {
            z1->set_value(x1 - y1);
            std::cout << "success" << std::endl;
        }
        else
        {
            std::cout << "failure" << std::endl;
        }
    };

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
            std::string x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            calculator->add_nodes(x, y, z);
        }
        else if (command == "SUB")
        {
            std::string x, y, z;

            std::cin >> x;
            std::cin >> y;
            std::cin >> z;

            calculator->sub_nodes(x, y, z);
        }
        else if (command == "REM")
        {
            std::string name;

            std::cin >> name;

            calculator->remove_node(name);
        }
        else if (command == "PRT")
        {
            std::string name;

            std::cin >> name;

            calculator->print_node_value(name);
        }
        else if (command == "END")
        {
            calculator->print_linked_list();
            break;
        }
    }
}