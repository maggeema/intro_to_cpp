// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Removing indentation

// This program removes all whitespace in each inputted line

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

string removeLeadingSpaces(string line){
    string result = "";
    for (int i = 0; i < line.length(); i++){
        if (i == 0 && isspace(line[i])){
            continue;
        } else if ((isspace(line[i])) && (!isspace(line[i-1]) && !isspace(line[i+1]))){
                result = result + line[i];
        } else if (!isspace(line[i])){
            result = result + line[i];
        } 

    }
    return result;
}

int main(){
    // string input;

    // cout << "Enter a file name: ";
    // cin >> input;
    // ifstream fin(input);
    string line;

    // if (fin.fail()){
    //     cerr << "File cannot be opened for reading.\n";
    //     exit(1);
    // }

    while(getline(cin, line)){
        cout << removeLeadingSpaces(line) << "\n";
    }
    // fin.close();
    return 0;
}