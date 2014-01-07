/*
 * Timer.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: leon
 */

#include "Timer.h"
#include "KeyboardController.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "TimerView.h"
using namespace std;

Timer::Timer() :
		sec_(0), ticking_(false) {
	thread t(&Timer::run, this); //create a background thread
	t.detach();
}

//start the timer
void Timer::start() {
	ticking_ = true;
}

//stop the timer
void Timer::stop() {
	ticking_ = false;
}

//reset the timer
void Timer::reset() {
	sec_ = 0;
}

// return second
unsigned long Timer::get() const {
	return sec_;
}

// background thread running this.
void Timer::run() {
	while (true) {
		if (ticking_ == true) { //check every second
			set(sec_ + 1);
		}
		this_thread::sleep_for(std::chrono::seconds(1));
	}
}

//return true if the timer is ticking
bool Timer::isTicking() const {
	return ticking_;
}

// set ticking and notify all observers.
void Timer::setTicking(bool ticking) {
	ticking_ = ticking;
	notify();
}

// set second and notify all observers
void Timer::set(unsigned long sec) {
	sec_ = sec;
	notify();
}

//update the time based on keyboard command
void Timer::update(Subject *s) {
	std::string cmd = ((KeyboardController*) s)->getCommand();
	//cout << "GET command " + cmd << std::endl;
	if (cmd == "start") {
		if (ticking_) {
			std::cerr << "Timer has already started." << std::endl;
			return;
		}
		setTicking(true);
	} else if (cmd == "stop") {
		setTicking(false);
	} else {
		if (ticking_) {
			cerr << "Please stop the Timer first before reset." << std::endl;
		} else {
			set(0);
		}
	}
}

