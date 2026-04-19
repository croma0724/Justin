/******************************************************************************
*
* DataType.h : data types definitions
* 
*
******************************************************************************/
#pragma once

#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__

#include <string>
using namespace std;

/*
typedef enum DataGenOper {
	SET = 1,
	DISPLAY,
	OPERATION,
	LOGIC_OPERATION,
	QUIT = 9
}DataGenOper_t;
*/
 
typedef struct IntType {
	short sVar;
	unsigned short usVar;
	int	iVar;
	unsigned int uiVar;
	long lVar;
	unsigned ulVar;
} IntType_t;


template <typename T>
bool MinMax(T t1, T t2, T inp)
{
	return (inp >= t1 && inp <= t2);
}

class DataType {
public:

protected:

private:

};


template <typename T>
class DataTypeIf {
public:
	// commandMenu: display menu of oerations and return selected one
	//			Selection from console.
	// @return: cmd
	//
	virtual int commandMenu() const = 0;

	// setData: set data
	// @input:  t, source data
	// @return: 
	//
	virtual void setData(const T& t) = 0;

	// toString: dump object as string. Format:
	// ... 6...12  14...24 25...34 35... 76  
	//     name    dec val hex val  bin val
	// @return: string
	//
	virtual std::string toString() const = 0;

	// operation: execute operations 
	// @return:  true, completed ok
	//					 false, failed
	//
	virtual bool operation(int op =0) = 0;
};


class IntDataType : public DataTypeIf <IntType_t> {
public:
	typedef enum IntDataOpType {
		SETUP_STRUCT		= 1,
		DISPLAY_STRUCT,
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
	IntType_t  intType;

private:
	bool aritmeticOperation() {
		return false;
	}

	bool logicalOperation() {
		return false;
	}

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
//void displayFormatInt<T>(std::string& out, T val);

#endif
