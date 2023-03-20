// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Testing ASCII

// This program asks the user to input a line of text (which may possibly include spaces). 
// The program should report all characters from the input line together with their ASCII 
// codes.

#include <iostream>
#include <istream>
using namespace std;

int main(){
    string input;
    char ch[100];

    cout << "Input: ";
    getline(cin, input);
    cout << "\n"; 

    for (int i = 0; i < input.length(); i++){
        ch[i] = input[i];
        cout << input[i] << " " << (int)ch[i] << "\n";
    }
    return 0;
}