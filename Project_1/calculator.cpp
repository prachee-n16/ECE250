// Libraries
#include <iostream>
#include <string>

#include "node.hpp"
#include "calculator.hpp"

// Class for calculator-based linked list
// Constructor
Calculator::Calculator(int n)
{
    // Change size of linked list
    max_size = n;
    current_size = 0;
    head = NULL;

    std::cout << "success" << std::endl;
};

// Destructor
Calculator::~Calculator()
{
    Node *temp = head;

    while (head != NULL)
    {
        while (head->get_next_node() != NULL)
        {
            temp = head->get_next_node();
            head = temp;
        }
    }

    delete temp;
    temp = nullptr;
};

// TODO: Find better function names (not a fan of these ones)
// To be called for input command DEF
void Calculator::insert_node(std::string x, double val)
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
            current_size += 1;

            std::cout << "success" << std::endl;

            temp = nullptr;
            delete temp;
        }
        else
        {
            std::cout << "failure" << std::endl;
        }
    }
};

// To be called for input command REM
void Calculator::remove_node(std::string x)
{
    // Node before removed node;
    Node *prev_r = head;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->get_name() == x)
        {
            break;
        }
        prev_r = temp;
        temp = temp->get_next_node();
    }
    if (current_size == 1)
    {
        head = NULL;
        current_size -= 1;
        std::cout << "success" << std::endl;
        return;
    }
    if (temp != NULL)
    {
        prev_r->set_next_node(temp->get_next_node());
        current_size -= 1;
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    };

    prev_r = nullptr;
    temp = nullptr;
    delete prev_r;
    delete temp;
};

// To be called for other function purposes
Node *Calculator::find_node(std::string x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->get_name() == x)
        {
            temp = nullptr;
            delete temp;
            return temp;
        }
        temp = temp->get_next_node();
    }

    temp = nullptr;
    delete temp;
    return NULL;
};

// To be called for input command PRT
void Calculator::print_node_value(std::string x)
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
    temp = nullptr;
    delete temp;
};

// To be called for input command Add
void Calculator::add_nodes(std::string x, std::string y, std::string z)
{
    if (head == NULL)
    {
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
        if (temp->get_name() == y)
        {
            variables_found += 1;
            y1 = temp->get_value();
        }
        if (temp->get_name() == z)
        {
            variables_found += 1;
            z1 = temp;
        }
        temp = temp->get_next_node();
    }

    if (variables_found == 3)
    {
        z1->set_value(x1 + y1);
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }

    temp = nullptr;
    z1 = nullptr;
    delete temp;
    delete z1;
};

// To be called for input command SUB
void Calculator::sub_nodes(std::string x, std::string y, std::string z)
{
    if (head == NULL)
    {
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

    if (variables_found == 3)
    {
        z1->set_value(x1 - y1);
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }

    temp = nullptr;
    z1 = nullptr;
    delete temp;
    delete z1;
};