/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Is divisible?

This program defines a function bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){
    if (n % d == 0){
        return true;
    } else {
        return false;
    }
}


int main(){
    int x, y;
    bool divisible;

    cout << "Is x divisible by y? \nEnter an integer for x: ";
    cin >> x;
    cout << "Enter an integer for y: ";
    cin >> y;
    divisible = isDivisibleBy(x, y);

    if (divisible == true){
        cout << "Yes";
    } else {
        cout << "No";
    }
}