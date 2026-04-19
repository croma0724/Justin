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


class IntDataType : public DataTypeIf <IntType_t> {
public:
	typedef enum IntDataOpType {
		SETUP_DATA		= 1,
		DISPLAY_DATA,
		ARITMETICAL_OPER,
		LOGICAL_OPER,
		TEST_ARIT_OPER,
		TEST_LOGIC_OPER,
		QUIT_INT = 9
	} IntDataOpType_t;

public:
	IntDataType(const IntType_t& t);

	// commandMenu: read console for cmd to execute.
	// @return:  command ID
	//
	void commandMenu();

	// setData:  set <intType> data structure
	// @input:  inp, new intType values
	//
	void setData(const IntType_t& t);
	
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
	bool aritmeticOperation() {
		return false;
	}

	bool logicalOperation() {
		return false;
	}

private:
	// Integer data type 
	IntType_t  intType;

	// Operation type
	IntDataOpType_t intOper;

	// displayIntDataTypeMenu: display object main menu with list of supported 
	//		commands
	// 
	void displayIntDataTypeMenu() const;

	// readDataTypeCommand: retrieve user command and update <oper>.
	//    Loop until the command is valid or QUIT.
	//
	void readIntDataTypeCommand();
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
