/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Box

This program sks the user to input width and height and prints a solid rectangular box of the
requested size using asterisks.

Also, print a line Shape: between user input and the printed shape (to separate input from 
output).
*/

#include <iostream>
using namespace std;

int main(){
    int width, height;
    char ch = '*';

    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    cout << "\nShape:" << endl;


    for (int i = 0; i < height; i++){
        for (int k = 0; k < width; k++){
            cout << ch;
        }
        cout << '\n';
    }
}