/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Fidn the smaller of two integers

This program asks the user to input two integer numbers and prints
out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    if (num1 < num2){
        cout << "The smaller of the two is " << num1 << endl;
    } else if (num2 < num1){
        cout << "The smaller of the two is " << num2 << endl;
    } else {
        cout << "The two numbers are equal"
    }
}
