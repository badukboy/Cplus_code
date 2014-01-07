/*
 * Observer.h
 *
 *  Created on: Nov 15, 2013
 *      Author: leon
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_
#include "Subject.h"

class Subject;
class Observer { //ABC
public:
	virtual ~Observer() {
	}
	virtual void update(Subject *) = 0;
protected:
	Observer() {
	}
};

#endif /* OBSERVER_H_ */
