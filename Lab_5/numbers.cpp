/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5

This program checks for divisibility, prime, etc. 
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d){
    if (n % d == 0){
        return true;
    } else {
        return false;
    }
}

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