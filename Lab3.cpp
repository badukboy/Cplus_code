/*
 * Lab3.cpp
 *
 *  Created on: Sep 26, 2013
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

#define IDSIZE 10

using namespace std;

struct Record {
	char id[IDSIZE];
	int score;
};

////////////////////////////////////////////////////////////////////////////////
bool is_valid_ID(const string& id);
bool is_valid_score(int score);
bool get_valid_word(const string& prompt, string& word,
		bool (*is_valid)(const string&) = 0);
bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int) = 0);
///////////////////////////////////////////////////////////////////////////////////

bool get_command(const string& prompt, int& n) {
	string line;
	while (1) {
		cout << prompt;
		if (!getline(cin, line))
			break;
		istringstream iss(line);
		if (iss >> n) {
			if (n == 0) {
				return false;
			}
			return true;
		}
		cout << "Invalid command" << endl;
	}
	cin.clear();
	return false;
}

void display_n(fstream& file, const int n) {
	string id;
	ios::pos_type pos = sizeof(Record) * (n - 1);
	file.seekg(pos, ios_base::beg);
	Record r;
	file.read(r.id, sizeof(Record));
	if (file) {
		string id(r.id);
		cout << "id: " << id << " score: " << r.score << endl;
		return;
	}
	cout << "seek past the EOF." << endl;
	file.clear();
}

void display_all_fromn(fstream& file, const int n) {
	string id;
	ios::pos_type pos = sizeof(Record) * (n - 1);
	file.seekg(pos, ios_base::beg);
	Record r;
	file.read(r.id, sizeof(Record));
	if (!file) {
		cout << "seek past the EOF." << endl;
		file.clear();
		return;
	} else {
		string id(r.id);
		cout << "id: " << id << " score: " << r.score << endl;
	}
	while (1) {
		file.read(r.id, sizeof(Record));
		if (!file) {
			file.clear();
			return;
		}else {
			string id(r.id);
			cout << "id: " << id << " score: " << r.score << endl;
		}
	}
}
/*
 *
 */

int lab3_main(int argc, char** argv) {
	Record sr;
	int n;
	cout << argv[1] << endl;
	cout << "size of int: " << sizeof(int) << endl;
	fstream file(argv[1],
			ios_base::in | ios_base::out | ios_base::trunc | ios_base::binary);
	if (!file) {
		cerr << "unable to open students.dat file." << endl;
		return 1;
	}
	while (get_command("\n1.Input records\n2.Display records\n", n)) {
		if (n == 1) {
			string srstring;
			while (get_valid_word("please inter ID. \n ", srstring, is_valid_ID)
					&& get_valid_int("please inter score \n ", sr.score,
							is_valid_score)) {
				strcpy(sr.id, srstring.c_str());
				file.write(sr.id, sizeof(Record));
			}
		} else if (n == 2) {
			while (get_command("please input a number: ", n)) {
				if (n > 0) {
					display_n(file, n);
				} else {
					display_all_fromn(file, -n);
				}
			}
		} else {
			cout << "Invalid command" << endl;
		}
	}
	return 0;
}

