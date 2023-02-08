/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Computing Fibonacci Numbers with Loops and Arrays 0, 1, 1, 2, 3, 5, 8, 13...

This program that uses an array of ints to compute and print all Fibonacci numbers from
F(0) to F(59).
*/

#include <iostream>
using namespace std;

int main(){
    int index;
    int fib[60];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (int k = 0; k < 60; k++){
        cout << fib[k] << "\n\n";
    }
    return 0;
}

// when the code hit i = 47 (which is supposed to be 2,971,215,073), the integers that are 
// printed are displayed as negative. This is occuring because an int data type only has 
// 4 bytes (32 bits) to store a value, and c++ is only able to detect 31 bits for value for 
// assigned int values (the last bit assigned in c++ for a negative sign, which probably
// represents a value that exceeds its capibility of storage)