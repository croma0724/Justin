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
		QUIT = 9
	} IntDataOpType_t;

public:
	IntDataType(const IntType_t& t);

	// commandMenu: read console for cmd to execute.
	// @return:  command ID
	//
	int commandMenu() const;

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
	// Operation type
	IntDataOpType_t opType;

	// Integer data type 
	IntType_t  intType;


	string displayToStringHeader() const;
};

template <typename T>
class DisplayIntType {
public:
	static const int LineSz = 80;
	static const int NameOff = 4;
	static const int DecOff = NameOff + 12;
	static const int HexOff = DecOff + 12;
	static const int BinOff = HexOff +12;

public:
	DisplayIntType(T t);

	void displayHeader() const;
	void displayInt(const std::string& name) const;

protected:
	T	val;
};

#endif
