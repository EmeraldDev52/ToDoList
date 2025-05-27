#include "TodoApp.h"
#include "printUtils.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <string>
namespace Todo_app {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
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
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void AddElement(ToDoList& toDoList) {
        println("Enter the element you want to add:");
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
            println("The list is empty. Nothing to remove.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return;
        }
        println("Choose the element you want to remove (by number):");
        toDoList.printList();
        int elementId;
        std::cin >> elementId;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        std::cin >> elementId;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (elementId < 1 || elementId > toDoList.list.size()) {
            clearScreen();
            println("Invalid element ID.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return;
        }
        clearScreen();
        println("Enter the new value for the element:");
        toDoList.printList();
        std::string element;
        std::getline(std::cin, element);
        toDoList.editElement(elementId, element);
    }
}
