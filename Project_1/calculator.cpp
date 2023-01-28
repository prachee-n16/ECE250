// Libraries
#include <iostream>
#include <string>

#include "node.hpp"
#include "calculator.hpp"

// Class for calculator-based linked list

// Constructor
Calculator::Calculator(int n)
{
    // Size of linked list
    max_size = n;
    current_size = 0;
    head = nullptr;

    std::cout << "success" << std::endl;
};

// Destructor
Calculator::~Calculator()
{
    Node *temp = head;

    while (head != nullptr)
    {
        temp = head->get_next_node();
        delete head;
        head = temp;
    }
};

// Insert the value into calculator linked list
void Calculator::insert_node(std::string x, double val)
{
    // If head is empty, add this to linked list
    // Make sure size isn't exceeded
    if (head == nullptr && current_size != max_size)
    {
        head = new Node(x, val);
        current_size += 1;

        std::cout << "success" << std::endl;
    }
    else
    {
        // If node is not already added,
        // and max size hasn't been reached
        if (find_node(x) == nullptr && current_size != max_size)
        {
            Node *temp = head;
            head = new Node(x, val);
            head->set_next_node(temp);
            current_size += 1;

            std::cout << "success" << std::endl;
        }
        else
        {
            std::cout << "failure" << std::endl;
        }
    }
};

// To be called for input command REM
// Remove the node
void Calculator::remove_node(std::string x)
{
    // Node before removed node;
    Node *prev_r = head;
    Node *temp = head;

    if (head == nullptr)
    {
        std::cout << "failure" << std::endl;
        return;
    }

    // If the element to be deleted is head
    if (temp->get_name() == x)
    {
        // If it's the only node
        if (current_size == 1)
        {
            delete head;
            head = nullptr;

            current_size -= 1;
            std::cout << "success" << std::endl;
            return;
        }
        // Remove first element where size > 1
        else
        {
            Node *temp = head;
            head = head->get_next_node();
            delete temp;
        }
        current_size -= 1;
        std::cout << "success" << std::endl;
        return;
    }

    // If not first element,
    // Find node previous to it
    while (temp != nullptr)
    {
        if (temp->get_name() == x)
        {
            break;
        }
        prev_r = temp;
        temp = temp->get_next_node();
    }

    // If the element is found, delete it
    if (temp != nullptr)
    {
        prev_r->set_next_node(temp->get_next_node());
        delete temp;
        current_size -= 1;
        std::cout << "success" << std::endl;
    }

    else
    {
        std::cout << "failure" << std::endl;
    };
};

// To be called for other function purposes
// Finds the node we are looking for
Node *Calculator::find_node(std::string x)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->get_name() == x)
        {
            return temp;
        }
        temp = temp->get_next_node();
    }

    return nullptr;
};

// To be called for input command PRT
void Calculator::print_node_value(std::string x)
{
    Node *temp = find_node(x);
    if (temp != nullptr)
    {
        std::cout << temp->get_value() << std::endl;
    }
    else
    {
        std::cout << "variable " << x << " not found" << std::endl;
    }
};

// To be called for input command Add
void Calculator::arithmetic_op_nodes(std::string x, std::string y, std::string z, std::string operation)
{
    if (head == nullptr)
    {
        std::cout << "failure" << std::endl;
    }
    // Stores the values that need to be added and keep sum
    double x1, y1;
    int variables_found = 0;

    Node *temp = head;
    Node *z1 = head;

    // Finds all the variables we are looking for
    while (temp != nullptr)
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
        // Check which operation we want to do
        if (operation == "ADD")
        {
            z1->set_value(x1 + y1);
        } else if (operation == "SUB") {
            z1->set_value(x1 - y1);
        }
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
};