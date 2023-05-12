// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Sum of elements in array

// In the same program, add a new function
// int sumArray(int *arr, int size);
// which receives an array (as a pointer to its first element) and the size of the array, and 
// should return the sum of its elements. The function itself should not do any new dynamic 
// memory allocations.

// There are several approaches to this task:

// One possible strategy is to define a helper function
// sumArrayInRange(int *arr, int left, int right);
// which adds up all elements of the passed array, but only for indexes in the interval 
// left <= i <= right. It can be implemented very similarly to the function sumRange, but it 
// should be adding the elements of the array instead of range indices.
// Then sumArray(arr, size) can be defined as
// sumArrayInRange(arr, 0, size-1).

// Alternatively, can you maybe get away with just using the original function?
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