/*
 * TimerView.h
 *
 *  Created on: Nov 18, 2013
 *      Author: leon
 */

#ifndef TIMERVIEW_H_
#define TIMERVIEW_H_

#include "Observer.h"
#include "Timer.h"
#include <string>
#include <iostream>

class TimerView: public Observer {
public:
	explicit TimerView(Timer *timer, std::ostream& os = std::cout) :
			timer_(timer), out_(&os) {
		timer_->subscribe(this);
	}

	virtual ~TimerView() {
	}

	virtual void update(Subject *s) { // from Observer class
		display(*out_);
	}

	virtual void display(std::ostream& os) const = 0;
protected:
	Timer *timer_;
	std::ostream *out_;
};

#endif /* TIMERVIEW_H_ */
