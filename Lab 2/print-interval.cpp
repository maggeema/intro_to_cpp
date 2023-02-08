/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Print all integers from the requested interval

This program asks the user to input two integers L and U (representing the lower and upper
limits of the interval), and print out all integers in the range L <= i < U separated by 
spaces. Notice that we include the lower limit, but exclude the upper limit. 
*/

#include <iostream> 
#include <cstdlib>
using namespace std;

int main(){
    int lower, upper, range;

    cout << "Please enter L: ";
    cin >> lower;

    cout << "Please enter U: ";
    cin >> upper;

    range = abs(lower) + abs(upper);

    for (int i = 0; i < range+1; i++){
        cout << lower << " ";
        lower += 1;
    }
}