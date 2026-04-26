/******************************************************************************
*
* Int_DataType.cpp :  integer data type testing
*
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "BaseIntType.h"
#include "Helper.inc"
using namespace std;


const vector<std::string> BaseIntType::BaseIntMenu = {
		string("**************************************\n\t \
Hello to C++ Integer Data tutorial. Menu selection: \n\n"),
		string("\tQuit                   0\n"),
		string("\tChar                   1\n"),
		string("\tUnsigned Char          2\n"),
		string("\tShort                  3\n"),
		string("\tUnsigned Short         4\n"),
		string("\tInteger                5\n"),
		string("\tUnsigned Integer       6\n"),
		string("\tLong                   7\n"),
		string("\tUnsigned Long          8\n"),
		string("\tLong Long              9\n"),
		string("\tUnsigned Long Long    10\n")
};

BaseIntType::BaseIntType(IntDataType_t& t) : baseInt(t)
{
}
 
std::string BaseIntType::toString() const 
{
	std::ostringstream os;

	os << "Integer Data Types structure.\n";
	os << "Name    Type     Size     Value       Min			  Max\n";

		//    every name....................
		// "Select Update [1]  Quit [9].  Enter:  "   
		// @return: "

	return os.str();
}


void BaseIntType::processBaseIntMenu()
{
	while (true)
	{
		IntType_e cmd = displayBaseIntMenu();
		if (cmd == IntType_e::QUIT)
		{
			break;
		}

		switch (cmd) {
		case IntType_e::SHORT:
				std::cout << "SHORT.\n";
				break;

		case IntType_e::USHORT:
			std::cout << "USHORT.\n";
			break;

		case IntType_e::INT:
			std::cout << "INT.\n";
			break;

		case IntType_e::UINT:
			std::cout << "UINT.\n";
			break;

		case IntType_e::LONG:
			std::cout << "LONG.\n";
			break;

		case IntType_e::ULONG:
			std::cout << "ULONG.\n";
			break;

		case IntType_e::LLONG:
			std::cout << "LLONG.\n";
			break;

		case IntType_e::ULLONG:
			std::cout << "ULLONG.\n";
			break;

		default:
			std::cout << "INVALID INPUT\n";
		}
	}

	return;

/*
	intOper = NO_OPERATION;

	while (intOper != QUIT)
	{
		// read command from console
		readIntDTCmd();

		switch (intOper) {
		case QUIT:
			return;
	
		case SETUP_DATA:
		{
			IntDataSt_t intVals = { -10000, 10000, -100000, 100000, -1000000, 1000000 };
			IntDataType objIntDT(intVals);
			//	.setData(intVals);
			objIntDT.set();
		}
		break;

		case DISPLAY_DATA:
			std::cout << toString();
			break;

		default:
			break;
		}

		intOper = NO_OPERATION;
	}
*/
}
 

BaseIntType::IntType_e BaseIntType::displayBaseIntMenu() const
{
	IntType_e ret = IntType_e::INVALID;
	int id = static_cast<int> (IntType_e::INVALID);

	while (true) {
		system("cls");
		for (std::string it : BaseIntType::BaseIntMenu)
		{
			std::cout << it;
		}
		
		std::cout << "Select option {" << std::to_string(QUIT) << "..." <<
			std::to_string(ULLONG) << "}:  ";

		std::cin >> id;
		if (validateMinMax<int>(QUIT, ULLONG, id) == false)
		{
			continue;
		}

		ret = static_cast<IntType_e> (id);
		break;
	}

	return ret;
}