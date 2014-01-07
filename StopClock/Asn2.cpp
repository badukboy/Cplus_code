//============================================================================
// Name        : Asn2.cpp
// Author      : Leon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "SecView.h"
#include "MinSecView.h"
#include "TickView.h"
#include "KeyboardController.h"
using namespace std;

int main() {
	Timer *timer = new Timer(); //create a timer
	//create and subscribe views
	TickView tv(timer);
	SecView sv(timer);
	MinSecView msv(timer);

	KeyboardController kc; // create keyboard controller
	kc.subscribe(timer); // subscribe timer
	kc.start(); //start the controller

	delete timer;
	return 0;
}
