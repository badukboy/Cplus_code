/*
 * SecView.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#include "SecView.h"

SecView::SecView(Timer *timer, std::ostream& os) :
		TimerView(timer, os) {
}

SecView::~SecView() {
}

//formated output
void SecView::display(std::ostream& os) const {
	os << "SecView: " << timer_->get() << "\t";
}

