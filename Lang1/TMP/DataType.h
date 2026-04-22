/******************************************************************************
*
* DataType.h : data types definitions
* 
*
******************************************************************************/
#pragma once

#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__


class NumberType {
public:
	typedef enum Option {
		DISPLAYINT = 1,
		OPERINT,
		LOGIC_OPERINT, Pointers,
		DISPLAYFLOAT,
		OPERFLOAT,
		OPERCHAR,
		QUIT = 9
	} Option_t;

public:
	typedef enum IntFormat_t {
		BINARY = 1,
		HEX,
		DECIMAL
	} IntFormat_t;

	typedef struct IntTypes {
		int	iVar;
		unsigned int uiVar;
		short sVar;
		unsigned short usVar;
		long lVar;
		unsigned ulVar;
	} IntTypes_t;

	typedef struct FloatTypes {
		float fVar;
		double dfVar;
	} FloatTypes_t;


public:
	NumberType();
	
	void setInts(const IntTypes_t& ints);
		
	void testInt(const IntTypes_t& ints)
	{
		setInts(ints);
		displayIntFormat();
	}

	void testFloat() {};
	void testChar() {};



protected:
	// selectProcessing: display menu amd select data type processing
	// 
	Option_t selectProcessing();

	// displayFormat: display min/max for int variables and various format
	void displayIntFormat() const;
	void operationInt();
	void logicalOperationInt();
	void displayFloatFormat() const;
	void operationFloat();
	void operationChar();

private:
	IntTypes_t intTypes;
	FloatTypes_t floatTypes;
};


#endif
