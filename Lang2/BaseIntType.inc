/******************************************************************************
*
* BaseIntType.inc : 
* 
*
******************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <type_traits>
#include "BaseIntType.h"
using namespace std;

template <typename T> 
std::string HelperIntType<T>::displayIntOpt() const
{
	char buffer[80];

	std::fill(std::begin(buffer), std::end(buffer), ' ');
	buffer[79] = 0;

	memcpy(&buffer[IntOff::hdIntNameOff], "Name", strlen("Name"));
	memcpy(&buffer[IntOff::hdIntValueOff], "Value", strlen("Value"));
	memcpy(&buffer[IntOff::hdIntTypeOff], "Type", strlen("Type"));
	strcpy(&buffer[IntOff::hdIntSizeOff], "Size");
	strcat(buffer, "\n");

	return string(buffer);
}

template <typename T> 
std::string HelperIntType<T>::displayIntValue(const std::string& name, const T& t)
{
	char buffer[80];

	std::fill(std::begin(buffer), std::end(buffer), ' ');
	buffer[79] = 0;

	std::string tValue = std::to_string(t);
	std::string tType = getIntTypeAsString(t);
	std::string len = std::to_string(sizeof(T));

	memcpy(&buffer[IntOff::hdIntNameOff], name.c_str(), name.size());
	memcpy(&buffer[IntOff::hdIntValueOff], tValue.c_str(), tValue.size());
	memcpy(&buffer[IntOff::hdIntTypeOff], tType.c_str(), tType.size());
	strcpy(&buffer[IntOff::hdIntSizeOff], len.c_str());
	strcat(buffer, "\n");

	return buffer;
}

template <typename T>
std::string HelperIntType<T>::getIntTypeAsString(T t)
{
	string ret;
    (void) t;

	if (std::is_same_v<T, unsigned char>)
		ret = "unsigned char";
	else if (std::is_same_v<T, char>)
		ret = "char";
	else if (std::is_same_v<T, unsigned short>)
		ret = "unsigned short";
	else if (std::is_same_v<T, short>)
		ret = "short";
	else if (std::is_same_v<T, unsigned int>)
		ret = "unsigned int";
	else if (std::is_same_v<T, int>)
		ret = "int";
	else if (std::is_same_v<T, unsigned long>)
		ret = "unsigned long";
	else if (std::is_same_v<T, long>)
		ret = "long";
	else if (std::is_same_v<T, unsigned long long>)
		ret = "unsigned long long";
	else if (std::is_same_v<T, long long>)
		ret = "long long";

	return ret;
}


template <typename T>
bool HelperIntType<T>::readInt(T& t)
{
	std::ostringstream os;
	//os << "Current value: << 

	bool ret = false;

	

	return ret;	
}

/* AAAAAAA
template <typename T>
std::string HelperIntType<T>::convertToBase(const T& t, Base_e b)
{
	if (
}
*/
 