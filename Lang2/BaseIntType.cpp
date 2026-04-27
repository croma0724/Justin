/******************************************************************************
*
* Int_DataType.cpp :  integer data type testing
*
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "Helper.inc"
#include "BaseIntType.h"
#include "BaseIntType.inc"
using namespace std;

const vector<std::string> BaseIntType::BaseIntMenu = {
		string("    Quit                              0\n"),
		string("    Char                              1\n"),
		string("    Unsigned Char                     2\n"),
		string("    Short                             3\n"),
		string("    Unsigned Short                    4\n"),
		string("    Integer                           5\n"),
		string("    Unsigned Integer                  6\n"),
		string("    Long                              7\n"),
		string("    Unsigned Long                     8\n"),
		string("    Long Long                         9\n"),
		string("    Unsigned Long Long               10\n")
};

static const HeadIntEntryOff_s headIntEtyOff;


BaseIntType::BaseIntType(IntDataType_t& t) : baseInt(t)
{}

std::string BaseIntType::toString() const
{
	ostringstream os;
	HelperIntType<int> itype;

	os << "Display int type structure:\n";

	os << itype.displayIntOpt();
	os << HelperIntType<char>::displayIntValue("cVar", baseInt.cVar);
	os << HelperIntType<unsigned char>::displayIntValue("ucVar", baseInt.ucVar);
	os << HelperIntType<short>::displayIntValue("shVar", baseInt.shVar);
	os << HelperIntType<unsigned short>::displayIntValue("shVar", baseInt.ushVar);
	os << HelperIntType<int>::displayIntValue("iVar", baseInt.iVar);
	os << HelperIntType<unsigned int>::displayIntValue("uiVar", baseInt.uiVar);
	os << HelperIntType<long>::displayIntValue("lVar", baseInt.lVar);
	os << HelperIntType<long>::displayIntValue("ulVar", baseInt.ulVar);
	os << HelperIntType<long long>::displayIntValue("llVar", baseInt.llVar);
	os << HelperIntType<unsigned long long>::displayIntValue("ullVar", baseInt.ullVar);
	os << "\n\n";

	return os.str();
}

void BaseIntType::processBaseIntMenu()
{
	while (true)
	{
		system("cls");

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
}
 
BaseIntType::IntType_e BaseIntType::displayBaseIntMenu() const
{
	IntType_e ret = IntType_e::INVALID;
	int id = static_cast<int> (IntType_e::INVALID);

	while (true) {
		system("cls");
		std::cout << string("**************************************\n\t Hello to \
C++ Integer Data tutorial.\n\n"),

		std::cout << toString();
		std::cout << "Options:\n";
		for (std::string it : BaseIntType::BaseIntMenu)
		{
			std::cout << it;
		}
		
		std::cout << "Select option {" << std::to_string(QUIT) << "..." <<
			std::to_string(ULLONG) << "}:               ";

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
