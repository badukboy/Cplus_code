/*
 * Lab1.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: leon
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int lab1_main_a(int argc, char** argv) {
	cout << uppercase << setw(10) << "dec" << setw(12) << "oct" << setw(9) << "hex" << endl;
	cout << string(10, '-') << " " << string(11, '-') << " " << string(8, '-')
			<< endl;
	string line;
	int n;
	while (1) {
		//cout << "Enter an integers" << endl;
		if (!getline(cin, line))
			break;
		istringstream iss(line);
		while (iss >> n) {
			if (n < 0)
				continue;
			cout << setw(10) << dec << n << setw(12) << oct << n << setw(9)
					<< hex << n << endl;
		}
		cin.clear();
	}
	return 0;
}

int lab1_main_b(int argc, char** argv) {

	string line;
	double n;
	double sum = 0;
	int count = 0;
	while (1) {
		//cout << "Enter an integers" << endl;
		if (!getline(cin, line))
			break;
		istringstream iss(line);
		while (iss >> n) {
			sum += n;
			count += 1;
			cout << string(5,' ')<< setw(12) << fixed << showpos << internal << setprecision(2)<< n << endl;
		}
		cin.clear();
	}
	cout << string(17, '-') << endl;
	cout << "avg: "<< setw(12) << showpos << internal << setprecision(2)<< sum/count << endl;
	return 0;
}

