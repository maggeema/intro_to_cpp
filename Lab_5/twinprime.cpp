/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Is a twin prime?

A prime number N is called a twin prime if either N-2 or N+2 (or both of them) is also a prime.
For example, a prime 17 is a twin prime, because 17+2 = 19 is a prime as well.
The first few twin primes are: 3, 5, 7, 11, 13, 17, 19, 29, 31 …

Add a function bool isTwinPrime(int n); that determines whether or not its argument is a twin 
prime. Change the main function to test the new code.
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

// int previousPrime(int n){
//     bool prime = true;
//     int previous;

//     if (n < 0){
//         return -1;
//     } else {
//         for (int i = n-1; i >= 2; i--){
//             if (isPrime(i) == true){
//                 previous = i;
//             }
//         }
//         return previous;  
//     }     
// }

bool isTwinPrime(int n){
    bool twinPrime = false;
    if (isPrime(n) == true && (isPrime(n+2) == true || isPrime(n-2) == true)){
        twinPrime = true;
    }
    return twinPrime;
}

// int main(){
//     int num;
//     cout << "Check to see if an integer is a twin prime! Enter an integer: ";
//     cin >> num;
//     if (isTwinPrime(num) == true){
//         cout << "true";
//     } else {
//         cout << "false";
//     }
// }