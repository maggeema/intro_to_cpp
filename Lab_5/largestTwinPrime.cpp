/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Largest Twin Prime

Add a function int largestTwinPrime(int a, int b); that returns the largest twin prime in the 
range a ≤ N ≤ b. If there is no twin primes in range, then return -1.

For example:
largestTwinPrime(5, 18) == 17
largestTwinPrime(1, 31) == 31
largestTwinPrime(14, 16) == -1
Change the main function to test the new code.
*/

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

bool isTwinPrime(int n){
    bool twinPrime = false;
    if (isPrime(n) == true && (isPrime(n+2) == true || isPrime(n-2) == true)){
        twinPrime = true;
    }
    return twinPrime;
}

int largestTwinPrime(int a, int b){
    // int max = -1;
    // for (int i = a; i <= b; i++){
    //     if ((isTwinPrime(i) == true) && (i > max)){
    //         max = i;
    //     } 
    //     a++;
    // }
    // return max;
    int max = -1;
    for (int i = b; b >= a; i--){
        if ((isTwinPrime(i) == true)){
            max = i;
            break;
        }
        b--;
    }
    return max;
}

int main(){
    int start, end;
    cout << "I can look for the largest twin prime within a range. \nEnter a starting number for the range: ";
    cin >> start;
    cout << "Enter a ending number: ";
    cin >> end;

    cout << largestTwinPrime(start, end);
}