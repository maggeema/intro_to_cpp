/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E.14

This program consists of a function that swaps the values of a and b,
if a is greater than b and otherwise leaves a and b unchanged. For
example, int u = 2, v = 3, int w = 4, int x = 1;
sort2(u,v) is still 2 and 3
sort2(w,x) changes w to 1 and x to 4
*/
#include <iostream>
using namespace std;

int main(){
    int u = 2;
    int v = 3;
    int w = 4;
    int x = 1;

    sort2(u,v);
    sort2(w,x);
}

void sort2(int& a, int& b){
    int num1 = a;
    int num2 = b;
    if (a > b){
        a = num1;
        b= num2;
    }
}