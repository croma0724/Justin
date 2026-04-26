/******************************************************************************
*
* IntDataType.h : data types definitions
* 
*
******************************************************************************/
#pragma once

#ifndef __INT_DATATYPE_H__
#define __INT_DATATYPE_H__

#include "DataTypeIf.h"
using namespace std;

class IntDataType : public DataTypeIf <IntDataSt_t> {
public:
	typedef enum IntDataTypeOper {
		NO_OPERATION = 0,
		SETUP_DATA,           // 1
		DISPLAY_DATA,         // 2 			
		ARITMETICAL_OPER,     // 3 
		LOGICAL_OPER,         // 4
		TEST_ARIT_OPER,       // 5
		TEST_LOGIC_OPER,      // 6 
		QUIT = 9              // 9
	} IntDTOper_t;

public:
	IntDataType(const IntDataSt_t& t);

	// commandMenu: read console for cmd to execute.
	// @return:  command ID
	//
	void commandCmd();

	// setData: update data from the console.
	// @input:  inp, new intType values
	//
	void set();
	void setData(const IntDataSt_t& t);
	
	// toString: display intType in dec/hex and binary format.
	// @return: data in user friendly format 
	//
	std::string toString() const;

	// operation: operation to execute. Could be aritmetical or logical
	// @input:  false, arithmetical operations
	//				  true, logical operations
	//
	bool operation(int op = 0);
	
protected:
	// readIntDTCmd: read command from console, loop until valid cmd
	//		QUIT is a valid one.
	// 	
	void 	readIntDTCmd();

	bool aritmeticOperation() {
		return false;
	}

	bool logicalOperation() {
		return false;
	}

private:
	// Integer data type 
	IntDataSt_t intType;

	// Operation type
	IntDTOper_t intOper;

	// Console command ID. 
	int menuId;

	// displayIntDataTypeMenu: display object main menu with list of supported 
	//		commands
	// 
	void displayIntDTMenu() const;

	// readDataTypeCommand: retrieve user command and update <oper>.
	//    Loop until the command is valid or QUIT.
	//
	void readIntDataTypeCommand();

	void displayIntDataLimits() const;
	void readIntStructData(IntDataSt_t& out);

	// Display IntegerMenu header:
	// "Integer Data Types " 
	// "Name    Type     Size     Value     Min			Max"
	//    every name....................
	// "Select Update [1]  Quit [9].  Enter:  "   
	// @return: 
	// 	   
	std::string displayIntTypeHeader() const;
};


// DisplayIntValue: class used to display the header and values for IntDataType
// Template used for different int types.
//    Header format: var name and values in decimal, hex and bianry:
//			Name			Decimal   Hex    Binary
//			  
template <typename T>
class DisplayIntValue {
public:
	// Offsets on displayed line
	static const int LineSz = 80;
	static const int NameOff = 4;
	static const int DecOff = NameOff + 12;
	static const int HexOff = DecOff + 12;
	static const int BinOff = HexOff +12;

public:
	DisplayIntValue(T t);

	// displayHeader:  display header (see foramt above)
	//
	void displayHeader() const;
	
	// displayIntValue: populate header format with <val> value in decimal, hex
	//		and bianry
	// 
	void displayIntValue(const std::string& name) const;

protected:
	T	val;
};

#endif
