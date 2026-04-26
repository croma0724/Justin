/******************************************************************************
* 
* Console.cpp : process user commands 
* 
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "Console.h"
#include "BaseDataType.h"
//#include "Int_DataType.h"
#include "Helper.inc"
using namespace std;

static const std::string ErrMsg("Error Console menu selection, invalid ID: ");

Console::Console()
{}

void Console::processMainMenu()
{
	int menuId = 0;

	while (true)
	{
		std::cout << displayMainMenu();

		// read command from console
		std::cin >> menuId;
		if (menuId == QUIT)
			return;

		if (validateMinMax<int>(DATA_MENU, CLASS_MENU, menuId) == false)
		{
			continue;
		}

		switch (menuId) {
		case DATA_MENU:
			{
				BaseDataType  dtype;
				dtype.processBasicDataTypeMenu();
			}
			break;

		default:
			break;
		}
	}
}

std::string Console::displayMainMenu() const
{
	system("cls");
	std::ostringstream os;
	os << "**************************************\n"
						<< "\tHello to C++ Tutorial. Menu selection:\n\n";
	os << "Select options to continue:\n";
	os << "\tData Type              1\n";
	os << "\tString                 2\n";
	os << "\tMemory                 3\n";
	os << "\tClass                  4\n";
	os << "\tQuit                   9\n\n";
	os << "Select option {" << std::to_string(DATA_MENU) << "..." <<
		std::to_string(CLASS_MENU) << ", " << std::to_string(QUIT) << "}:  ";

	return os.str();
}