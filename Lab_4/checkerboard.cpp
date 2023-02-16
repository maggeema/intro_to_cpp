/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Checkerboard

This program asks the user to input width and height and prints a rectangular checkerboard of 
the requested size using asterisks and spaces (alternating).
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
    cout << "\nShape: \n";

    for (int i = 0; i < height; i++){
        for (int k = 0; k < width; k++){
            if (i % 2 == 0){
                if (k % 2 == 0){
                    cout << ch;
                } else {
                    cout << " ";
                }
            } else {
                if (k % 2 == 0){
                    cout << " ";
                } else {
                    cout << ch;
                }
            }
        }
        cout << "\n";
    }
}