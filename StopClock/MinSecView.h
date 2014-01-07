/*
 * MinSecView.h
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#ifndef MINSECVIEW_H_
#define MINSECVIEW_H_

#include "TimerView.h"
#include <iostream>

class MinSecView: public TimerView {
public:
	//take a extra ostream in order update to call display
	explicit MinSecView(Timer *timer, std::ostream& os = std::cout);
	virtual ~MinSecView();
	virtual void display(std::ostream& os) const;
};

#endif /* MINSECVIEW_H_ */
