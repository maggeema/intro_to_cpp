/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Cross

This program asks the user to input the shape size, and prints a diagonal cross of that 
dimension.
*/

#include <iostream>
using namespace std;

int main(){
    int size;
    char ch = '*';

    cout << "Input size: ";
    cin >> size;
    cout << "\nShape:\n";

    for (int i = 0; i < size; i++){
        for (int k = 0; k < size; k++){
            if (k == i || k == size-i-1){
                cout << ch;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}