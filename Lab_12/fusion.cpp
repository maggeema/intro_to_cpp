// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: It's over 9000!

// This program implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) 
// that appends elements of the second vector into the first and empties the second vector

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta){
    int index = 0;
    for (int i = 0; i < vegeta.size(); i++){
        // if (goku.capacity() < vegeta.size()){
        // } 
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}