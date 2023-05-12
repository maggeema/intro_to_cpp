// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Is string alphanumeric?

// In the same program, add a new function

// bool isAlphanumeric(string s);
// which returns true if all characters in the string are letters and digits, otherwise returns false.

// A usage example:

// cout << isAlphanumeric("ABCD") << endl;        // true (1)
// cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
// cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
// The logic is similar to the sumRange function:

// if the sting is empty, return true.
// Otherwise,
// check the first character, and
// check that the rest of the string is alphanumeric.
// You may use the string function substr(pos, len), which extracts a substring. It takes two parameters, the starting position and the length of the substring. For example:

// string msg = "ABCDEFGH";
// cout << msg.substr(2, 4);   // CDEF (start at char [2] and
//                             //       take 4 characters)

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