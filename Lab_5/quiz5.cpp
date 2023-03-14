/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Quiz 5

This program prints a shape with 6 rows and 5 columns.
*/

#include <iostream>
using namespace std;

int main(){
    int rows = 6;
    int columns = 5;
    char ch = '+';

    for (int i = 0; i < rows; i++){
        for (int k = 0; k < columns; k++){
            cout << ch;
        }
        cout << "\n";
    }
}