// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Homework E5.6

// This program contains a function middle(string str) that returns a string containing
// the middle character in str if the length of str is odd or the two middle characters
// are even. For example, middle("middle") returns "dd"
#include <iostream>
using namespace std;

string middle(string str){
    string middle;
    int center = str.length()/2;
    if (str.length() % 2 == 0){
        middle = str[center-1];
        middle = middle + str[center];
    } else {
        middle = str[center];
    }
    return middle;
}

int main(){
    string str = "";
    cout << "Enter a string: ";
    cin >> str;
    cout << middle(str);
    return 0;
}