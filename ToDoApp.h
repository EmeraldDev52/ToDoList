#pragma once
#include "ToDoListClass.h"

namespace Todo_app {
    void clearScreen();
    void getInput(int& variable);
    void getInput(std::string& variable);
    void getListAction(int& choice, const ToDoList& toDoList);
    void AddElement(ToDoList& toDoList);
    void RemoveElement(ToDoList& toDoList);
    void EditElement(ToDoList& toDoList);

    enum class ListAction {
        Add = 1,
        Remove = 2,
        Edit = 3,
        Exit = 4
    };
}
