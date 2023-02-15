// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 3

// This program creates an array of 10 integers, uses a for loop to initialize the values 
// from 1 to 10, and prints each number on a separate line. 

#include <iostream>
using namespace std;

int main() {
  int arr[10];
  int num = 1;

  for (int i = 0; i < 10; i++) {
    arr[i] = num;
    cout << arr[i] << endl;
    num += 1;
  }
  return 0;
}