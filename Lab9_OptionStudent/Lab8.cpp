//============================================================================
// Name        : Lab8.cpp
// Author      : Leon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lab8.h"
#include <map>
#include "OptionStudent.h"
using namespace std;

int main() {
	try {
		OptionStudent s("a12345678", "Homer", "Simpson", 3, "IS");
		cout << s << endl;
		s.display(cout);


	} catch (const char * s) {  // because above is a c-style string
		cerr << s << endl;
	}
}
