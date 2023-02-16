/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Upper triangle

This program prints the top-right half of a square, given the side length.
*/

#include <iostream>
using namespace std;

int main(){
    int length;
    char ch = '*';

    cout << "Input side length: ";
    cin >> length;
    cout << "\nShape:\n";

    // have num of iterations of lines be equal to length
    for (int i = length; i > 0; i--){
        // if length is 5
        // when i = 4 and k = 4; print out space
        // when i = 4 and k = 3; print out char
        // when i = 4 and k = 2; print out char
        // when i = 4 and k = 1; print out char
        // ...

        for (int k = length; k > 0; k--){
            if (k <= i){
                cout << ch;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}