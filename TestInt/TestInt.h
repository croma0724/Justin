#pragma once

#ifndef _TESTINT_H_
#define _TESTINT_H_

#include <string>
using namespace std;

// Min/max values for specified type
typedef struct ALimits {
	long long minVal;;
	long long maxVal;
} ALimits;


std::string processChar();
std::string processUChar();
std::string processShort();
std::string processUShort();
std::string processInt();
std::string processUInt();
std::string processLong();
std::string processULong();


std::string convertAlignToString(long long& val, size_t sz);
std::string convertAlignToString(unsigned long long& val, size_t sz);


#endif
