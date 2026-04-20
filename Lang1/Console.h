#pragma once
/******************************************************************************
*
* Console.h : data types definitions
*
******************************************************************************/
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

// Console:  terminal user interface, read used input and display results
// 
class Console {
public:
	typedef enum ConsMenu {
		NO_OPERATION = 0,
		DATA_MENU,				// 1
		STRING_MENU,			// 2
		MEMORY_MENU,			// 3
		CLASS_MENU,				// 4
		QUIT  = 9,				// 9
	} ConsMenu_t;

public:
	// Display menu 
	Console();

	// processConsoleCmd:  select command to execute, execute it and loop for. 
	//    another command. Exit when command is QUIT
	// @return: command ID
	//
	ConsMenu_t processConsoleCmd();

protected:
	// readCmd: read command from console, loop until valid cmd
	//		QUIT is a valid one.
	//  
	void 	readCmd();

private:
	// Menu to execute
	ConsMenu_t consOper;
	
	// Console command ID. Normally 0.
	int menuId;
	
	// displayDataTypeMenu: display object main menu with list of supported 
	//		commands
	// 
	void displayConsoleMenu() const;
};

#endif