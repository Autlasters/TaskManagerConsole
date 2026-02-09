/*
 * Source.cpp
 *
 * Contains the application entry point for the TaskManagerConsole project
 * This file initializes the task manager, displays the main console menu, and routes user input to the appropriate application logic
 *
 * Built with C++ using CMake
 *
 */
#include"../TaskLib/Task.h"
#include"../MenuLib/Menu.h"
#include"../TaskManagerLib/TaskManager.h"
#include<iostream>

int main() {
	try {
		TaskManager obj;
		obj.setPathToFile("TasksToDo.txt");
		obj.loadFromFile();
		while (true) {
			Menu::clearScreen();
			Menu firstMenu("Welcome to Task Manager", { "Add Task",
														"Delete Task",
														"Show All Tasks",
														"Show Completed Tasks",
														"Show InProgress Tasks",
														"Show UnDone Tasks",
														"Edit Task Name",
														"Edit Task Description",
														"Edit Task Priority",
														"Edit Task Status",
														"Exit" });
			int firstOption = firstMenu.showMenu();

			switch (firstOption) {
			case 0:
				Menu::clearScreen();
				obj.addTask();
				Menu::pauseScreen();
				break;

			case 1:
				Menu::clearScreen();
				obj.deleteTask();
				Menu::pauseScreen();
				break;

			case 2:
				Menu::clearScreen();
				obj.showAll();
				Menu::pauseScreen();
				break;

			case 3:
				Menu::clearScreen();
				obj.showCompleted();
				Menu::pauseScreen();
				break;

			case 4:
				Menu::clearScreen();
				obj.showInProgress();
				Menu::pauseScreen();
				break;

			case 5:
				Menu::clearScreen();
				obj.showUnDone();
				Menu::pauseScreen();
				break;

			case 6:
				Menu::clearScreen();
				obj.editTaskName();
				Menu::pauseScreen();
				break;

			case 7:
				Menu::clearScreen();
				obj.editTaskDescription();
				Menu::pauseScreen();
				break;

			case 8:
				Menu::clearScreen();
				obj.editTaskPriority();
				Menu::pauseScreen();
				break;

			case 9:
				Menu::clearScreen();
				obj.editTaskStatus();
				Menu::pauseScreen();
				break;

			case 10:
				obj.saveToFile();
				return 0;
			}
		}
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}