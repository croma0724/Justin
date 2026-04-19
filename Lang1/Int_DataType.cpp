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

int IntDataType::commandMenu() const
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

	int ret = 0;
	bool loop = true;
	while (true) {
		std::cin >> ret;

		if (ret == (int)QUIT)
		{
			break;
		}

		loop = !validateMinMax<int>((int)SETUP_DATA, (int)TEST_LOGIC_OPER, ret);
		if (loop == false)
		{
			break;
		}
	}

	return ret;
}

std::string IntDataType::toString() const
{
	std::string ret;

	DisplayIntType<short> disp1(intType.sVar);
	disp1.displayHeader();
	disp1.displayInt("sVar");
 
	DisplayIntType<unsigned short> disp2(intType.usVar);
	disp2.displayInt("usVar");

	DisplayIntType<int> disp3(intType.iVar);
	disp3.displayInt("iVar");

	DisplayIntType<unsigned int> disp4(intType.uiVar);
	disp4.displayInt("uiVar");

	DisplayIntType<long> disp5(intType.lVar);
	disp5.displayInt("lVar");

	DisplayIntType<long> disp6(intType.ulVar);
	disp6.displayInt("ulVar");

	return ret;
}

bool IntDataType::operation(int op)
{
	return op == 1 ? logicalOperation() : aritmeticOperation();
}

string IntDataType::displayToStringHeader() const
{
	std::string ret("      ");
	ret += "Var:    ";
	ret += "Decimal     ";
	ret += "Hex         ";
	ret += "Binary      ";

	ret += "\n";
	return ret;  
}
