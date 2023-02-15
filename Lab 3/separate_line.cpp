// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: E4.8

// This program asks the user to input a string value and prints each character on separate
// lines.

#include <iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter your first name: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++){
        cout << s[i] << endl;
    }
}