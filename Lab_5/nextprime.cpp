/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Next prime

This program has the function
int nextPrime(int n);
that returns the smallest prime greater than n.
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

int main(){
    int num, nextprime;
    cout << "Check the next prime number after this integer: ";
    cin >> num;
    nextprime = nextPrime(num);
    cout << "The next prime number is " << nextprime;
}