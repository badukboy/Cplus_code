/*
 * OptionStudent.h
 *
 *  Created on: Nov 14, 2013
 *      Author: leon
 */

#ifndef OPTIONSTUDENT_H_
#define OPTIONSTUDENT_H_

#include "Lab8.h"

class OptionStudent: public Student {
public:
	explicit OptionStudent(const std::string& id = "a00000000",
			const std::string& first = "something", const std::string& last =
					"whatever", int term = 0, const std::string& option = "nothing");
	OptionStudent(const OptionStudent& src);
	static size_t count() {
		return count_;
	}
	virtual void print(std::ostream& os) const;
	virtual void display(std::ostream& os) const;
	friend std::istream& operator>>(std::istream& is, OptionStudent& s);
	virtual ~OptionStudent() {
		count_--;
	}
	;
private:
	int term_;
	std::string option_;
	static size_t count_;
};

#endif /* OPTIONSTUDENT_H_ */
