/*
 * KeyboardController.h
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#ifndef KEYBOARDCONTROLLER_H_
#define KEYBOARDCONTROLLER_H_

#include "Subject.h"
#include <string>

class KeyboardController: public Subject {
public:
	KeyboardController();
	virtual ~KeyboardController();
	void start(); // start the loop to get user commands
	std::string getCommand() const; // return the command
	void setCommand(std::string& cmd); //setCommand and notify all observers.
private:
	std::string cmd_;
};

#endif /* KEYBOARDCONTROLLER_H_ */
