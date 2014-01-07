/*
 * SecView.h
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#ifndef SECVIEW_H_
#define SECVIEW_H_

#include "TimerView.h"
#include "Timer.h"
#include <iostream>

class SecView: public TimerView {
public:
	//take a extra ostream object in ordert update to call diplay
	explicit SecView(Timer *timer, std::ostream& os = std::cout);
	virtual void display(std::ostream& os) const;
	virtual ~SecView();
};

#endif /* SECVIEW_H_ */
