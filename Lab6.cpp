/*
 * Lab6.cpp
 *
 *  Created on: Oct 17, 2013
 *      Author: leon
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Grades {
	string id;
	map<string, int> scores;
};

inline ostream& operator<<(ostream& os, const Grades& g) {
	os << g.id << endl;
	os << g.scores.size() << endl;
	for (auto x : g.scores) {
		os << x.first << " " << x.second << endl;
	}
	return os;
}

inline istream& operator>>(istream& is, Grades& g) {
	string name;
	int score;
	size_t i, count;

	if(!(is >> g.id)){
		return is;
	}

	is >> count;
	g.scores.clear();
	for (i = 0; i < count; ++i) {
		is >> name >> score;
		g.scores.insert(pair<string, int>(name, score));
	}
	return is;
}

class Cmp {
private:
	string courseName_;
public:
	Cmp(string name) :
			courseName_(name) {
	}
	;
	bool operator()(const Grades& g1, const Grades& g2) {
//		auto sc1map = g1.scores;
//		auto sc2map = g2.scores;
//		if (sc1map.find(courseName_) == sc1map.end()
//				&& sc2map.find(courseName_) != sc2map.end()) {
//			return false;
//		}else if (sc1map.find(courseName_) != sc1map.end()
//				&& sc2map.find(courseName_) == sc2map.end()){
//			return true;
//		}else if (sc1map.find(courseName_) == sc1map.end()
//				&& sc2map.find(courseName_) == sc2map.end()){
//			return true;
//		}else {
//			return !(sc1map.find(courseName_)->second < sc2map.find(courseName_) ->second);
//		}
		auto s1it = g1.scores.find(courseName_);
		auto s2it = g2.scores.find(courseName_);
		auto s1 = s1it == g1.scores.end() ? -1 : s1it->second;
		auto s2 = s2it == g2.scores.end() ? -1 : s2it ->second;
		return s1 > s2 ;
	}
};

class Stats{
private:
	int sum_,count_;
	double average_;
	string name_;
public:
	Stats(string n):name_(n){
		sum_ = 0;
		count_ = 0;
		average_ = 0;
	}
	Stats& operator()(const Grades& g){
		if(g.scores.find(name_) != g.scores.end()){
			sum_ += g.scores.find(name_)->second;
			count_++;
			average_ = (double)sum_ / count_;
		}
		return *this;
	}
	int getAvg() const {
		return average_;
	}
};

int lab6_main(int argc, char** argv) {
	vector<Grades> vog;
	Grades g;
	while(cin >> g){
		vog.push_back(g);
	}

	cerr << "begin sorting" << endl;
	sort(vog.begin(),vog.end(),Cmp("COMP3512"));
	cerr << "done sorting" << endl;

	for(auto x : vog){
		cout << x << endl;
	}

	cout << endl;
	cerr << "start calculate avg" << endl;
	Stats a = for_each(vog.begin(), vog.end(), Stats("COMP3512"));
	cout << "Average is : " << a.getAvg() << endl;
	cerr << "done calculating" << endl;

	cerr << "check out put" << endl;

	return 0;
}

