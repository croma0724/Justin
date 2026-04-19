#pragma once
#ifndef __CONSOLE_H__
#define __CONSOLE_H__

class Console {
public:
	typedef enum Option {
		DataOper = 1,
		StringOper,
		Pointers,
		Memory,
		Quit = 20
	} Option;

public:
	// Display menu 
	Console();

	// process:  display meny and select option 
	//
	void processInput();

protected:
	// processDataOpeation:  data 
	//
	void processDataOpeation();


private:
	Option getCommand() const;
};


#endif