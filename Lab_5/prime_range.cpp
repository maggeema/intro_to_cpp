/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Count Prime In Range

Add a function int countPrimes(int a, int b); that returns the number of prime numbers in the
interval a ≤ x ≤ b. Change the main function to test the new code.
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

int countPrimes(int a, int b){
    int count = 0;

    for (int i = a; i <= b; i++){
        if (isPrime(a) == true){
            count++;
        }
        a++;
    }
    return count;
}

int main(){
    int a, b;
    cout << "Enter a starting number for range: ";
    cin >> a;
    cout << "Enter an ending number for range: ";
    cin >> b;

    cout << countPrimes(a, b);
}

