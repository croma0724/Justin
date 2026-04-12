/****************************************************
 * 
 * Display current time interface like in C language 
 *
 ***************************************************/
#pragma once
#ifndef LESSON11_H_
#define	LESSON11_H_

#include <string>
#include <ctime>
using namespace std;

// Max buffer size.
#define BUFSZ 128

const string Msg("Hello World, time ");

// getTimeNow:  get current time as a string
// @return:   current time
//
string getTimeNow();

// getTimeOffset:  get current time offset
// @input:		offset 
// @return:   current time
//
string getTimeOffset(int offset);

// displayCurrentTime:  display current time
// @return: message including current time
//
void displayCurrentTime();

// displaySetTime:  display setup time
// @input:  time to display
// @return: message including set time
//
void displayTime(const string& setime);

#endif