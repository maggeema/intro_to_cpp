// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Print all numbers in range

#include <iostream>
using namespace std;

void printRange(int left, int right){
    if (left == right){
        cout << left << endl;
    } else {
        cout << left << " ";
        printRange(left++, right);
    }
}

int sumRange(int left, int right){
    if (left > right){
        return 0;
    } else {
        return (left + sumRange(left+1, right));
    }
}

int main() {
    int x = sumRange(1, 3);
    cout << "This is" << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is" << y << endl;   // 52
}