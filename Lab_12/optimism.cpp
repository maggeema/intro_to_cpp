// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Happy filter

// This program implements the function vector<int> goodVibes(const vector<int>& v); that, 
// given a vector of integers, returns a vector with only the positive integers in the same 
// order.

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v){
    vector<int> mags;
    for (int i = 0; i < v.size(); i++){
        if (v[i] >= 0){
            mags.push_back(v[i]);
        }
    }
    return mags;
}