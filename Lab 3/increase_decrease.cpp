// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: E3.5

// This program asks the user to input three integers and prints out whether the inputs were
// given in increasing/decreasing order or neither. 


#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3;
    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter another integer: ";
    cin >> num2;

    cout << "Enter a last integer: ";
    cin >> num3;

    if (num1 < num2 && num2 < num3){
        cout << "Increasing";
    } else if (num3 < num2 && num2 < num1){
        cout << "Decreasing";
    } else {
        cout << "Neither";
    }
}