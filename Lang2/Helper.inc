/******************************************************************************
*
* Helper.inc : helper templated functions
* 
*
******************************************************************************/
#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <type_traits>
using namespace std;


// validateMinMax: validate input is in limits
// @input:	min, min limit
//			max, max limits
//			inp, value to test
// @return: true, inp in limits
//			false, inp not in limits
//
template <typename T>
bool validateMinMax(const T& min, const T& max, T inp)
{
	return (inp >= min && inp <= max);
}

// getTypeAsString: return template type as a string
// @return:  <T> as string
//
template <typename T>
std::string getTypeAsString(T t = 0)
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
 