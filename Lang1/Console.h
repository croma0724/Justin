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
	Console();

	// processConsoleCmd:  display main menu and execute selected command.
	// @return:  QUIT command 
	// 
	void processMainMenu();

protected:

private:
	// displayDataTypeMenu: display object main menu.
	// @return: user input, no validation
	//
	std::string displayMainMenu() const;
};

#endif