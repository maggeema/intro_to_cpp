/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Is prime?

A prime number is an integer greater or equal to 2 that is only divisible by 1 and by itself.
The first few primes are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 …

N is a prime if and only if it is not divisible evenly by any of the numbers from 2 to N−1. 
Let’s implement this decision as a function.

In the same program numbers.cpp, add a function

bool isPrime(int n);
The function should return true if n is a prime, otherwise return false. Change the main 
function to test your new code.
*/
#include <cstdlib>
#include <iostream>
using namespace std;


bool isPrime(int n){
    bool prime;
    if (n == 2){
        prime = true;
    } else if (n == 1 || n == 0){
        prime = false;
    } else if (n < 0){
        prime = false;
    } else {
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                prime = false;
                break;
            } else {
                prime = true;
            }
        }
    }
    return prime;
}

int main(){
    int x;
    bool prime;

    cout << "Is x a prime number? \nEnter an integer for x: ";
    cin >> x;

    prime = isPrime(x);

    if (prime == false){
        cout << "No";
    } else {
        cout << "Yes";
    }
}