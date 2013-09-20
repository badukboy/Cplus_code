/* 
 * File:   main.cpp
 * Author: leon
 *
 * Created on January 18, 2013, 3:28 PM
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

bool get_command(const string& prompt, int& n){
    string line;
    while(1){
         cout << prompt;
         if (!getline(cin, line))
            break;
        istringstream iss(line);
        if(iss >> n){
            if(n == 0){
                return false;
            }
            return true;              
        }            
    }
    cin.clear();
    return false;
}

void display_n(istream& in ,const int n){
    string id;
    int score;
    ios::pos_type pos = 14 * (n - 1);
    in.seekg(pos, ios_base::beg);
    if(in >> id && in >> score){
        cout << "id: " << id << " score: " << score << endl;
        return;
    }
    cout << " no such recored." << endl;
    in.clear();
}

void display_all_fromn(istream& in ,const int n){
    string id;
    int score;
    ios::pos_type pos = 14 * (n - 1);
    in.seekg(pos,ios_base::beg);
    if(in >> id && in >> score){
        cout << "id: " << id << " score: " << score << endl;
    }else{
        cout << "seek past the EOF." << endl;
    }
    while(in >> id && in >> score){
        cout << "id: " << id << " score: " << score << endl;
    }
    in.clear();
}
/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    cout << argv[1] << endl;
    ifstream in(argv[1], ios_base::in|ios_base::binary);
        if(!in){
        cerr<<"unable to open students.dat file."<< endl;
        return 1;
    }
    while(get_command("please input a number: ",n)){
        if(n > 0){
            display_n(in, n);
        }else{
            display_all_fromn(in, -n);
        }
    }      
    return 0;
}





