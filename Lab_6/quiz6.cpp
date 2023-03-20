/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Quiz 6

THis program has a function, max3(), that takes three integers, ab, b, and c,
and return the maximum of the three numbers. 
*/

#include <iostream> 
using namespace std;

int max3(int a, int b, int c){
    int max = a;
    if (b > a) {
        if (b > c){
            max = b;
        }
    } else if (c > a){
        if (c > b){
            max = c;
        }
    }
}

int main(){
    cout << max3(-5, 10, 15) << endl;
}