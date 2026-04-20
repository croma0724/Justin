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


IntDataType::IntDataType(const IntDataSt_t& t) : intType(t)
{}

int IntDataType::commandMenu()
{
	int ret = 0;
	displayIntDTMenu();
	readIntDataTypeCommand();

	IntDataSt_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
	IntDataType intDataVar(intVals);

	switch (intOper) {
	case QUIT:
				intOper = NO_OPERATION;
				ret = QUIT;
				break;

	case SETUP_DATA:
				{
					IntDataSt_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
					intDataVar.setData(intVals);
				}
				break;

	case DISPLAY_DATA:
				std::cout << intDataVar.toString();
				break;

	default:
				break;
	}

	intOper = NO_OPERATION;
	if (ret != QUIT)
	{
		ret = 0;
	}

	return ret;
}  

void IntDataType::setData(const IntDataSt_t& t)
{
	displayIntDataLimits();
	intType = t;
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

void IntDataType::readIntDTCmd()
{
	while (true)
	{
		displayIntDTMenu();

		// Read command
		std::cin >> menuId;

		if (menuId == QUIT ||
			validateMinMax<int>(SETUP_DATA, TEST_LOGIC_OPER, menuId) == true)
		{
			intOper = (IntDTOper_t)menuId;
			menuId = 0;
			break;
		}
	}
}

void IntDataType::displayIntDTMenu() const
{
	system("cls");
	std::cout << "**************************************\n"
		<< "\tHello to C++ Integer Data tutorial. Menu selection: \n\n";
	std::cout << "\tSetup values                            1\n";
	std::cout << "\tDisplay Integer type                    2\n";
	std::cout << "\tInteger type operations                 3\n";
	std::cout << "\tInteger type logic operations           4\n";
	std::cout << "\tInteger test type operations            5\n";
	std::cout << "\tInteger test type logical operations    6\n";
	std::cout << "\tQuit                                    9\n\n";

	std::cout << "Select option {" << std::to_string(SETUP_DATA) << "..." <<
		std::to_string(TEST_LOGIC_OPER) << ", " << std::to_string(QUIT) << "}:  ";
}

void IntDataType::readIntDataTypeCommand()
{
	while (true) {
		int ret = 0;
		std::cin >> ret;
		intOper = (IntDTOper_t)ret;

		if (intOper == QUIT ||
			validateMinMax<IntDTOper_t>(SETUP_DATA, TEST_LOGIC_OPER, intOper) == true)
		{
			break;
		}
	}
}

void IntDataType::displayIntDataLimits() const
{
	system("cls");
	std::cout << "C++ update integer types:\n";
	std::cout << "\tinteger size: [" << sizeof(int) << "] bytes. Min / max values :       [" <<
		std::numeric_limits<int>::min() << ", " <<
		std::numeric_limits<int>::max() << "]\n";
	std::cout << "\tunsigned integer size: [" << sizeof(unsigned int) << "]  bytes. Min/max values:  [" <<
		std::numeric_limits<unsigned int>::min() << ", " <<
		std::numeric_limits<unsigned int>::max() << "]\n";

	std::cout << "\tshort size: [" << sizeof(short) << "] bytes. Min / max values :         [" <<
		std::numeric_limits<short>::min() << ", " <<
		std::numeric_limits<short>::max() << "]\n";
	std::cout << "\tunsigned short size: [" << sizeof(unsigned short) << "] bytes. Min/max values:    [" <<
		std::numeric_limits<unsigned short>::min() << ", " <<
		std::numeric_limits<unsigned short>::max() << "]\n";

	std::cout << "\tlong size: [" << sizeof(long) << "] bytes. Min/max values:             [" <<
		std::numeric_limits<long>::min() << ", " <<
		std::numeric_limits<long>::max() << "]\n";
	std::cout << "\tunsigned long size: [" << sizeof(unsigned long) << "] bytes. Min/max values:     [" <<
		std::numeric_limits<unsigned long>::min() << ", " <<
		std::numeric_limits<unsigned long>::max() << "]\n";
}
