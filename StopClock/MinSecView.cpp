/*
 * MinSecView.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#include "MinSecView.h"

MinSecView::MinSecView(Timer *timer, std::ostream& os) :
		TimerView(timer, os) {
}

MinSecView::~MinSecView() {
}

//formated display
void MinSecView::display(std::ostream& os) const {
	int min = timer_->get() / 60;
	int sec = timer_->get() % 60;
	os << "MinSecView: " << min << ":" << sec << std::endl;
}

