/*
 * Task.cpp
 *
 * This .cpp file implements the Task class logic, including task state management and console output functionality
 *
 * Built with C++ using CMake
 * 
 */
#include"Task.h"
#include<iostream>

//The Constructor of the class 
Task::Task(const std::string& Name, const std::string& newDescription) : Name(Name),
Description(newDescription),
Priority(enumPriority::NoPriority),
Status(enumStatus::UnDone)
{
}

//The default Constructor of the class
Task::Task() : Name(""), Description(""), Priority(enumPriority::NoPriority), Status(enumStatus::UnDone) {}

//Method to set the name of a task
void Task::setName(const std::string& Name) {
	this->Name = Name;
}

//Method to set the description of a task
void Task::setDescription(const std::string& Description) {
	this->Description = Description;
}

//Method to set the priority of a task
void Task::setPriority(const enumPriority Priority) {
	this->Priority = Priority;
}

//Method to set the status of a task
void Task::setStatus(const enumStatus Status) {
	this->Status = Status;
}

//Method to get the status of a task
std::string Task::getStatus() const {
	switch (Status) {
	case InProgress:
		return "InProgress";
	case Done:
		return "Done";
	case UnDone:
		return "UnDone";
	default:
		return "Unknown";
	}
}

//Method to get the name of a task
std::string Task::getName() const {
	return Name;
}

//Method to get the description of a task
std::string Task::getDescription() const {
	return Description;
}

//Method to get the priority of a task
std::string Task::getPriority() const {
	switch (Priority) {
	case NoPriority:
		return "NoPriority";
	case Low:
		return "Low";
	case Medium:
		return "Medium";
	case High:
		return "High";
	default:
		return "Unknown";
	}
}

//Method to display the task's details
void Task::printTask() const {
	std::cout << "Task Name: " << this->Name << std::endl;
	std::cout << "Description: " << this->Description << std::endl;
	std::cout << "Priority: " << getPriority() << std::endl;
	std::cout << "Status: " << getStatus() << std::endl;
}
