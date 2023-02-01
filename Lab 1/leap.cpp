/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: A leap year or a common year

This program asks the user to input an integer representing a year number (1999, 2016, etc.). 
If the input year is a leap year according to the modern Gregorian calendar, it should print 
Leap year, otherwise, print Common year.
*/

#include <iostream> 
using namespace std;

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    // year is not divisible by 4 = common year
    // year is not divisible by 100 = leap year
    // year is not divisible by 400 = common year
    // else, it is a leap year
    if (year % 4 != 0){
        cout << "Common Year";
    } else if (year % 100 != 0){
        cout << "Leap Year";
    } else if (year % 400 != 0){
        cout << "Common Year";
    } else {
        cout << "Leap Year";
    }
}