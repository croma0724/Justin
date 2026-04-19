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
using namespace std;

Console::Console()
{}

void Console::processInput()
{
	Console::Option ret = getCommand();
	std::cout << "Option: [" << ret << "]\n";

	if (ret == Option::DataOper)
	{
//		NumberType nrType;
//		nrType.testInt();

		IntType_t intType = { -10000, 10000, -1000000, 1000000, -10000000, 10000000 };
		IntDataType intObj(intType);
		IntDataType::IntDataOpType_t retop = (IntDataType::IntDataOpType_t) intObj.commandMenu();
		cout << "Options........[" << retop << "]\n";

		switch (retop) {
		case IntDataType::SETUP_DATA:
					{
						IntType_t	t = { -20000, 20000, -2000000, 2000000, -20000000, 20000000 };
						intObj.setData(t);
					}
					break;

		case IntDataType::DISPLAY_DATA:
					std::cout << intObj.toString();
					break;

		default:
					break;
		}


	}
}

Console::Option Console::getCommand() const
{
	Option ret = Option::Quit;

	bool loop = true;
	while (loop) {
		system("cls");

		std::cout << "**************************************\n"
			<< "\tHello to C++ Tutorial\n\n";
		std::cout << "Select options to contiunue:\n";
		std::cout << "\tData Type              1\n";
		std::cout << "\tString                 2\n";
		std::cout << "\tPointers               3\n";
		std::cout << "\tMemory                 4\n";
		std::cout << "\tQuit                   10\n";

		std::cout << "\nEnter option {1, ...10}:  ";
		int opt;
		cin >> opt;

		if (opt == Option::DataOper ||
			opt == Option::StringOper ||
			opt == Option::Pointers ||
			opt == Option::Memory ||
			opt == Option::Quit)
		{
			ret = (Option)opt;
			loop = false;
		}
	}

	return ret;
}
