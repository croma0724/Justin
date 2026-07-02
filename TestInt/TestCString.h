// ============================================================================
// TestCString.h:  definitions for C strings
//
// ============================================================================

#ifndef _TEST_CSTRING_H_
#define _TEST_CSTRING_H_

#include <string>
#include <iostream>
using namespace std;

#define STR_CAPACITY 20

typedef struct CStr_t{
	char *pstr;
	char *pstr1;  
	char* pstr2;
} CStr_t;

// @brief:  initialize 1 string and 2 pointers to strings. 
//    str1:  string 
//    pstr1: pointer to constant string in memory
//    pstr2: pointer to str1.
//
void testCStringInit();


void testCStringOper();



#endif 
