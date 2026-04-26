/******************************************************************************
*
* Console.cpp : process user commands
*
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "BaseDataType.h"
#include "BaseIntType.h" 
#include "Helper.inc"  

void    BaseDataType::processBasicDataTypeMenu()
{
	int menuId = 0;

	while (true)
	{
		std::cout << displayBDTMenu();

		// read command from console
		std::cin >> menuId;
		if (menuId == QUIT)
			return;

		if (validateMinMax<int>(INT_DTMENU, STRING_DTMENU, menuId) == false)
		{
			continue;
		}

		switch (menuId) {
		case INT_DTMENU:
		{
			IntDataType_t value = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			BaseIntType dtype(value);
			dtype.processBaseIntMenu();
		}
		break;

		default:
			break;
		}
	}
}

std::string BaseDataType::displayBDTMenu() const
{
	std::ostringstream os;

	system("cls");
	os << "**************************************\n"
		<< "\tC++ Basic Data Type menu selection:\n\n";
	os << "\tInteger Data                            1\n";
	os << "\tFloat Data                              2\n";
	os << "\tCharacter Data                          3\n";
	os << "\tArray Data                              4\n";
	os << "\tString Data                             5\n";
	os << "\tQuit                                    9\n\n";
	os << "Select option {" << std::to_string(INT_DTMENU) << "..." <<
		std::to_string(STRING_DTMENU) << ", " << std::to_string(QUIT) << "}:   "; 
		
	return os.str();
}
