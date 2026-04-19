/******************************************************************************
*
* Int_DataType.cpp :  integer data type testing
*
******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include "DataType.inc"
#include "Helper.inc"
using namespace std;


IntDataType::IntDataType(const IntType_t& t) : intType(t)
{}

void IntDataType::commandMenu()
{
	displayIntDataTypeMenu();
	readIntDataTypeCommand();

	IntType_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
	IntDataType intDataVar(intVals);

	switch (intOper) {
	case QUIT_INT:
				break;

	case SETUP_DATA:
				{
					IntType_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
					intDataVar.setData(intVals);
				}
				break;

	case DISPLAY_DATA:
				std::cout << intDataVar.toString();
				break;

	default:
				break;
	}
}  


std::string IntDataType::toString() const
{
	std::string ret;

	DisplayIntValue<short> disp1(intType.sVar);
	disp1.displayHeader();
	disp1.displayIntValue("sVar");
 
	DisplayIntValue<unsigned short> disp2(intType.usVar);
	disp2.displayIntValue("usVar");

	DisplayIntValue<int> disp3(intType.iVar);
	disp3.displayIntValue("iVar");

	DisplayIntValue<unsigned int> disp4(intType.uiVar);
	disp4.displayIntValue("uiVar");

	DisplayIntValue<long> disp5(intType.lVar);
	disp5.displayIntValue("lVar");

	DisplayIntValue<long> disp6(intType.ulVar);
	disp6.displayIntValue("ulVar");

	return ret;
}

bool IntDataType::operation(int op)
{
	return op == 1 ? logicalOperation() : aritmeticOperation();
}

void IntDataType::displayIntDataTypeMenu() const
{
	system("cls");
	std::cout << "**************************************\n"
		<< "\tHello to C++ Integer Data types selection\n\n";
	std::cout << "\tSetup values                            1\n";
	std::cout << "\tDisplay Integer type                    2\n";
	std::cout << "\tInteger type operations                 3\n";
	std::cout << "\tInteger type logic operations           4\n";
	std::cout << "\tInteger test type operations            5\n";
	std::cout << "\tInteger test type logical operations    6\n";
	std::cout << "\tQuit                                    9\n";
	std::cout << "Select options to contiunue {1,...6, 9}:\n";
}

void IntDataType::readIntDataTypeCommand()
{
	while (true) {
		int ret = 0;
		std::cin >> ret;
		intOper = (IntDataOpType_t)ret;

		if (intOper == QUIT_INT ||
			validateMinMax<IntDataOpType_t>(SETUP_DATA, TEST_LOGIC_OPER, intOper) == true)
		{
			break;
		}
	}
}
