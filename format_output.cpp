/* 
 * File:   main.cpp
 * Author: leon
 *
 * Created on January 11, 2013, 3:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//void read_and_out(istream& in, ostream& out) {
//    string line;
//    int n;
//    while (1) {
//        //out << "Enter an integers" << endl;
//        if (!getline(in, line))
//            break;
//        istringstream iss(line);
//        if (iss >> n)
//            out << setw(10) << internal << showpos << n << endl;
//    }
//}
//
//bool read_and_out_h(istream& in, ostream& out) {
//    string line;
//    int n;
//    while (1) {
//        //out << "Enter an integers" << endl;
//        if (!getline(in, line))
//            break;
//        istringstream iss(line);
//        if (iss >> n && n >= 0)
//            out << setw(10) << hex << uppercase << n << endl;
//    }
//}
//
//bool read_and_out_o(istream& in, ostream& out) {
//    string line;
//    int n;
//    while (1) {
//        //out << "Enter an integers" << endl;
//        if (!getline(in, line))
//            break;
//        istringstream iss(line);
//        if (iss >> n && n >= 0)
//            out << setw(10) << oct << noshowbase << n << endl;
//    }
//}

void read_and_out(istream& in, ostream& out, int type) {
    string line;
    int n;
    while (1) {
        //out << "Enter an integers" << endl;
        if (!getline(in, line))
            break;
        istringstream iss(line);
        if (iss >> n )
            if (type == 0) {
                out << setw(10) << internal << showpos << n << endl;
            } else if (type == 1 && n >= 0) {
                out << setw(10) << hex << uppercase << n << endl;
            } else if (type == 2 && n >= 0) {
                out << setw(10) << oct << noshowbase << n << endl;
            }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 2 && argc != 1) {
        cout << "usage: usage information\n";
        return 0;
    }

    if (argc == 1) {
        read_and_out(cin, cout,0);
    } else if (string(argv[1]) == "-x") {
        read_and_out(cin, cout,1);
    } else if (string(argv[1]) == "-o") {
        read_and_out(cin, cout,2);
    } else {
        cout << "option only can be -o or -x.\n";
    }

    return 0;
}



