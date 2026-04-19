/******************************************************************************
*
* DataType.h : data types definitions
* 
*
******************************************************************************/
#pragma once

#ifndef __DATATYPE_H__
#define __DATATYPE_H__

#include <string>
using namespace std;
 
class DataType {
public:
	typedef enum DataTypeOp {
		INTDATA_TYPE   =1,	// 1, i
		FLOATDATA_TYPE,			// 2, f
		CHATDATA_TYPE,			// 3, c
		ARRAY_TYPE,					// 4, a
		STRING_TYPE,				// 5, s
		QUIT_TYPE,					// 9, q
	} DataTypeOp_t;

public:
	DataType() {};

	// commandMenu: display menu of oerations and return selected one
	//			Selection from console.
	// @return: cmd
	//
	void commandMenu();

///protected:

private:
	DataTypeOp_t oper;

	// displayDataTypeMenu: display object main menu with list of supported 
	//		commands
	// 
	void displayDataTypeMenu() const;
	
	// readDataTypeCommand: retrieve user command and update <oper>.
	//    Loop until the command is valid or QUIT.
	//
	void readDataTypeCommand();
};


#endif
