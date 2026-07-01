

#include <iostream>
#include <sstream>
#include <bitset>
#include <limits>
#include <string>
#include "TestInt.h"
using namespace std;


std::string processChar()
{
	int nr;
	std::string val;
	std::ostringstream os;
	ALimits charLimit = { static_cast<int>(std::numeric_limits<char>::min()),
								 static_cast<int>(std::numeric_limits<char>::max()) };

	// Display data type
	std::cout << "\nRead character, valid values:  [" << charLimit.minVal 
				 << "..." << charLimit.maxVal << "].\n";
	std::cout << "Enter char:    ";
	std::cin >> val;
	nr = std::stoi(val);

	// Validation against character limits
	if ((nr >= charLimit.minVal) && (nr <= charLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)nr, sizeof(char));
		os << "Char value in decimal: [" << (int)nr << "].  Hex: [0x" << tmp
			<< "].   Bin: [" << std::bitset<8>(nr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid character value [" << val << "]\n";
	}

	return os.str();
}

std::string processUChar()
{
	unsigned int unr;
	std::string val;
	std::ostringstream os;
	ALimits charLimit = { static_cast<int>(std::numeric_limits<unsigned char>::min()),
								 static_cast<int>(std::numeric_limits<unsigned char>::max()) };

	std::cout << "\nRead unsigned character, valid values:  ["
				<< charLimit.minVal << "..." << charLimit.maxVal << "].\n";
	std::cout << "Enter unsigned char:    ";
	std::cin >> val;
	unr = std::stoul(val);

	// Validation against character limits
	if ((unr >= charLimit.minVal) && (unr <= charLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)unr, sizeof(unsigned char));
		os << "Unsigned Char value in decimal: [" << (int)unr << "].  Hex: [0x" << tmp
			<< "].   Bin: [" << std::bitset<8>(unr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid unsigned character value [" << val << "]\n";
	}

	return os.str();
}

std::string processShort()
{
	int nr;
	std::string val;
	std::ostringstream os;
	ALimits shLimit = { static_cast<int>(std::numeric_limits<short>::min()),
							  static_cast<int>(std::numeric_limits<short>::max()) };

	std::cout << "\nRead short int type, valid values:  ["
		<< shLimit.minVal << "..." << shLimit.maxVal << "].\n";
	std::cout << "Enter short:    ";
	std::cin >> val;
	nr = std::stoi(val);

	// Validation against character limits
	if ((nr >= shLimit.minVal) && (nr <= shLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)nr, sizeof(short));
		os << "Short value in decimal: [" << (short)nr << "].  Hex: [0x" << tmp
			<< "].   Bin: [" << std::bitset<16>(nr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid short value [" << val << "]\n";
	}

	return os.str();
}

std::string processUShort()
{
	int unr;
	std::string val;
	std::ostringstream os;
	ALimits shLimit = { static_cast<int>(std::numeric_limits<unsigned short>::min()),
							  static_cast<int>(std::numeric_limits<unsigned short>::max()) };

	std::cout << "\nRead unsigned short type, valid values:  ["
		<< shLimit.minVal << "..." << shLimit.maxVal << "].\n";
	std::cout << "Enter unsigned short:    ";
	std::cin >> val;
	unr = std::stoul(val);

	// Validation against character limits
	if ((unr >= shLimit.minVal) && (unr <= shLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)unr, sizeof(unsigned short));

		os << "Unsigned short value in decimal: [" << (unsigned short)unr << "].  Hex: [0x"
			<< tmp << "].   Bin: [" << std::bitset<16>(unr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid unsigned short value [" << val << "]\n";
	}

	return os.str();
}

std::string processInt()
{
	long long nr;
	std::string val;
	std::ostringstream os;
	ALimits intLimit = { static_cast<int>(std::numeric_limits<int>::min()),
								static_cast<int>(std::numeric_limits<int>::max()) };

	std::cout << "\nRead int type, valid values: ["
		<< intLimit.minVal << "..." << intLimit.maxVal << "].\n";

	std::cout << "Enter int:    ";
	std::cin >> val;
	nr = std::stoll(val);

	// Validation against character limits
	if ((nr >= intLimit.minVal) && (nr <= intLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)nr, sizeof(int));
		os << "Int value in decimal: [" << (int)nr << "].  Hex: [0x"
			<< tmp << "].   Bin: [" << std::bitset<32>(nr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid int value [" << val << "]\n";
	}

	return os.str();
}

std::string processUInt()
{
	unsigned long long uni;
	std::string val;
	std::ostringstream os;
	ALimits uiLimit = { static_cast<int>(std::numeric_limits<unsigned int>::min()),
						      static_cast<int>(std::numeric_limits<unsigned int>::max()) };

	std::cout << "\nRead unsigned int type, valid values: ["
		<< uiLimit.minVal << "..." << uiLimit.maxVal << "].\n";

	std::cout << "Enter unsigned int:    ";
	std::cin >> val;
	uni = std::stoull(val);

	// Validation against character limits
	if ((uni >= (unsigned long long) uiLimit.minVal) && 
		 (uni <= (unsigned long long) uiLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)uni, sizeof(unsigned int));
		os << "Int value in decimal: [" << (unsigned int)uni << "].  Hex: [0x"
			<< tmp << "].   Bin: [" << std::bitset<32>(uni) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid unsigned int value [" << val << "]\n";
	}

	return os.str();
}

std::string processLong()
{
	long long nr;
	std::string val;
	std::ostringstream os;
	ALimits lLimit = { static_cast<int>(std::numeric_limits<long>::min()),
								static_cast<int>(std::numeric_limits<long>::max()) };

	std::cout << "\nRead unsigned int type, valid values: ["
		<< lLimit.minVal << "..." << lLimit.maxVal << "].\n";

	std::cout << "Enter long:    ";
	std::cin >> val;
	nr = std::stoll(val);

	// Validation against character limits
	if ((nr >= lLimit.minVal) && (nr <= lLimit.maxVal))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)nr, sizeof(unsigned int));
		os << "Int value in decimal: [" << (long)nr << "].  Hex: [0x"
			<< tmp << "].   Bin: [" << std::bitset<32>(nr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid long value [" << val << "]\n";
	}

	return os.str();
}

std::string processULong()
{
	unsigned long long nr;
	std::string val;
	std::ostringstream os;
	ALimits ulLimit = { static_cast<int>(std::numeric_limits<unsigned long>::min()),
								static_cast<int>(std::numeric_limits<unsigned long>::max()) };

	std::cout << "Read unsigned long type, valid values: ["
		<< ulLimit.minVal << "..." << ulLimit.maxVal << "].\n";

	std::cout << "Enter unsigned long:    ";
	std::cin >> val;
	nr = std::stoull(val);

	// Validation against character limits
	if ((nr >= static_cast<unsigned long long> (ulLimit.minVal)) && 
		 (nr <= static_cast<unsigned long long> (ulLimit.maxVal)))
	{
		// Valid
		std::string tmp = convertAlignToString((long long&)nr, sizeof(unsigned int));
		os << "Unsigned long value in decimal: [" << (long)nr << "].  Hex: [0x"
			<< tmp << "].   Bin: [" << std::bitset<32>(nr) << "]\n";
	}
	else
	{
		// Invalid input
		os << "Error, invalid unsigned long value [" << val << "]\n";
	}

	return os.str();
}


std::string convertAlignToString(long long& val, size_t sz)
{
	stringstream sstr;
	sstr << hex << val;
	std::string str = sstr.str();
	// str size => "XXXXX..."
	size_t strSize = str.size();

	if (strSize > sz)
	{
		// Keep first 2 characters:  0x, remove in the 
		str.erase(0, strSize - sz * 2);
	}
	
	return str;
}
