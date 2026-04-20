/******************************************************************************
*
* DataType.cpp :  
*
******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "DataType.h"
#include "Int_DataType.h"
#include "Helper.inc"
using namespace std;

static const string ErrMsgDT("Error Data Type menu selection, invalid ID: ");

DataType::DataType() : dataOper(NO_OPERATION), menuId(0)
{}

DataType::DTMenu_t DataType::processDataTypeCmd()
{
	while (dataOper != QUIT)
	{
		// read command from console
		readDTCmd();

		switch (dataOper) {
		case QUIT:
			// Exit function.
			dataOper = NO_OPERATION;
			return QUIT;

		case INTDT_MENU:
		{
			IntDataSt_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
			IntDataType intType(intVals);
			int ret = intType.commandMenu();
			dataOper = ret == QUIT ? QUIT : NO_OPERATION;
		}
		break;

		default:
			break;
		}
	}

	return dataOper;
}

void DataType::readDTCmd()
{
	while (true)
	{
		displayDTMenu();

		// Read command
		std::cin >> menuId;

		if (menuId == QUIT ||
			validateMinMax<int>(INTDT_MENU, STRINGDT_MENU, menuId) == true)
		{
			dataOper = (DTMenu_t)menuId;
			menuId = 0;
			break;
		}
	}
}

void DataType::displayDTMenu() const
{
	system("cls");
	std::cout << "**************************************\n"
		<< "\tHello to C++ Data Type Tutorial. Menu selection:\n\n";

	if (menuId)
	{
		std::cout << ErrMsgDT << std::to_string(menuId) << "\n\n";
	}

	std::cout << "\tInteger Data                            1\n";
	std::cout << "\tFloat Data                              2\n";
	std::cout << "\tCharacter Data                          3\n";
	std::cout << "\tArray Data                              4\n";
	std::cout << "\tString Data                             5\n";
	std::cout << "\tQuit                                    9\n\n";
	std::cout << "Select option {" << std::to_string(INTDT_MENU) << "..." <<
		std::to_string(STRINGDT_MENU) << ", " << std::to_string(QUIT) << "}:  ";
}
