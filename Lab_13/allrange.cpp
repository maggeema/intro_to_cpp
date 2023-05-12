// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Print all numbers in range

#include <iostream>
using namespace std;

void printRange(int left, int right){
    if (left > right){
        return;
    } else {
        cout << left << " " ;
        left++;
        printRange(left, right);
    }
}

int main() {
    printRange(-2, 10);
    return 0;
}