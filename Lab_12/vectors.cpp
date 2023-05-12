// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: The easy one

// This program is a function called vector<int> makeVector(int n) that returns a vector of n 
// integers that range from 0 to n-1. The function is implemented outside the main function 
// and must return a vector.

#include <vector>
#include <iostream>
using namespace std;

vector<int> makeVector(int n){
    vector<int> vectie;
    for (int i = 0; i < n; i++){
        vectie.push_back(i);
    }
    return vectie;
}