/******************************************************************************
*
* DataTypeIf.h : data types definitions
* 
*
******************************************************************************/
#pragma once

#ifndef __DATATYPEIF_H__
#define __DATATYPEIF_H__

#include <string>
using namespace std;

// IntType_t: integer types to be tested
// 
typedef struct IntDataType {
	char  cVar;
	unsigned char ucVar;
	short shVar;
	unsigned short ushVar;
	int	iVar;
	unsigned int uiVar;
	long lVar;
	unsigned long ulVar;
	long long llVar;
	unsigned long long ullVar;
} IntDataType_t;


// DataTypeIf: abstract interface to data types
//
template <typename T>
class DataTypeIf {
public:
	// setData: update data from the console.
	// @output: t, source data
	// @return: true: done
	//				false: failed, invalid data,...
	//
	virtual bool setData() = 0;

	// toString: dump object as string. Format:
	// ... 6...12  14...24 25...34 35... 76  
	//     name    dec val hex val  bin val
	// @return: string
	//
	virtual std::string toString() const = 0;
};

#endif
