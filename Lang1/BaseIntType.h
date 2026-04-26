/******************************************************************************
*
* BaseIntType.h : int data types definitions
* 
******************************************************************************/
#ifndef __BASEINTTYPE_H__
#define __BASEINTTYPE_H__

#include <vector>
#include <string>
#include "DataTypeIf.h"
using namespace std;

class BaseIntType : public DataTypeIf <IntDataType_t> {
public:
	typedef enum IntType_e {
		QUIT   = 0,
		CHAR,				// character
		UCHAR,			// unsigned char
		SHORT,			// short
		USHORT,			// unsigned short
		INT,				// int
		UINT,				// unsigned int
		LONG,				// long
		ULONG,			// unsigned long
		LLONG,			// long long
		ULLONG,			// unsigned long long			
		INVALID
	} IntType_e;

public:
	BaseIntType(IntDataType_t& t);

	// processIntMenu: read console for cmd to execute.
	//
	void processBaseIntMenu();

	// setData: update data from the console.
	// @input:  inp, new intType values
	//
	bool setData() {
		return false;
	}
	
	// toString: display intType in dec/hex and binary format.
	// @return: data in user friendly format 
	//
	std::string toString() const;
	
protected:
	static const vector<std::string> BaseIntMenu;

private:
	// Integer data type 
	IntDataType_t& baseInt;

	// displayBaseIntMenu: retrieve user command for Base Int Menu, as defined 
	//		by BaseIntMenu. 
	//    Always retrieve a valid command.	
	//	 - Commands:  defined by IntType_e.
	// @return:  command Id
	//
	IntType_e displayBaseIntMenu() const;

     
};
 
#endif
