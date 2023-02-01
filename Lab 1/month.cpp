/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Number of days in a given month

This program asks the user to input the year and the month (1-12) and prints the number of 
days in that month (taking into account leap years). You may not use switch case or arrays 
even if you know these language constructs.
*/

#include <iostream>
using namespace std;

int main(){
    string input;
    int month;
    int year;

    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;

    if (month <= 7 && month % 2 == 1 || month >= 8 && month % 2 == 0){
        cout << "31 days" << endl;
    } else if (month == 2){
        if (year % 4 != 0){
             cout << "28 days" << endl;
        } else if (year % 100 != 0){
             cout << "29 days" << endl;
        } else if (year % 400 != 0){
             cout << "28 days" << endl;
        } else {
             cout << "29 days" << endl;
        }
    } else {
        cout << "30 days" << endl;
    }
    // switch(month){
    //     case 1:
    //     case 3:
    //     case 5:
    //     case 7:
    //     case 8:
    //     case 10:
    //     case 12:
    //         cout << "31 days" << endl;
    //         break;
    //     case 4:
    //     case 6:
    //     case 9:
    //     case 11:
    //         cout << "30 days" << endl;
    //         break;
    //     case 2:
    // year is not divisible by 4 = common year
    // year is not divisible by 100 = leap year
    // year is not divisible by 400 = common year
    // else, it is a leap year
    //     if (year % 4 != 0){
    //          cout << "28 days";
    //     } else if (year % 100 != 0){
    //          cout << "29 days";
    //     } else if (year % 400 != 0){
    //          cout << "28 days";
    //     } else {
    //          cout << "29 days";
    //     }
    // }
}