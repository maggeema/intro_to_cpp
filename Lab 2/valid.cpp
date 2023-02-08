/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Input validation

This program asks the user to input an integer in the range 0 < n < 100.
If the number is out of range, the program should keep asking to re-enter until a valid 
number is input. After a valid value is obtained, print this number n squared. 
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "Please enter an integer: ";
    cin >> num;

    while (num <= 0 || num >= 100){
        cout << "Please re-enter: ";
        cin >> num;
    }
    
    if (num < 100 && num > 0){
        cout << "Number squared is " << pow(num,2) << endl;
    }    
}