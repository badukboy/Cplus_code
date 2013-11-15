/*
 * OptionStudent.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: leon
 */

#include "OptionStudent.h"
#include <iostream>

size_t OptionStudent::count_ = 0;
OptionStudent::OptionStudent(const std::string& id ,
		const std::string& first , const std::string& last , int term, const std::string& option) :
		Student(id, first, last), term_(term), option_(option) {
	count_++;
}

OptionStudent::OptionStudent(const OptionStudent& src) :
		Student(src), term_(src.term_), option_(src.option_) {
	count_++;
}

void OptionStudent::print(std::ostream& os) const {
	Student::print(os);
	os << term_ << std::endl;
	os << option_ << std::endl;
}

void OptionStudent::display(std::ostream& os) const {
	Student::display(os);
	os << "Term: " << term_ << std::endl;
	os << "Option: " << option_ << std::endl;
}

std::istream& operator>>(std::istream& is, OptionStudent& s) {
	return is >> (Student&) s >> s.term_ >> s.option_;
}

