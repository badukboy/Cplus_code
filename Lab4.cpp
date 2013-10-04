/*
 * Lab4.cpp
 *
 *  Created on: Oct 3, 2013
 *      Author: leon
 */

#include <cstdlib>
#include <string>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

string delete_all(const string& s, const string& junk) {
	string result = s;
	size_t found = result.find(junk);
	while (found != string::npos) {
		result.erase(found, junk.length());
		found = result.find(junk);
	}
	return result;
}

bool is_junk(char c) {
	return isspace(c);
}

string ltrim(const string& s, bool (*is_junk)(char)) {
	size_t startpos = 0;
	while (startpos != string::npos && is_junk(s[startpos++]))
		;
	return s.substr(startpos - 1);
}

string rtrim(const string& s, bool (*is_junk)(char)) {
	size_t stoppos = s.length();
	while (stoppos != 0 && is_junk(s[--stoppos]))
		;
	return s.substr(0, stoppos + 1);
}


string squeeze(const string& s, char c) {
	string result = s;
	size_t found = result.find(c);
	while (found != string::npos) {
		++found;
		while (found != result.length()) {
			if (result[found] != c)
				break;
			result.erase(found, 1);
		}
		found = result.find(c, found);
	}
	return result;
}

int lab4_main(int argc, char** argv) {
	string s("a123kflkadfj123kjlajfkd123kkkk");
	string junk("123");
	cout << delete_all(s, junk) << endl;
	cout << ltrim(" \t    ", is_junk) << endl;
	cout << rtrim("012345      ", is_junk) << endl;
	cout << squeeze("a1111gdsga11111gggdsg11111", '1') << endl;
	return 0;
}
