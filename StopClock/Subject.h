/*
 * Subject.h
 *
 *  Created on: Nov 15, 2013
 *      Author: leon
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_
#include "Observer.h"
#include <list>

class Observer;
class Subject {
public:
	virtual void subscribe(Observer *obs); // subscribe an observer

	virtual void unsubscribe(Observer *obs); // unsubscribe an observer

	virtual void notify(); // ask each subscribed observer to update itself

	virtual ~Subject();
protected:
	Subject();
private:
	std::list<Observer*> observers_; // list of observers
};

#endif /* SUBJECT_H_ */
