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

static const HeadIntEntryOff_s headIntEtyOff;


BaseIntType::BaseIntType(IntDataType_t& t) : baseInt(t)
{}

std::string BaseIntType::toString() const
{
	ostringstream os;

	os << "Display int type structure:\n";
	os << displayIntToStringHead();
	os << displayIntValue<char>("cVar", baseInt.cVar);
	os << displayIntValue<unsigned char>("ucVar", baseInt.ucVar);
	os << displayIntValue<short>("shVar", baseInt.shVar);
	os << displayIntValue<unsigned short>("ushVar", baseInt.ushVar);
	os << displayIntValue<int>("iVar", baseInt.iVar);
	os << displayIntValue<unsigned int>("uiVar", baseInt.uiVar);
	os << displayIntValue<long>("lVar", baseInt.lVar);
	os << displayIntValue<unsigned long>("ulVar", baseInt.ulVar);
	os << displayIntValue<long long>("llVar", baseInt.llVar);
	os << displayIntValue<unsigned long long>("ullVar", baseInt.ullVar);
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
C++ Integer Data tutorial. Menu selection: \n\n"),

		std::cout << toString();

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

std::string BaseIntType::displayIntToStringHead() const
{
	char buffer[80]; 

	std::fill(std::begin(buffer), std::end(buffer), ' ');
	buffer[79] = 0;

	memcpy(&buffer[headIntEtyOff.hdIntNameOff], "Name", strlen("Name"));
	memcpy(&buffer[headIntEtyOff.hdIntValueOff], "Value", strlen("Value"));
	memcpy(&buffer[headIntEtyOff.hdIntTypeOff], "Type", strlen("Type"));
	strcpy(&buffer[headIntEtyOff.hdIntSizeOff], "Size");
	strcat(buffer, "\n");

	return string(buffer);
}

template <typename T> std::string displayIntValue(const std::string& name, const T& t)
{
	char buffer[80];

	std::fill(std::begin(buffer), std::end(buffer), ' ');
	buffer[79] = 0;

	std::string tValue = std::to_string(t);
	std::string tType = getTypeAsString<T>(t);
	std::string len = std::to_string(sizeof(T));

	memcpy(&buffer[headIntEtyOff.hdIntNameOff], name.c_str(), name.size());
	memcpy(&buffer[headIntEtyOff.hdIntValueOff], tValue.c_str(), tValue.size());
	memcpy(&buffer[headIntEtyOff.hdIntTypeOff], tType.c_str(), tType.size());
	strcpy(&buffer[headIntEtyOff.hdIntSizeOff], len.c_str());
	strcat(buffer, "\n");

	return buffer;
}

template std::string displayIntValue<unsigned short>(const std::string& name, 
																	const unsigned short& t);
template std::string displayIntValue<short>(const std::string& name, const short& t);