#include "ToDoApp.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    using namespace Todo_app;

    ToDoList toDoList;

    while (true) {
        clearScreen();
        int choice;
        getListAction(choice, toDoList);
        clearScreen();

        switch (choice) {
            case static_cast<int>(ListAction::Add):
                AddElement(toDoList);
                break;
            case static_cast<int>(ListAction::Remove):
                RemoveElement(toDoList);
                break;
            case static_cast<int>(ListAction::Edit):
                EditElement(toDoList);
                break;
            case static_cast<int>(ListAction::Exit):
                return 0;
            default:
                clearScreen();
                std::printf("Invalid choice. Please try again.");
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
        }
    }
    return 0;
}
