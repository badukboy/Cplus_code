/*
 * Subject.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: leon
 */

#include "Subject.h"

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::subscribe(Observer *obs) { // subscribe an observer
	observers_.push_back(obs);
}

void Subject::unsubscribe(Observer *obs) { // unsubscribe an observer
	observers_.remove(obs);
}

//notify all observers
void Subject::notify() {
	for (auto x : observers_) {
		x->update(this);
	}
}
