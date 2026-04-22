#pragma once
/******************************************************************************
*
* DataType.h : data types definitions
* 
*
******************************************************************************/
#ifndef __DATATYPE_H__
#define __DATATYPE_H__

#include <string>
using namespace std;
 
class DataType {
public:
	typedef enum DataTypeMenu {
		NO_OPERATION   = 0,
		INTDT_MENU,					// 1
		FLOATDT_MENU,				// 2
		CHATDT_MENU,				// 3
		ARRAYDT_MENU,				// 4
		STRINGDT_MENU,			// 5
		QUIT					 = 9, // 9
	} DTMenu_t;

public:
	DataType(); 
	
	// processDataTypeCmd:  select command from menu and execute it. 
	//    Loop, exit when command is QUIT
	// @return: command ID	
	//
	void processDataTypeCmd();

protected:
	// readDTCmd: read command from console, loop until valid cmd
	//		QUIT is a valid one.
	//  
	void 	readDTCmd();

private:
	// Menu to execute
	DTMenu_t dataOper;

	// Console command ID. Normally 0.
	int menuId;

	// displayDataTypeMenu: display object main menu with list of supported 
	//		commands
	// 
	void displayDTMenu() const;
	

	// DELETE **********************************
	// readDataTypeCommand: retrieve user command and update <oper>.
	//    Loop until the command is valid or QUIT.
	//
	void readDataTypeCommand();
};


#endif
