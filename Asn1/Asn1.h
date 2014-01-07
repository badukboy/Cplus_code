/*
 * Asn1.h
 *
 *  Created on: Oct 21, 2013
 *      Author: leon
 */

#ifndef ASN1_H_
#define ASN1_H_

#endif /* ASN1_H_ */

#include <set>
#include <iterator>

class Grade {
public:
	Grade() :
			score_(0) {
	}
	Grade(std::string c, int s) :
			course_(c), score_(s) {
	}
	bool operator<(const Grade& x) const {
		return course_ < x.course_;
	}
	bool operator==(const Grade& x) const {
		return course_ == x.course_ && score_ == x.score_;
	}

	int getScore() const {
		return score_;
	}

	std::string getCourse() const {
		return course_;
	}

	friend std::ostream& operator<<(std::ostream& os, const Grade& g); // sample output: comp3512 90
	friend std::istream& operator>>(std::istream& is, Grade& g);
private:
	std::string course_; // e.g. comp3512
	int score_;  // e.g. 90
};

//Grade operator<< overload
inline std::ostream& operator<<(std::ostream& os, const Grade& g) {
	os << g.course_ << " " << g.score_;
	return os;
}

//Grade operator>> overload
inline std::istream& operator>>(std::istream& is, Grade& g) {
	is >> g.course_ >> g.score_;
	return is;
}

class Name {
public:
	Name() {
	}
	Name(std::string f, std::string l) :
			first_(f), last_(l) {
	}
	std::string getFirst() const {
		return first_;
	}
	std::string getLast() const {
		return last_;
	}
	bool operator==(const Name& x) const {
		return first_ == x.first_ && last_ == x.last_;
	}
	friend std::ostream& operator<<(std::ostream& os, const Name& n); // sample output: homer simpson
	friend std::istream& operator>>(std::istream& is, Name& n); 
private:
	std::string first_; // e.g. homer
	std::string last_; // e.g. simpson
};

//Name operator<< overload
inline std::ostream& operator<<(std::ostream& os, const Name& n) {
	os << n.first_ << " " << n.last_;
	return os;
}

//Name operator>> overload
inline std::istream& operator>>(std::istream& is, Name& n) {
	is >> n.first_ >> n.last_;
	return is;
}

class Student {
public:
	Student() {
	}
	;
	Student(std::string id, Name name) :
			id_(id), name_(name) {
	}
	void display(std::ostream& os) const {
		os << id_ << std::endl;
		os << name_ << std::endl;
		for (auto grade : grades_) {
			os << grade << std::endl;
		}
	}

	std::string getId() const {
		return id_;
	}

	Name getName() const {
		return name_;
	}

	const std::set<Grade>& getGrades() const {
		return grades_;
	}

	void clearGrades() {
		grades_.clear();
	}

	bool operator<(const Student& x) const {
		return id_ < x.id_;
	}

	bool operator==(const Student& x) const {
		return id_ == x.id_;
	}

	friend std::istream& operator>>(std::istream& is, Student& s);
private:
	std::string id_; // e.g. a11111111
	Name name_;
	std::set<Grade> grades_;
};

//student operator>> overload
inline std::istream& operator>>(std::istream& is, Student& s) {
	int m, i;
	Grade g;
	if (!(is >> s.id_)) {
		return is;
	}
	is >> s.name_ >> m;
	s.grades_.clear();
	for (i = 0; i < m; ++i) {
		is >> g;
		s.grades_.insert(g);
	}
	return is;
}

//Represent searching type
enum SearchBy {
	all,		//e.g. show name/showid
	byid,		//e.g. show id a12345678
	byname,		//e.g. show name * *
	byfirstname,	//e.g. show name first *
	bylastname,	//e.g. show name * last
	byfullname,	//e.g. show name first last
	bygrade,	//e.g. show grade com3510 100
	bygraderange	//e.g. show grade com3510 0 100
};

//Represent command argument and option
struct CommandArgument {
	bool idonly;         	//show or showid
	SearchBy searchby;
	std::string id;
	Name name;
	Grade grade;
	int g_lower_bound;	//grade lower bound
	int g_upper_bound;	//grade upper bound
};

//functor class for search by range.
class range_comp {
private:
	std::string course_;
	int lowerbound_, upperbound_;
public:
	range_comp(std::string c, int l, int u) :
			course_(c), lowerbound_(l), upperbound_(u) {
	}
	;
	bool operator()(const Student& s) {
		for (auto x : s.getGrades()) {
			if (x.getCourse() == course_ && x.getScore() >= lowerbound_
					&& x.getScore() <= upperbound_) {
				return true;
			}
		}
		return false;
	}
};

