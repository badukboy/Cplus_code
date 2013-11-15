#include "Lab8.h"
#include <iostream>
#include <map>

using namespace std;

int lab8_main(int argc, char** argv) {
	try {
		//Student s("a12345678", "Homer", "Simpson");
		//cout << s << endl;
		//Student s2("AAA", "carl", "carlson");

		map<Student, int> m;
		Student s;
		int score;
		while (cin >> s >> score)
			m[s] += score;
		cout << endl;
		for (auto x : m) {
			cout << x.first << " " << x.second << endl;
		}
		return 0;
	} catch (const char * s) {
		cerr << s << endl;
		return 0;
	}
}
