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

void DataType::commandMenu()
{
	displayDataTypeMenu();
	readDataTypeCommand();

	switch (oper) {
	case QUIT_TYPE:
				break;

	case INTDATA_TYPE:
				{
					IntType_t intVals = {-10000, 10000, -100000, 100000, -1000000, 1000000};
					IntDataType intType(intVals);
					intType.commandMenu();
				}
				break;

	default:
				break;
	}
}


void DataType::displayDataTypeMenu() const
{
	system("cls");
	std::cout << "**************************************\n"
		<< "\tHello to C++ selection operation\n\n";
	std::cout << "\tInteger Data                            1\n";
	std::cout << "\tFloat Data                              2\n";
	std::cout << "\tCharacter Data                          3\n";
	std::cout << "\tArray Data                              4\n";
	std::cout << "\tString Data                             5\n";
	std::cout << "\tQuit                                    9\n";
	std::cout << "Select options to contiunue {1,...5, 9}:\n";
}

void DataType::readDataTypeCommand()
{
	while (true) {
		int ret = 0;
		std::cin >> ret;
		oper = (DataTypeOp_t)ret;

		if (oper == QUIT_TYPE ||
			  validateMinMax<DataTypeOp>(INTDATA_TYPE, STRING_TYPE, oper) == true)
		{
			break;
		}
	}
}