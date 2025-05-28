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
    void editElement(int elementId, const std::string& value);

    // Removes an element from the to do list
    void removeElement(int elementId) {
        if (elementId < 1 || elementId > static_cast<int>(list.size())) {
            std::printf("Invalid element ID.");
            return;
        }
        list.erase(list.begin() + elementId - 1);
    }

    // Prints the to-do list
    void printList();
};