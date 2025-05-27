#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

//my (very simple) print utils
#include "printUtils.h"

//List element class
class ListElement{
public:
    std::string value;
    
    ListElement(const std::string& val) : value(val) {}

};

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





namespace Todo_app{
    //clears the console screen
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }

    //gets input from the user with error handling
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

    //a specialized input function to get input for the list actions
    void getListAction(int& choice, const ToDoList& toDoList) {
        // Displays the list actions and gets the user's choice
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




    //Switch statement functions
    void AddElement(ToDoList& toDoList) {
        // Function to handle adding an element
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
        //edit an element in the list
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


    // Enum for list actions to imporve readability in the switch statement
    enum class ListAction {
        Add = 1,
        Remove = 2,
        Edit = 3,
        Exit = 4
    };
}
int main() {
    using namespace Todo_app;

    //Defines todolist vector
    ToDoList toDoList;

    while (true) {
        // Main loop for the to-do list application

        //gets the choice from the user for what action to take
        clearScreen();
        int choice;
        getListAction(choice, toDoList);
        clearScreen();


        //the logic for the actions
        switch (choice) {
            case static_cast<int>(ListAction::Add) : {
                AddElement(toDoList);
                break;
            }
            case static_cast<int>(ListAction::Remove) : {
                RemoveElement(toDoList);
                break;
            }
            case static_cast<int>(ListAction::Edit): {
                EditElement(toDoList);
                break;
            }
            case static_cast<int>(ListAction::Exit): {
                //exit the application
                return 0;
            }
            default: {
                //invalid choice handling
                clearScreen();
                println("Invalid choice. Please try again.");
                std::this_thread::sleep_for(std::chrono::seconds(1));
                break;
            }
        }
        //end of the switch statement

    }
    return 0;
}
