/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Using arrays to store, update, and retrieve numbers

This program creates an array of 10 integers, and provides the user with an interface to edit 
any of its elements. Specifically, it should work as follows:

Create an array myData of 10 integers.
Fill all its cells with value 1 (using a for loop).
Print all elements of the array on the screen.
Ask the user to input the cell index i, and its new value v.
If the index i is within the array range (0 ≤ i < 10), update the asked cell, myData[i] = v, 
and go back to the step 3. Otherwise, if index i is out of range, the program exits.
*/

#include <iostream>
using namespace std;

int main(){
    int index, value;
    int myData[10];

    cout << "\n";
    for (int i = 0; i < 10; i++){
        myData[i] = 1;
        cout << myData[i] << " ";
    }

    do {
        cout << "\n\nInput index: ";
        cin >> index;

        cout << "Input value: ";
        cin >> value;
        cout << "\n";

        if (index >= 0 && index < 10){
            myData[index] = value;
            for (int i = 0; i < 10; i++){
                cout << myData[i] << " ";
            }
        }
    } while (index >= 0 && index < 10);
    return 0;
}