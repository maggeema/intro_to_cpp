//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 6, 2022
//This program asks the user for their current number of credit hours
//... and prints out the year of college that it corresponds with total hours

#include <iostream>
using namespace std;

int main(){
    int credit_hours;
    cout << "Enter number of credit hours taken: ";
    cin >> credit_hours;

    if (credit_hours < 28){
        cout << "freshman";
    } else if (credit_hours >= 28 && credit_hours < 61){
        cout << "sophomore";
    } else if (credit_hours >= 61 && credit_hours < 94){
        cout << "junior";
    } else {
        cout << "senior";
    }
    return 0;
}