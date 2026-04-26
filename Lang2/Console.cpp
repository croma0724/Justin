/******************************************************************************
* 
* Console.cpp : process user commands 
* 
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include "Console.h"
#include "BaseDataType.h"
#include "Helper.inc"
using namespace std;


const vector<std::string> Console::ConsoleMenuStr = {
		string("**************************************\n\t \
Hello to C++ Tutorial. Menu selection:\n\n"),
		string("\tQuit                   0\n"),
		string("\tData Type              1\n"),
		string("\tString                 2\n"),
		string("\tMemory                 3\n"),
		string("\tClass                  4\n"),
};
	
Console::Console()
{}

void Console::processMainMenu()
{
	while (true)
	{
		Cons_e cmd = displayMainMenu();
		if (cmd == Cons_e::QUIT)
		{
			break;
		}

		switch (cmd) {
		case DATA_MENU:
			{
				BaseDataType  dtype;
				dtype.processBasicDataTypeMenu();
			}
			break;

		case STRING_MENU:
			std::cout << "STRING_MENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case MEMORY_MENU:
			std::cout << "MEMORY_MENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case CLASS_MENU:
			std::cout << "CLASS_MENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		default:
			break;
		}
	}
}

Console::Cons_e Console::displayMainMenu() const
{
	Cons_e ret = Cons_e::INVALID;
	int id = static_cast<int> (Cons_e::INVALID);

	while (true) {
		system("cls");
		for (std::string it : Console::ConsoleMenuStr)
		{
			std::cout << it;
		}

		std::cout << "Select option {" << std::to_string(QUIT) << "..." <<
			std::to_string(CLASS_MENU) << "}:  ";

		std::cin >> id;
		if (validateMinMax<int>(QUIT, CLASS_MENU, id) == false)
		{
			std::cout << "\nError, invalid option: [" << id << "]\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		ret = static_cast<Cons_e> (id);
		break;
	}

	return ret;
}