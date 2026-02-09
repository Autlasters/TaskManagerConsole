/*
 * Task.h
 *
 * Declares the Task class, which represents a single task entity
 * The class stores task metadata such as name, description, priority, and status
 *
 * Built with C++ using CMake
 * 
 */
#pragma once
#include<string>
enum enumPriority { NoPriority, Low, Medium, High };
enum enumStatus { Done, InProgress, UnDone };

class Task {
protected:
	std::string Name;
	std::string Description;
	enumPriority Priority;
	enumStatus Status;
public:
	Task();
	Task(const std::string& Name, const std::string& newDescription);
	void setName(const std::string& Name);
	void setDescription(const std::string& Description);
	void setPriority(const enumPriority Priority);
	void setStatus(const enumStatus Status);
	std::string getName() const;
	std::string getDescription() const;
	std::string getPriority() const;
	std::string getStatus() const;
	void printTask() const;
};
