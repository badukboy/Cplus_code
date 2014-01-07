/*
 * KeyboardController.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#include "KeyboardController.h"
#include <string>
#include <iostream>

KeyboardController::KeyboardController() {
}

KeyboardController::~KeyboardController() {
}

//start the controller , and listening to user input
void KeyboardController::start() {
	std::string cmd;
	std::cout << "Please enter command(start, stop, reset, eof to quit):"
			<< std::endl;
	while (std::cin >> cmd) {
		if (cmd == "start" || cmd == "stop" || cmd == "reset") {
			setCommand(cmd);
			std::cout
					<< "Please enter command(start, stop, reset, eof to quit):"
					<< std::endl;
			continue;
		}
		std::cerr << "invalid command" << std::endl;
		std::cout << "Please enter command(start, stop, reset, eof to quit):"
				<< std::endl;
	}
}

//set command and notify all observers
void KeyboardController::setCommand(std::string& cmd) {
	cmd_ = cmd;
	notify();
}

//return command
std::string KeyboardController::getCommand() const {
	return cmd_;
}
