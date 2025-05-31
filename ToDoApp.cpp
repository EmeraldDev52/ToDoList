#include "ToDoApp.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <string>
#include <print>
namespace Todo_app {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    void getListAction(int& choice, ToDoList& toDoList) {
        std::printf("What do you want to do with your list?\n\n");
        std::printf("[1] Add an element\n");
        std::printf("[2] Remove an element\n");
        std::printf("[3] Edit an element\n");
        std::printf("[4] Exit\n\n");
        if (!toDoList.list.empty()) {
            toDoList.printList();
        }
        std::cin >> choice;
        std::cin.ignore();
    }


    // extracted switch case functions 
    void AddElement(ToDoList& toDoList) {
        std::printf("Enter the element you want to add:\n");
        if (!toDoList.list.empty()) {
            toDoList.printList();
        }
        std::string element;
        std::getline(std::cin, element);
        toDoList.addElement(element);
    }

    void RemoveElement(ToDoList& toDoList) {
        if (toDoList.list.empty()) {
            clearScreen();
            std::printf("The list is empty. Nothing to remove.\n");
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return;
        }
        std::printf("Choose the element you want to remove (by number):\n");
        toDoList.printList();
        int elementId;
        std::cin >> elementId;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        toDoList.removeElement(elementId);
    }

    void EditElement(ToDoList& toDoList) {
        if (toDoList.list.empty()) {
            std::printf("The list is empty. Nothing to edit.\n");
            return;
        }
        std::printf("Which element do you want to edit (by number)?\n");
        toDoList.printList();
        int elementId;
        std::cin >> elementId;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (elementId < 1 || elementId > toDoList.list.size()) {
            clearScreen();
            std::printf("Invalid element ID.\n");
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return;
        }
        clearScreen();
        std::printf("Enter the new value for the element:\n");
        toDoList.printList();
        std::string element;
        std::getline(std::cin, element);
        toDoList.editElement(elementId, element);
    }
}
