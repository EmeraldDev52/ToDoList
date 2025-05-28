#include <string>
#include <vector>
#include "ListElementClass.h"
#include <print>
#include <iostream>
// ToDoList class that manages a list of ListElement objects
class ToDoList {
public:
    //a vector to store the list elements
    std::vector<ListElement> list;

    // Adds an element to the to do list
    void addElement(const std::string& value) {
        list.push_back(ListElement(value)); 
    }

    // Edits an element in the to do list
    void editElement(int elementId, const std::string& value) {
        if (elementId < 1 || elementId > list.size()) {
            std::printf("Invalid element ID.");
            return;
        }
        list[elementId - 1].value = value; 
    }

    // Removes an element from the to do list
    void removeElement(int elementId) {
        if (elementId < 1 || elementId > list.size()) {
            std::printf("Invalid element ID.");
            return;
        }
        list.erase(list.begin() + elementId - 1);
    }

    // Prints the to-do list
    void printList() const {
        if (list.empty()) {
            std::printf("The list is empty.");
            return;
        }
        std::printf("Your list:");
        for (size_t i = 0; i < list.size(); ++i) {
            std::cout << (i + 1) << ". " << list[i].value << std::endl;

        }
    }
};