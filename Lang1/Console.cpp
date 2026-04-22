/******************************************************************************
* 
* Console.cpp : process user commands 
* 
******************************************************************************/
#include <iostream>
#include <string>
#include "Console.h"
#include "DataType.h"
#include "Int_DataType.h"
#include "Helper.inc"
using namespace std;

static const std::string ErrMsg("Error Console menu selection, invalid ID: ");

Console::Console() : consOper(NO_OPERATION), menuId(0)
{}

void Console::processConsoleCmd()
{
	consOper = NO_OPERATION;

	while (consOper != QUIT)
	{
		// read command from console
		readConsoleCmd();
		
		switch (consOper) {
		case QUIT:
			// Exit function.
			return;

		case DATA_MENU:
			{
				DataType  dtype;
				dtype.processDataTypeCmd();
			}
			break;

		default:
			break;
		}
	}
}

void Console::readConsoleCmd()
{
	while (true)
	{
		displayConsoleMenu();

		// Read command
		int menuId;
		std::cin >> menuId;
	
		if (menuId == QUIT ||
			validateMinMax<int>(DATA_MENU, CLASS_MENU, menuId) == true)
		{
			consOper = (ConsMenu_t)menuId;
			break;
		}
	}
}

void Console::displayConsoleMenu() const
{
	system("cls");
	std::cout << "**************************************\n"
						<< "\tHello to C++ Tutorial. Menu selection:\n\n";
	if (menuId)
	{
		std::cout << ErrMsg << std::to_string(menuId) << "\n\n";
	}
	std::cout << "Select options to contiunue:\n";
	std::cout << "\tData Type              1\n";
	std::cout << "\tString                 2\n";
	std::cout << "\tMemory                 3\n";
	std::cout << "\tClass                  4\n";
	std::cout << "\tQuit                   9\n\n";
	std::cout << "Select option {" << std::to_string(DATA_MENU) << "..." << 
		std::to_string(CLASS_MENU) << ", " << std::to_string(QUIT) << "}:  ";
}