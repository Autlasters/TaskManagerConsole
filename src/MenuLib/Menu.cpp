/*
 * Menu.cpp
 *
 * Here is the Menu class logic implemented, handling console rendering, keyboard input, and user navigation within text-based menus
 *
 * Built with C++ using CMake
 *
 */
#include"Menu.h"
#include"iostream"
#include<conio.h>

//The constructor of the class
Menu::Menu(const std::string& Title, const std::vector<std::string>& Options) : Title(Title), Options(Options) {}

//Method to clear the console
void Menu::clearScreen() {
	system("cls");
}

//Method to pause the console
void Menu::pauseScreen() {
	system("pause");
}

//Methd to show the menu
int Menu::showMenu() {
	char button;
	while (true) {
		clearScreen();
		std::cout << "================" << Title << "================" << std::endl;
		for (size_t i = 0; i < Options.size(); ++i) {
			if (i == Selected) {
				std::cout << "[" << "+" << "]" << Options[i] << std::endl;
			}
			else {
				std::cout << "[" << " " << "]" << Options[i] << std::endl;
			}
		}
		button = _getch();
		if (button == 72 || button == 'w') Selected = (Selected - 1 + Options.size()) % Options.size();
		else if (button == 80 || button == 's') Selected = (Selected + 1) % Options.size();
		else if (button == '\r') return Selected;
	}
}