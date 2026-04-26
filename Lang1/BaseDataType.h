/******************************************************************************
*
* BaseDataType.h : data types definitions
* 
*
******************************************************************************/
#ifndef __BASEDATATYPE_H__
#define __BASEDATATYPE_H__

#include <string>
using namespace std;
 
class BaseDataType {
public:
	typedef enum DataTypeMenu {
		NO_OPERATION   = 0,
		INT_DTMENU,					// 1
		FLOAT_DTMENU,				// 2
		CHAR_DTMENU,				// 3
		ARRAY_DTMENU,				// 4
		STRING_DTMENU,				// 5
		QUIT					 = 9, // 9
	} DTMenu_t;
	 
public:
	BaseDataType() {};
	 
	// processConsoleCmd:  display basic data type menu and execute selected 
	//		command.
	// @return: void, by QUIT command 
	// 
	void processBasicDataTypeMenu();

protected:
 
private:
	// displayBDTMenu: display object main menu with list of supported 
	//		commands
	// 
	std::string displayBDTMenu() const;
};

#endif
