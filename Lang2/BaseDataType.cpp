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
#include "BaseDataType.h"
#include "BaseIntType.h" 
#include "DataTypeIf.h" 
#include "Helper.inc"  

const vector<std::string> BaseDataType::DataTypeMenuStr = {
	string("**************************************\n\tC++ \
Basic Data Type menu selection:\n\n"),
	string("\tQuit                                    0\n"),
	string("\tInteger Data                            1\n"),
	string("\tFloat Data                              2\n"),
	string("\tCharacter Data                          3\n"),
	string("\tArray Data                              4\n"),
	string("\tString Data                             5\n"),
};

BaseDataType::BaseDataType()
{}

void    BaseDataType::processBasicDataTypeMenu()
{
	while (true)
	{
		DTMenu_t cmd = displayBDTMenu();
		if (cmd == DTMenu_t::QUIT)
		{
			break;
		}

		switch (cmd) {
		case INT_DTMENU:
				{
					IntDataType_t value = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
					BaseIntType dtype(value);
					dtype.processBaseIntMenu();
				}
				break;

		case FLOAT_DTMENU:
			std::cout << "FLOAT_DTMENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case CHAR_DTMENU:
			std::cout << "CHAR_DTMENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case ARRAY_DTMENU:
			std::cout << "ARRAY_DTMENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		case STRING_DTMENU:
			std::cout << "STRING_DTMENU\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;

		default:
			break;
		}
	}
}

BaseDataType::DTMenu_t BaseDataType::displayBDTMenu() const
{
	DTMenu_t ret = DTMenu_t::INVALID;
	int id = static_cast<int> (DTMenu_t::INVALID);

	while (true) {
		system("cls");
		for (std::string it : BaseDataType::DataTypeMenuStr)
		{
			std::cout << it;
		}

		std::cout << "Select option {" << std::to_string(QUIT) << "..." <<
			std::to_string(STRING_DTMENU) << "}:  ";

		std::cin >> id;
		if (validateMinMax<int>(QUIT, STRING_DTMENU, id) == false)
		{
			std::cout << "\nError, invalid option: [" << id << "]\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		ret = static_cast<DTMenu_t> (id);
		break;
	}
		
	return ret;
}
