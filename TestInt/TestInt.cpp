


#include <iostream>
#include <sstream>
#include <bitset>
#include <limits>
#include <string>
#include "TestInt.h"
#include "TestCString.h"
using namespace std;

std::string intToHex(long long n);
 

std::string processLLong();
std::string processULLong();

int main()
{
#ifdef TESTINT
	std::cout << processChar() << "\n";
	std::cout << processUChar() << "\n";
	std::cout << processShort() << "\n";
	std::cout << processUShort() << "\n";

	std::cout << processInt() << "\n";
	std::cout << processUInt() << "\n";

	std::cout << processLong() << "\n";
	std::cout << processULong() << "\n";

	std::cout << processLLong();
	std::cout << processULLong();
#endif 
	 

	std::cout << "\n\nTesting strings\n";
	testCStringInit();
}

std::string processLLong()
{
	long long nr;
	std::string val;
	std::ostringstream os;

	std::cout << "\nprocessLLong(). Long long limits. Min: [" 
		<< static_cast<long long>(std::numeric_limits<long long>::min())
		<< "].  Max: [" << static_cast<long long>(std::numeric_limits<long long>::max())
		<< "].\n";
	std::cout << "Enter int:    ";
	std::cin >> val;
	nr = std::stoll(val);
	os << "Long long. Decimal: [" << nr << "]. Hex: [0x" << intToHex(nr) << "], Bin: ["
		<< std::bitset<64>(nr) << "]\n";

	// long the same size as int.
	long long l = (long long)(nr & 0xFFFFFFFFFFFFFFFF);
	os << "Long long. Decimal: [" << l << "]. Hex: [0x" << intToHex(l)
		<< "]. Bin: [" << std::bitset<64>(l) << "]\n";

	return os.str();
}

std::string processULLong()
{
	long long nr;
	std::string val;
	std::ostringstream os;

	std::cout << "\nprocessULLong unsigned long long limits. Min: [" 
		<< static_cast<unsigned long long>(std::numeric_limits<unsigned long long>::min())
		<< "].  Max: [" 
		<< static_cast<unsigned long long>(std::numeric_limits<unsigned long long>::max())
		<< "].\n";
	std::cout << "Enter int:    ";
	std::cin >> val;
	nr = std::stoull(val);
	os << "unsigned long Long. Decimal: [" << nr << "]. Hex: [0x" << intToHex(nr)
		<< "], Bin: [" << std::bitset<64>(nr) << "]\n";

	// long the same size as int.
	unsigned long long ull = (unsigned long long)(nr & 0xFFFFFFFFFFFFFFFF);
	os << "unsigned long long. Decimal: [" << (unsigned long long)ull 
		<< "]. Hex: [0x" << intToHex(ull) << "]. Bin: [" << std::bitset<64>(ull)
		<< "]\n";

	return os.str();
}



std::string intToHex(long long n) {
	if (n == 0) return "0";

	// Treat as unsigned to handle two's complement for negative numbers
	unsigned long un = static_cast<unsigned long>(n);
	std::string hex = "";
	char digits[] = "0123456789ABCDEF";

	while (un > 0) {
		hex = digits[un % 16] + hex;
		un /= 16;
	}
	return hex;
}
