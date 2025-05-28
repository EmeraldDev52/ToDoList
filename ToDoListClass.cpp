#include "ToDoListClass.h"
#include <iostream>

void ToDoList::addElement(const std::string& value) {
    list.push_back(ListElement(value)); 
}

void ToDoList::editElement(int elementId, const std::string& value) {
    if (elementId < 1 || elementId > list.size()) {
        std::printf("Invalid element ID.");
        return;
    }
    list[elementId - 1].value = value; 
}

void ToDoList::printList() {
    if (list.empty()) {
        std::printf("The list is empty.");
        return;
    }
    std::printf("Your list:\n");
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << (i + 1) << ". " << list[i].value << std::endl;
    }
}
