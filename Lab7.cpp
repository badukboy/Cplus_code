#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <sstream>

#define N 10000000

using namespace std;

string num2str(int i) {
	string Result;
	ostringstream convert(Result);
	convert << i;
	return convert.str();
}

string hashKey(int i) {
	string word = num2str(i);
	sort(word.begin(), word.end());
	return word;
}

map<string, vector<int> > findPrimes() {
	bitset<N> isPrime;
	map<string, vector<int> > result;
	isPrime.set();
	for (size_t i = 2; i < sqrt(N); i++) {
		if (isPrime[i]) {
			for (size_t j = i; j * i < N; j++) {
				isPrime[i * j] = 0;
			}
		}
	}
	for (size_t i = 1000000; i <= 9999999; i++) {
		if (isPrime[i]) {
			string key = hashKey(i);
			result[key].push_back(i);
		}
	}
	return result;
}

bool cmp(pair<string, vector<int> > p1, pair<string, vector<int> > p2) {
	return p1.second.size() < p2.second.size();
}

int lab7_main(int argc, char** argv) {
	auto m = findPrimes();

	auto max = max_element(m.begin(), m.end(), cmp);

	cout << max->second.size() << endl;

	for (auto x : max->second) {
		cout << x << " " << endl;
	}

	return 0;
}
