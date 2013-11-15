/*
 * Lab8.h
 *
 *  Created on: Nov 7, 2013
 *      Author: leon
 */

#ifndef LAB8_H_
#define LAB8_H_

#include <cctype>
#include <algorithm>
#include <iostream>

class Name {
private:
	std::string first_, last_;

public:
	explicit Name(const std::string& f = "aaa", const std::string& l = "bbb") :
			first_(f), last_(l) {
		if (!isValidLast(last_) || !isValidFirst(first_)) {
			throw "Name::Name(const string&, const string&) : invalid name";
		}
		std::transform(first_.begin(), first_.end(), first_.begin(), tolower);
		std::transform(last_.begin(), last_.end(), last_.begin(), tolower);
	}

	friend std::istream& operator>>(std::istream& is, Name& n);
	friend std::ostream& operator<<(std::ostream& os, const Name& n);

	static bool isValidLast(const std::string& last) {
		return isValidFirst(last);
	}
	static bool isValidFirst(const std::string& first) {
		if (first.empty()) {
			return false;
		}
		for (size_t i = 0; i < first.size(); ++i) {
			if (isspace(first[i])) {
				return false;
			}
		}
		return true;
	}
};

inline std::ostream& operator<<(std::ostream& os, const Name& n) {
	os << n.first_ << " " << n.last_;
	return os;
}

inline std::istream& operator>>(std::istream& is, Name& n) {
	std::string first;
	std::string last;
	if (is >> first >> last && Name::isValidFirst(first)
			&& Name::isValidLast(last)) {
		n.first_ = first;
		n.last_ = last;
	} else {
		is.setstate(std::ios_base::failbit);
	}
	return is;
}

class Student {
public:
//	explicit Student(const std::string& id = "a00000000", const Name& name =
//			Name()) :
//			id_(id), name_(name) {
//		if (!isValidID(id))
//			throw "Student::Student(const std::string& , const Name&)";
//	}

	explicit Student(const std::string& id = "a00000000",
			const std::string& first = "abcd", const std::string& last =
					"whatever") :
			id_(id), name_(Name(first, last)) {
		if (!isValidID(id))
			throw "Student::Student(const std::string& , const Name&)";
	}

	bool operator<(const Student& x) const {
		return id_ < x.id_;
	}

	friend std::istream& operator>>(std::istream& is, Student& s);
	friend std::ostream& operator<<(std::ostream& os, const Student& s);
private:
	std::string id_;
	Name name_;

	static bool isValidID(const std::string& id) {
		if (id.length() != 9 || id[0] != 'a') {
			return false;
		}
		for (std::string::size_type i = 1; i < id.length(); i++) {
			if (!isdigit((int) id[i])) {
				return false;
			}
		}
		return true;
	}
};

inline std::istream& operator>>(std::istream& is, Student& s) {
	std::string id;
	Name name;
	if (is >> id >> name && Student::isValidID(id)) {
		s.id_ = id;
		s.name_ = name;
	} else {
		is.setstate(std::ios_base::failbit);
	}
	return is;
}

inline std::ostream& operator<<(std::ostream& os, const Student& s) {
	os << s.id_ << " " << s.name_;
	return os;
}

#endif /* LAB8_H_ */
