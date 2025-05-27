#pragma once

#include <string>
#include <vector>
#include "printUtils.h"
#include "ListElementClass.h"
// ToDoList class that manages a list of ListElement objects
class ToDoList {
public:
    //a vector to store the list elements
    std::vector<ListElement> list;

    // Adds an element to the to do list
    void addElement(const std::string& value) {
        list.push_back(ListElement(value)); // NOTE FOR MYSELF: emplace_back automatically constructs a ListElement with the given value bc it knows the vector stores that type
    }

    // Edits an element in the to do list
    void editElement(int elementId, const std::string& value) {
        if (elementId < 1 || elementId > static_cast<int>(list.size())) {
            println("Invalid element ID.");
            return;
        }
        list[elementId - 1].value = value; 
    }

    // Removes an element from the to do list
    void removeElement(int elementId) {
        if (elementId < 1 || elementId > static_cast<int>(list.size())) {
            println("Invalid element ID.");
            return;
        }
        list.erase(list.begin() + elementId - 1);
    }

    // Prints the to-do list
    void printList() const {
        if (list.empty()) {
            println("The list is empty.");
            return;
        }
        println("Your list:");
        for (size_t i = 0; i < list.size(); ++i) {
            println(std::to_string(i + 1) + ". " + list[i].value);
        }
    }
};