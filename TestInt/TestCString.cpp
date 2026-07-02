

#include <cstring> 
#include "TestCString.h"

const char msg1[] = "Hello World!";
const char msg2[] = "Hello Canada!";
const char msg3[] = "Today is a big day!";
 
static void *getStringAddress(const char*);
static void displayCStr(const CStr_t s);

void testCStringInit()
{
	std::cout << "Testing C strings ===\n";

	char str1[20] = "Hello World!";				// string stores data
	char* pstr1 = const_cast<char*> (msg1);	// String pointer to msg2 data from memory.
	char* pstr2 = str1;								// String pointer to str1
	CStr_t cstr = { str1, pstr1, pstr2 };
	
	// Display strings after initialization
	displayCStr(cstr);

	// Update <str1> with <msg2>. Validation:  str1 capacity <= msg2 
	std::cout << "\nUpdate string variable str1 with msg2 content:\n";
	// Validation
	if (strlen(msg2) < STR_CAPACITY)
	{
		strcpy(str1, msg2);
		displayCStr(cstr);
	}
	else
	{
		std::cerr << "\tError: input string [" << msg2 << "] too big!";
	}

	// Partial copy 
	std::cout << "\nUpdate str1 variable with the first 6 characters:\n";
	strncpy(str1, msg3, 6);
	std::cout << "\tstr1   [" << str1 << "].  Length: [" << strlen(str1) << "]\n";
	std::cout << "\tpstr1  [" << pstr1 << "].  Length: [" << strlen(pstr1) << "]\n";
	std::cout << "\tpstr2  [" << pstr2 << "].  Length: [" << strlen(pstr2) << "]\n";

	// Cut string str1 length to 2 bytes.
	std::cout << "\nCut str1 variable to 2 characters:\n";
	str1[2] = 0x0;
	std::cout << "\tstr1   [" << str1 << "].  Length: [" << strlen(str1) << "]\n";
	std::cout << "\tpstr1  [" << pstr1 << "].  Length: [" << strlen(pstr1) << "]\n";
	std::cout << "\tpstr2  [" << pstr2 << "].  Length: [" << strlen(pstr2) << "]\n";
}

void testCStringOper()
{
	std::cout << "\nOperations on strings:\n";
	char str1[32] = { 0x0 };
	strcpy(str1, msg1);
	std::cout << "\tString str1 [" << str1 << "]\n";

	// Missing capacity validations
	//
	strcat(str1, ".  ");  // Append space
	strcat(str1, msg2);   // Append msg2.
	std::cout << "\tString str1 [" << str1 << "]\n\n";
	  
	std::cout << "Find world:\n";
	char* p = strstr(str1, "World");
	if (p != NULL)
	{
		std::cout << "\tFound World in string str1. Display:\n";
		std::cout << "\t" << p << "\n";
	}
	else
	{
		std::cout << "\tNOT Found World in string str1.\n";
	}

	p = strstr(str1, "123");
	if (p != NULL)
	{
		std::cout << "\tFound 123 in string str1. Display:\n";
		std::cout << p << "\n";
	}
	else
	{
		std::cout << "\tNOT Found 123 in string str1.\n";
	}
}


static void* getStringAddress(const char* ps)
{
	return static_cast<void*> (const_cast<char*> (ps));
}

static void displayCStr(const CStr_t s)
{
	// Display string and length
	std::cout << "String str1:\n\tValue: [" << s.pstr << "]. Address: [0x" << getStringAddress(s.pstr)
		<< "].  Length: [" << strlen(s.pstr) << "].  Capacity: [" << (int) STR_CAPACITY << "].\n";
	std::cout << "Pointer to string pstr1:\n\tValue: [" << s.pstr1 << "]. Address: [0x"
		<< getStringAddress(s.pstr1) << "].  Length: [" << strlen(s.pstr1) << "]\n";
	std::cout << "Pointer to string pstr2:\n\tValue: [" << s.pstr2 << "]. Address: [0x"
		<< getStringAddress(s.pstr2) << "].  Length: [" << strlen(s.pstr2) << "]\n";
}
