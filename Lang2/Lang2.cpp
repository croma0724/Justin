

#include <iostream>
#include "Console.h"
using namespace std;

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;


	long long ll = 23;
	char c = (char) ll;
	short s = (short)ll;
	int i = (int)ll;
	long l = (long)ll;
	std::cout << "CHAR: [" << c << "]. SHORT: [" << s << "]. INT: [" << i <<
				"]. LONG: [" << l << "]\n";

	unsigned long long ull = -23;
	unsigned char uc = (unsigned char)(ull);
	unsigned short us = (unsigned short) (ull);
	unsigned int ui = static_cast<unsigned int>(ull);
	unsigned long ul = static_cast<unsigned long>(ull);
	std::cout << "UCHAR: [" << (unsigned char) uc << "]. USHORT: [" << (unsigned short) us << 
				"]. UINT: [" << (unsigned int) ui <<  "]. ULONG: [" << ul << "]\n";

	Console cons;
	cons.processMainMenu();

	return 0;
}