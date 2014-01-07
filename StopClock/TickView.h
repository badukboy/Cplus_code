/*
 * TickView.h
 *
 *  Created on: Nov 19, 2013
 *      Author: leon
 */

#ifndef TICKVIEW_H_
#define TICKVIEW_H_

#include "TimerView.h"
#include <iostream>

class TickView: public TimerView {
public:
	//take a extra ostream in order update method to call display
	explicit TickView(Timer *timer, std::ostream& os = std::cout);
	virtual ~TickView();
	virtual void display(std::ostream& os) const;
};

#endif /* TICKVIEW_H_ */
