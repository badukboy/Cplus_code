/*
 * TickView.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#include "TickView.h"
#include <iostream>

TickView::TickView(Timer *timer, std::ostream& os) :
		TimerView(timer, os) {
}

TickView::~TickView() {
}

//formated display
void TickView::display(std::ostream &os) const {
	if (timer_->isTicking())
		os << "*" << "\t";
}
