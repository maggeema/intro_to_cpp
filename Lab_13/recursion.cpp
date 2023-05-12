// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Lab 13

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

int sumRange(int left, int right){
    if (left > right){
        return 0;
    } else {
        return (left + sumRange(left+1, right));
    }
}

int sumArrayInRange(int *arr, int left, int right){
    if (left > right){
        return 0;
    } else {
        return arr[left]+sumArrayInRange(arr, left+1, right);
    }
}

int sumArray(int *arr, int size){
    return sumArrayInRange(arr, 0, size-1);
}

bool isAlphanumeric(string s){
    if (s.length() == 0){
        return true;
    } else {
        char c = s[0];
        if (!(c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))){
            return false;
        } else {
            return isAlphanumeric(s.substr(1));
        }
    }
}

int main(){
    cout << isAlphanumeric("ABCD") << endl;        // true (1)
    cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
}