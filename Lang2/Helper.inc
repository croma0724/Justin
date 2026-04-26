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
