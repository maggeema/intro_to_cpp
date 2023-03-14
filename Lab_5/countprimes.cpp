/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Count primes in range

Add a function
int countPrimes(int a, int b);
that returns the number of prime numbers in the interval a ≤ x ≤ b. 
*/

#include <iostream>
using namespace std;

int nextPrime(int n){
    bool prime = true;
    int num, next;

    if (n < 0){
        return 2;
    } else {
        for (int i = 1; i < n+i; i++){
            num = n+i;
            for (int k = 2; k < num; k++){
                if (num % k == 0){
                    prime = false;
                    break;
                } else {
                    prime = true;
                }
            }
            if (prime == true){
                next = num;
                break;
            }
        }
        return next;  
    }      

}

int countPrimes(int a, int b){
    bool prime
}