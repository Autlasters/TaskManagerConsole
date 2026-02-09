/*
 * TaskManager.cpp
 *
 * This .cpp file implements the TaskManager class logic, handling task collection management, file persistence
 *
 * Built with C++ using CMake
 *
 */
#include"TaskManager.h"
#include"../MenuLib/Menu.h"
#include<iostream>
#include<vector>
#include<memory>
#include<sstream>

//Method to set the name of a task
void TaskManager::setTaskName() {
	std::string Name;
	std::cout << "Input The Task Name: ";
	std::getline(std::cin, Name);
	taskOfVector->setName(Name);
}

//Method to edit the name of a task
void TaskManager::editTaskName() {
	int index;
	std::string Name;
	std::cout << "Input The Index Of The Task: ";
	std::cin >> index;
	if (index >= 0 && index < Tasks.size()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input The New Name Of The Task: ";
		std::getline(std::cin, Name);
		Tasks[index]->setName(Name);
		saveToFile();
	}
	else {
		std::cout << "Invalid Index" << std::endl;
	}
}

//Method to set the description of a task
void TaskManager::setTaskDescription() {
	std::string Description;;
	std::cout << "Input The Task Description: ";
	std::getline(std::cin, Description);
	taskOfVector->setDescription(Description);
}

//Method to edit the description of a task
void TaskManager::editTaskDescription() {
	int index;
	std::string Description;
	std::cout << "Input The Index Of The Task: ";
	std::cin >> index;
	if (index >= 0 && index < Tasks.size()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input The New Description Of The Task: ";
		std::getline(std::cin, Description);
		Tasks[index]->setDescription(Description);
		saveToFile();
	}
	else {
		std::cout << "Invalid Index" << std::endl;
	}
}

//Method to set the priority of a task
void TaskManager::setTaskPriority() {
		Menu::clearScreen();
		Menu priorityMenu("Set The Priority", { "Low", "Medium", "High" });
		int priorityOption = priorityMenu.showMenu();
		switch (priorityOption) {
		case 0:
			taskOfVector->setPriority(enumPriority::Low);
			break;
		case 1:
			taskOfVector->setPriority(enumPriority::Medium);
			break;
		case 2:
			taskOfVector->setPriority(enumPriority::High);
			break;
		}
}

//Method to edit the priority of a task
void TaskManager::editTaskPriority() {
	int index;
	std::cout << "Input The Index Of The Task: ";
	std::cin >> index;
	if (index >= 0 && index < Tasks.size()) {
		Menu::clearScreen();
		Menu priorityMenu("Set The Priority", { "Low", "Medium", "High" });
		int priorityOption = priorityMenu.showMenu();
		switch (priorityOption) {
		case 0:
			Tasks[index]->setPriority(enumPriority::Low);
			break;
		case 1:
			Tasks[index]->setPriority(enumPriority::Medium);
			break;
		case 2:
			Tasks[index]->setPriority(enumPriority::High);
			break;
		}
		saveToFile();
	}
	else {
		std::cout << "Invalid Index" << std::endl;
	}
}

//Method to set the status of a task
void TaskManager::setTaskStatus() {
		Menu::clearScreen();
		Menu statusMenu("Set The Status", { "Done", "InProgress" });
		int statusOption = statusMenu.showMenu();
		switch (statusOption) {
		case 0:
			taskOfVector->setStatus(enumStatus::Done);
			break;
		case 1:
			taskOfVector->setStatus(enumStatus::InProgress);
			break;
		}
}

//Method to edit the status of a task
void TaskManager::editTaskStatus() {
	int index;
	std::cout << "Input The Index Of The Task: ";
	std::cin >> index;
	if (index >= 0 && index < Tasks.size()) {
		Menu::clearScreen();
		Menu statusMenu("Set The Status", { "Done", "InProgress" });
		int statusOption = statusMenu.showMenu();
		switch (statusOption) {
		case 0:
			Tasks[index]->setStatus(enumStatus::Done);
			break;
		case 1:
			Tasks[index]->setStatus(enumStatus::InProgress);
			break;
		}
		saveToFile();
	}
	else {
		std::cout << "Invalid Index" << std::endl;
	}
}

//Method to add the new task
void TaskManager::addTask() {
	setTaskName();
	setTaskDescription();
	setTaskPriority();
	Tasks.push_back(std::move(taskOfVector));
	taskOfVector = std::make_unique<Task>();
}

//Method to delete the new task
void TaskManager::deleteTask() {
	int index;
	std::cout << "Input The Index Of The Task: ";
	std::cin >> index;
	if (index >= 0 && index < Tasks.size()) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index < 0 || index >= Tasks.size()) {
			throw std::runtime_error("Invalid Index");
		}
		else {
			Tasks.erase(Tasks.begin() + index);
		}
	}
	else {
		std::cout << "Invalid Index" << std::endl;
 	}
}

//Method to display all tasks
void TaskManager::showAll() const {
	if (Tasks.size() > 0) {
		for (size_t i = 0; i < Tasks.size(); ++i) {
			std::cout << "Task index: " << "[" << i << "]" << std::endl;
			Tasks[i]->printTask();
		}
	}
	else {
		std::cout << "There Is No Tasks To Do" << std::endl;
	}
}

//Method to display the only completed tasks
void TaskManager::showCompleted() const {
	bool taskIsDone = false;
	if (Tasks.size() > 0) {
		for (const auto& it : Tasks) {
			if (it->getStatus() == "Done") {
				it->printTask();
				taskIsDone = true;
			}
		}
	}
	else {
		std::cout << "There Is No Completed Tasks" << std::endl;
	}
}

//Method to display the only the tasks with the status "In Progress"
void TaskManager::showInProgress() const {
	if (Tasks.size() > 0) {
		bool taskIsInProgress = false;
		for (const auto& it : Tasks) {
			if (it->getStatus() == "InProgress") {
				it->printTask();
				taskIsInProgress = true;
			}
		}
	}
	else {
		std::cout << "There Is No InProgress Tasks" << std::endl;
	}
}

//Method to show the Undone tasks
void TaskManager::showUnDone() const {
	if (Tasks.size() > 0) {
		bool taskIsUnDone = false;
		for (const auto& it : Tasks) {
			if (it->getStatus() == "UnDone") {
				it->printTask();
				taskIsUnDone = true;
			}
		}
	}
	else {
		std::cout << "There Is No UnDone Tasks" << std::endl;
	}
}

//Method to set the path to the file with data or create an empty one
void TaskManager::setPathToFile(const std::string& path) {
	filePath = path;
}

//Method to load data from the file
void TaskManager::loadFromFile() {
	std::ifstream File(filePath);
	if (!File.is_open()) {
		std::ofstream Create(filePath);
		Create.close();
		return;
	}
	Tasks.clear();
	std::string lineToRead;
	while (std::getline(File, lineToRead)) {
		std::stringstream ss(lineToRead);
		std::string nameFromFile, descriptionFromFile, priorityFromFile, statusFromFile;
		std::getline(ss, nameFromFile, ';');
		std::getline(ss, descriptionFromFile, ';');
		std::getline(ss, priorityFromFile, ';');
		std::getline(ss, statusFromFile, ';');
		auto fileTask = std::make_unique<Task>();
		fileTask->setName(nameFromFile);
		fileTask->setDescription(descriptionFromFile);
		if (priorityFromFile == "Low") {
			fileTask->setPriority(enumPriority::Low);
		}
		else if (priorityFromFile == "Medium") {
			fileTask->setPriority(enumPriority::Medium);
		}
		else if (priorityFromFile == "High") {
			fileTask->setPriority(enumPriority::High);
		}
		if (statusFromFile == "Done") {
			fileTask->setStatus(enumStatus::Done);
		}
		else if (statusFromFile == "InProgress") {
			fileTask->setStatus(enumStatus::InProgress);
		}
		else if (statusFromFile == "UnDone") {
			fileTask->setStatus(enumStatus::UnDone);
		}

		Tasks.push_back(std::move(fileTask));
	}
	File.close();
}

//Method to save data to the file
void TaskManager::saveToFile() const {
	std::ofstream File(filePath);
	if (!File.is_open()) {
		throw std::runtime_error("Not Possible To Open The File To Save The Data");
	}
	else {
		for (const auto& obj : Tasks) {
			File << obj->getName() << ";"
				<< obj->getDescription() << ";"
				<< obj->getPriority() << ";"
				<< obj->getStatus() << ";"
				<< std::endl;
		}
	}
	File.close();
}