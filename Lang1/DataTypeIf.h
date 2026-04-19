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
typedef struct IntType {
	short sVar;
	unsigned short usVar;
	int	iVar;
	unsigned int uiVar;
	long lVar;
	unsigned ulVar;
} IntType_t;


// DataTypeIf: abstract interface to data types
//
template <typename T>
class DataTypeIf {
public:
	// commandMenu: display menu of oerations and return selected one
	//			Selection from console.
	// @return: cmd
	//
	virtual void commandMenu() = 0;

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

#endif
