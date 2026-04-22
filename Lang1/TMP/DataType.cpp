/******************************************************************************
*
* DataType.cpp : data types declarations
*
******************************************************************************/

#include <iostream> 
#include <string>
#include <limits>
#include <bitset>
#include "DataType.h"
using namespace std;


NumberType::NumberType() : intTypes(0, 0, 0, 0, 0, 0), floatTypes(0.0, 0.0)
{}

void NumberType::setInts(const NumberType::IntTypes_t& ints)
{
	intTypes.iVar		= ints.iVar;
	intTypes.uiVar	= ints.uiVar;
	intTypes.sVar		= ints.sVar;
	intTypes.usVar	= ints.usVar;
	intTypes.lVar		= ints.lVar;
	intTypes.ulVar	= ints.ulVar;
}


NumberType:: Option NumberType::selectProcessing()
{
	system("cls");
	std::cout << "**************************************\n"
		<< "\tHello to C++ Data types selection\n\n";
	std::cout << "Select options to contiunue {1,...6, 9}:\n";
	std::cout << "\tDisplay Integer type     1\n";
	std::cout << "\tInteger type operations  2\n";
	std::cout << "\tInteger type logic op    3\n";
	std::cout << "\tDisplay Float type       4\n";
	std::cout << "\tFloat type operations    5\n";
	std::cout << "\tCharacter operations     6\n";
	std::cout << "\tQuit                     9\n";

	std::cout << "\nEnter option {1,...6, 9}:  ";
	int opt;
	cin >> opt;
	return (NumberType::Option) opt;
}

void NumberType::displayIntFormat() const
{
	system("cls");
	std::cout << "C++ integer number types:\n";

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

	intTypes.iVar = -100000;
	intTypes.uiVar = 100000;
	intTypes.sVar = -10000;
	intTypes.usVar = 10000;
	intTypes.lVar = -1000000;
	intTypes.ulVar = 1000000;

	std::cout << "\nDisplay Int:           [" << intTypes.iVar << "]\n";
	std::cout << "\tHex:           [" << "0x" << hex << intTypes.iVar << "]\n";
	std::cout << "\tBinary:        [" << std::bitset<32>(intTypes.iVar) << "]\n";
	std::cout << "Display Unsigned Int   [" << dec << intTypes.uiVar << "]\n";
	std::cout << "\tHex:           [" << "0x" << hex << intTypes.uiVar << "]\n";
	std::cout << "\tBinary:        [" << std::bitset<32>(intTypes.uiVar) << "]\n";

	std::cout << "\nDisplay Short:         [" << dec << intTypes.sVar << "]\n";
	std::cout << "\tHex:           [" << "0x" << hex << intTypes.sVar << "]\n";
	std::cout << "\tBinary:        [" << std::bitset<32>(intTypes.sVar) << "]\n";
	std::cout << "Display Unsigned Short [" << dec << intTypes.usVar << "]\n";
	std::cout << "\tHex:           [" << "0x" << hex << intTypes.usVar << "]\n";
	std::cout << "\tBinary:        [" << std::bitset<32>(intTypes.usVar) << "]\n";
}