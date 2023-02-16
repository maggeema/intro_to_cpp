/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lower triangle

This program prints the bottom-left half of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main(){
    int length;
    char ch = '*';

    cout << "Input side length: ";
    cin >> length;
    cout << "\nShape:\n";

    // can't start on 0 or else it will print an empty line before printing 1 astericks
    for (int i = 1; i <= length; i++){
        for (int k = 1; k <= i; k++){
            cout << ch;
        }
        cout << "\n";
    }
}