// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Equal Array (E6.8)

// This program includes a function bool equals(int a[], int a_size, int b[], int b_size) 
// that checks whether two arras have the same elements in the same order

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    bool result;
    if (a_size == b_size){
        for (int i = 0; i < a_size; i++){
            if (a[i] == b[i]){
                result = true;
            } else {
                result = false;
                break;
            }
        }
    } else {
        result = false;
    }
    return result;
}