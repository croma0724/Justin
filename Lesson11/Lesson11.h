/****************************************************
 *
 * Display current time implementation like in C++ language
 *
 ***************************************************/
#pragma once
#ifndef LESSON1_H_
#define	LESSON1_H_

#include <string>
#include <ctime>
using namespace std;


class JTime {
public:
	JTime(int offset = 0);

	void displayCurrentTime();
	void displayTime(const string = "");

protected:
	void getTimeOffset(int offset = 0);

private:
	// Message
	const string msg;   //  ("Hello World, time ");
	// Date/time
	string stmp;

	// Max buffer size
	static constexpr int BUFSZ = 128;
};

#endif