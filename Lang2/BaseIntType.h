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

typedef struct HeadIntEntryOff {
	int hdIntNameOff = 4;
	int hdIntValueOff = hdIntNameOff + 10;
	int hdIntTypeOff = hdIntValueOff + 24;
	int hdIntSizeOff = hdIntTypeOff + 24;
} HeadIntEntryOff_s;

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
	
	// toString: display IntDataType_t structure as follows:
	//    header including:  member name value type  size
	//		one line per IntDataType_t data member.
	// @return: data in user friendly format 
	//
	std::string toString() const;
	
protected:

private:
	static const vector<std::string> BaseIntMenu;

	// Integer data type 
	IntDataType_t& baseInt;

	// displayBaseIntMenu: retrieve user command for Base Int Menu, as defined 
	//		by BaseIntMenu, always a valid cmd. 
	//     	
	//	 - Commands:  defined by IntType_e.
	// @return:  command Id
	//
	IntType_e displayBaseIntMenu() const;

	std::string displayIntEntryHeader() const;

	// displayToStringHead:  header for toString() function
	//    "    Name      Value           Type      Size"
	std::string displayIntToStringHead() const;
};
 

/// Helper.inc
template <typename T> std::string displayIntValue(const std::string& name, const T& t);

#endif
