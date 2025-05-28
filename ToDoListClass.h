#pragma once

#include <string>
#include <vector>
#include "ListElementClass.h"
// ToDoList class that manages a list of ListElement objects
class ToDoList {
public:
    //a vector to store the list elements
    std::vector<ListElement> list;

    // Adds an element to the to do list
    void addElement(const std::string& value);

    // Edits an element in the to do list
    void editElement(size_t elementId, const std::string& value);

    // Removes an element from the to do list
    void removeElement(size_t elementId) {
        if (elementId < 1 || elementId > list.size()) {
            std::printf("Invalid element ID.");
            return;
        }
        list.erase(list.begin() + elementId - 1);
    }

    // Prints the to-do list
    void printList();
};