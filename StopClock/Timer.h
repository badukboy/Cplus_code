/*
 * Timer.h
 *
 *  Created on: Nov 15, 2013
 *      Author: leon
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Observer.h"
#include "Subject.h"
#include <atomic>

class Timer: public Observer, public Subject {
public:
	Timer();
	void start(); //start the timer
	void stop();  // stop the timer
	void reset();  //reset the timer
	unsigned long get() const;// return seconds elapsed
	void set(unsigned long); // set seconds and notify observers
	bool isTicking() const; // return if timer is ticking
	void setTicking(bool ticking); //start or stop timer and notify observers
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;
	virtual ~Timer() {
	}
	virtual void update(Subject *); //from Observer class
private:
	std::atomic<long> sec_; // number of seconds elapsed
	std::atomic<bool> ticking_; // is timer ticking or not?
	void run(); // function executed by thread
};

#endif /* TIMER_H_ */
