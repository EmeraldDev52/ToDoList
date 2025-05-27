#include "TodoApp.h"
#include "printUtils.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

namespace Todo_app {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    void getInput(int& variable) {
        while (!(std::cin >> variable)) {
            println("Invalid input, please enter a number.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void getInput(std::string& variable) {
        std::getline(std::cin, variable);
    }

    void getListAction(int& choice, const ToDoList& toDoList) {
        println("What do you want to do with your list?\n");
        println("[1] Add an element");
        println("[2] Remove an element");
        println("[3] Edit an element");
        println("[4] Exit\n");
        if (!toDoList.list.empty()) {
            toDoList.printList();
        }
        getInput(choice);
    }

    void AddElement(ToDoList& toDoList) {
        println("Enter the element you want to add:");
        if (!toDoList.list.empty()) {
            toDoList.printList();
        }
        std::string element;
        getInput(element);
        toDoList.addElement(element);
    }

    void RemoveElement(ToDoList& toDoList) {
        if (toDoList.list.empty()) {
            clearScreen();
            println("The list is empty. Nothing to remove.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return;
        }
        println("Choose the element you want to remove (by number):");
        toDoList.printList();
        int elementId;
        getInput(elementId);
        toDoList.removeElement(elementId);
    }

    void EditElement(ToDoList& toDoList) {
        if (toDoList.list.empty()) {
            println("The list is empty. Nothing to edit.");
            return;
        }
        println("Which element do you want to edit (by number)?");
        toDoList.printList();
        int elementId;
        getInput(elementId);
        if (elementId < 1 || elementId > static_cast<int>(toDoList.list.size())) {
            clearScreen();
            println("Invalid element ID.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return;
        }
        clearScreen();
        println("Enter the new value for the element:");
        toDoList.printList();
        std::string element;
        getInput(element);
        toDoList.editElement(elementId, element);
    }
}
