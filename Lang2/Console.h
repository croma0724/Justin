/******************************************************************************
*
* Console.h : data types definitions
*
******************************************************************************/
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <string>
#include <vector>
using namespace std;


// Console:  terminal user interface, read used input and display results
// 
class Console {
public:
	typedef enum ConsMenu {
		QUIT = 0,				// 0
		DATA_MENU,				// 1
		STRING_MENU,			// 2
		MEMORY_MENU,			// 3
		CLASS_MENU,				// 4
		INVALID
	} Cons_e;

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
	Cons_e displayMainMenu() const;

	// 
	static const vector<std::string> ConsoleMenuStr;
};

#endif