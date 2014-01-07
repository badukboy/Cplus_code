//============================================================================
// Name        : Asn1.cpp
// Author      : Liang Yang
// Version     : 3.0
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include "Asn1.h"
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//validate command (show / showid)
bool is_valid_command(const string& word, CommandArgument& com) {
	if (word == "show") {
		com.idonly = false;
		return true;
	} else if (word == "showid") {
		com.idonly = true;
		return true;
	} else {
#ifdef DEBUG
		cerr << "Invalid command" << endl;
#endif
		return false;
	}
}

//get and validate command argument
bool get_command_argument(istream& iss, string& word, CommandArgument& com) {
	int num1, num2;
	string nextword;
	if (word == "id" && iss >> word) {
		com.searchby = byid;
		com.id = word;
		return true;
	} else if (word == "name" && iss >> word && iss >> nextword) {
		if (word == "*" && nextword == "*") {
			com.searchby = byname;			
		} else if (word == "*") {
			com.searchby = bylastname;
		} else if (nextword == "*") {
			com.searchby = byfirstname;
		} else {
			com.searchby = byfullname;
		}
		com.name = Name(word, nextword);
		return true;
	} else if (word == "grade" && iss >> word && iss >> num1) {
		if (iss >> num2) {
			com.searchby = bygraderange;
			com.grade = Grade(word, 0);
			com.g_lower_bound = num1;
			com.g_upper_bound = num2;
			return true;
		} else {
			com.searchby = bygrade;
			com.grade = Grade(word, num1);
			return true;
		}
	} else {
#ifdef DEBUG
		cerr << "Invalid searchby option" << endl;
#endif
		return false;
	}
}

//get command from user and set up command argument
bool get_command(const string& prompt, CommandArgument& com) {
	string line, word;
	while (1) {
		cerr << prompt;
		if (!getline(cin, line))
			break;
		istringstream iss(line);
		if (!(iss >> word) || !is_valid_command(word, com)) {
			cout << endl;
			continue;
		}
		if (iss >> word) {
			if (get_command_argument(iss, word, com)) {
				return true;
			} else {
				cout << endl;
				continue;
			}
		} else {
			com.searchby = all;
			return true;
		}
	}
	cin.clear();
	return false;
}

//return a set of students that satisfy the requirement specified by command argument
set<Student> searchStudent(const set<Student>& students, CommandArgument& ca) {
	set<Student> result;
	switch (ca.searchby) {
	case byid:
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				[&ca](const Student& s) {return s.getId() == ca.id;});
		return result;
	case byfirstname:
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				[&ca](const Student& s) {return s.getName().getFirst() == ca.name.getFirst();});
		return result;
	case bylastname:
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				[&ca](const Student& s) {return s.getName().getLast() == ca.name.getLast();});
		return result;
	case byfullname:
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				[&ca](const Student& s) {return s.getName() == ca.name;});
		return result;
	case bygrade:
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				[&ca](const Student& s) {return any_of(s.getGrades().begin(),s.getGrades().end(), [&ca](const Grade& g) {
								return g == ca.grade;
							});});
		return result;
	case bygraderange:
		//use functor here.
		copy_if(students.begin(), students.end(), inserter(result,result.begin()),
				range_comp(ca.grade.getCourse(), ca.g_lower_bound,
						ca.g_upper_bound));
		return result;
	default:
		return students;
	}
}

void displayResult(const set<Student>& result, bool idonly) {
	for (auto s : result) {
		if (idonly) {
			cout << s.getId() << endl;
		} else {
			s.display(cout);
		}
	}
}

int main(int argc, char* argv[]) {
	set<Student> students;
	Student s;
	CommandArgument ca;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "unable to open" << argv[1] << endl;
		return 0;
	}
	while (in >> s) {
		students.insert(s);
	}
	while (get_command("Enter command.", ca)) {
		auto result = searchStudent(students, ca);
		displayResult(result,ca.idonly);
		cout << endl;
	}
	return 0;
}
