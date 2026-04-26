/******************************************************************************
*
* BaseDataType.h : data types definitions
* 
*
******************************************************************************/
#ifndef __BASEDATATYPE_H__
#define __BASEDATATYPE_H__

#include <string>
#include <vector>
using namespace std;
 
class BaseDataType {
public:
	typedef enum DataTypeMenu {
		QUIT = 0,
		INT_DTMENU,					// 1
		FLOAT_DTMENU,				// 2
		CHAR_DTMENU,				// 3
		ARRAY_DTMENU,				// 4
		STRING_DTMENU,				// 5
		INVALID
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
	DTMenu_t displayBDTMenu() const;

	static const vector<std::string> DataTypeMenuStr;

};

#endif
