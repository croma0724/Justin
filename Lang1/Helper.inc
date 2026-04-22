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

// Read int from console, validate limits
template <typename T>
T readInt(const std::string& msg)
{
	long tmp;
	bool ret = false;
	string line;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (true)
	{
		std::cout << msg;
		getline(std::cin, line); 
		if (line.size() == 0)
			continue; 

		ret = std::is_same_v<T, short> == true || 
			  std::is_same_v<T, int> == true ||
			  std::is_same_v<T, long> == true;
		if (ret == true)
		{
			tmp = std::stol(line);
		}
		else 
		{
			ret = std::is_same_v<T, unsigned short> == true || 
				  std::is_same_v<T, unsigned int> == true || 
				  std::is_same_v<T, unsigned long> == true;
			if (ret == true)
			{
				tmp = std::stoul(line);
			}
			else 
			{
				cout << "Error, unsuported data type, expected int.\n\n";
			}
		}
		
		if (tmp >= std::numeric_limits<T>::min() &&
			tmp <= std::numeric_limits<T>::max())
		{
			break;
		}
		else 
		{
			std::cout << "Invalid input: [" << tmp << "]\n\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
	}
	
	return (T) tmp;
}
