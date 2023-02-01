/*
Author: Maggie Ma
Course: CSCI-135 RECITATION (W, 9:30am-11:20am)
Instructor: Exhil Osmanllari
Assignment: QUIZ 2

This program asks the user for two integers (x and y) and prints the bigger of the two.
*/

#include <iostream>
using namespace std;

int main(){
    int x, y;
    cout << "Enter an integer for x: ";
    cin >> x;
    cout << "Enter an integer for y: ";
    cin >> y;

    if (x > y){
        cout << x;
    } else if (y > x){
        cout << y;
    }
}