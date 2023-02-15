/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: E3.1 Program

This program asks the user to imput a number and prints out whether it is a positive,
zero, or negative number. 
*/

#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (num > 0){
        cout << "POSITIVE";
    } else if (num < 0){
        cout << "NEGATIVE";
    } else {
        cout << "ZERO";
    }
    return 0;
}