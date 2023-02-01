/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Find the smallest of three integers

This program asks the user to input three integer numbers, and prints out the 
smallest of the three.
*/

#import <iostream>
using namespace std;

int main(){
    int num1, num2, num3;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the third number: ";
    cin >> num3;

    if (num1 < num2 and num1 < num3){
        cout << "The smaller of the three is " << num1;
    } else if (num2 < num1 and num2 < num3){
        cout << "The smaller of the three is " << num2;
    } else if (num3 < num1 and num3 < num2){
        cout << "The smaller of the three is " << num3;
    } 
}