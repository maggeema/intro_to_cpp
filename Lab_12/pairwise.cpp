// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Pairwise sum

// This program implements vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) that 
// returns a vector of integers whose elements are the pairwise sum of the elements from the 
// two vectors passed as arguments. If a vector has a smaller size than the other, consider 
// extra entries from the shorter vectors as 0.

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    vector<int> sums, bigger, smaller;
    if (v1.size() > v2.size()){
        for (int i = v2.size(); i < v1.size(); i++){
            v2.push_back(0); 
        }
    } else if (v2.size() > v1.size()){
        for (int i = v1.size(); i < v2.size(); i++){
            v1.push_back(0); 
        }
    }

    for (int k = 0; k < v1.size(); k++){
        sums.push_back(v1[k] + v2[k]);
    }

    return sums;
}