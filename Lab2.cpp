/*
 * Lab2.cpp
 *
 *  Created on: Sep 19, 2013
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

using namespace std;

bool is_valid_ID(const string& id) {
	if (id.length() != 9 || id[0] != 'A') {
		return false;
	}
	for (string::size_type i = 1; i < id.length(); i++) {
		if (!isdigit(id[i])) {
			return false;
		}
	}
	return true;
}

bool is_valid_score(int score){
    return score >=0 && score <= 100;
}

bool get_valid_word(const string& prompt, string& word, bool (*is_valid)(const string&) = 0){
    string line;
    string temp;
    while(1){
         cout << prompt;
         if (!getline(cin, line))
            break;
        istringstream iss(line);
        if(iss >> temp){
            if(is_valid == 0 || is_valid(temp)){
                word = temp;
                return true;
            }
        }
    }
    cin.clear();
    return false;
}

bool get_valid_int(const string& prompt, int& n, bool (*is_valid)(int) = 0){
    string line;
    int score;
    while(1){
         cout << prompt;
         if (!getline(cin, line))
            break;
        istringstream iss(line);
        if(iss >> score){
            if(is_valid == 0 || is_valid_score(score)){
                n = score;
                return true;
            }
        }
    }
    cin.clear();
    return false;
}

int lab2_main(int argc, char** argv) {
    int score;
    string word;
    while(get_valid_word("please inter ID. \n ", word , is_valid_ID) &&
            get_valid_int("please inter score \n ", score, is_valid_score)){
        cerr << word << " " << score << endl;
    }
    return 0;
}
