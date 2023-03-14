/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Next twin prime

Add a function int nextTwinPrime(int n); that returns the smallest twin prime greater than n. 
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

int nextTwinPrime(int n){
    int nextTwin, ty_next;
    if (isTwinPrime(n) == true && (isPrime(n+2))){
        nextTwin = n+2;
    } else {
        ty_next = nextPrime(n);
        while (isTwinPrime(ty_next) == false){
            ty_next = nextPrime(ty_next);
        }
        nextTwin = ty_next;
    }
    return nextTwin;
}

int main(){
    int num;
    cout << "What is the next twin prime after x? Enter a twin prime, x: ";
    cin >> num;
    cout << nextTwinPrime(num);
}