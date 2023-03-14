/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E.15

This program consists of a function that swaps its three arguments to arrange them in sorted
order. For example:
int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x);
v is now 1, w is now 3, x is now 4
*/

#include <iostream>
using namespace std;

// int main(){
//     int v = 3;
//     int w = 4;
//     int x = 1;

//     sort3(v, w, x);
// }

void sort2(int& a, int& b){
    int num1 = a;
    int num2 = b;
    if (a > b){
        a = num2;
        b= num1;
    }
}

void sort3(int& a, int& b, int& c){
    sort2(a, b);
    sort2(a, c);
    sort2(b, c);
}