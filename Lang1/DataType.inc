/******************************************************************************
*
* DataType.inc :  
*
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include "DataType.h"
using namespace std;

void IntDataType::setData(const IntType_t& t) 
{
	intType = t;
}

template <typename T>
DisplayIntType<T>::DisplayIntType(T t) : val(t)
{
}

template <typename T>
void DisplayIntType<T>::displayHeader() const
{
	char lineBuff[LineSz];
	memset(lineBuff, ' ', LineSz-2);
	lineBuff[LineSz-1] = 0x0;

	memcpy(&lineBuff[NameOff], "Name:", sizeof("Name:") -1);
	memcpy(&lineBuff[DecOff], "Decimal", sizeof("Decimal") -1);
	memcpy(&lineBuff[HexOff], "Hex", sizeof("Hex") -1);
	memcpy(&lineBuff[BinOff], "Binary", sizeof("Binary"));
	
	std::cout << lineBuff << "\n";
}

template <typename T>
void DisplayIntType<T>::displayInt(const std::string& name) const
{
	char lineBuff[LineSz];
	memset(lineBuff, ' ', LineSz-2);
	lineBuff[LineSz-1] = 0x0;

	std::stringstream ss;
	std::string str;

	memcpy(&lineBuff[NameOff], name.data(), name.size());
	
	ss << val;
	str = ss.str();
	memcpy(&lineBuff[DecOff], str.data(), str.size());

	ss.str("");
	ss << "0x" << hex << val;
	str = ss.str();
	memcpy(&lineBuff[HexOff], str.data(), str.size());

	str = std::bitset<32>(val).to_string(); 
	memcpy(&lineBuff[BinOff], str.data(), str.size());
	lineBuff[BinOff + 32] = 0x0; 
	
	std::cout << lineBuff << "\n";
}