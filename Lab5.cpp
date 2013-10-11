/*
 * Lab5.cpp
 *
 *  Created on: Oct 10, 2013
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
#include <vector>

using namespace std;

void print(vector<vector<int> > v) {
	vector<vector<int> >::iterator it;
	cout << "[";
	for (it = v.begin(); it != v.end(); ++it) {
		cout << "[";
		vector<int>::iterator innerit;
		for (innerit = it->begin(); innerit != it->end(); ++innerit) {
			cout << *innerit << ", ";
		}
		cout << "]";
	}
	cout << "]";
}

vector<vector<int> > interleave(int x, const vector<int>& v) {
	vector<vector<int> > result;
	if (x == 1) {
		result.push_back(v);
		return result;
	}
	for (vector<int>::size_type i = 0; i <= v.size(); ++i) {
		vector<int> temp(v);
		if (i == v.size()) {
			temp.push_back(x);
		} else {
			temp.insert(temp.begin() + i, x);
		}
		result.push_back(temp);
	}
	return result;
}

vector<vector<int> > permute(size_t n) {
	vector<vector<int> > result;
	vector<vector<int> > v;
	if (n == 1) {
		vector<int> temp;
		temp.push_back(1);
		result.push_back(temp);
		return result;
	} else {
		vector<vector<int> > temp;
		vector<vector<int> >::iterator it;
		temp = permute(n - 1);
		for (it = temp.begin(); it != temp.end(); ++it) {
			v = interleave(n, *it);
			result.insert(result.end(), v.begin(), v.end());
		}
	}
	return result;
}


int lab5_main(int argc, char** argv) {
	vector<vector<int> > v = permute(10);
	cout<< v.size() << endl;
	print(v);
	return 0;
}

