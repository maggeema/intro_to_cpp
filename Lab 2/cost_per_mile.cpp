/*
Author: Maggie Ma
Course: CSCI-136
Instructor: Genady Maryash
Assignment: E2.10 Program

This program asks the user to imput the number of gallons of gas in the tank, the fuel 
efficiency in miles per gallon, and the price of gas per gallon. Then print the cost per 
100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main(){
    double gas, fueleff, price, cost, distance;

    cout << "Enter the number of gallons of gas in tank: ";
    cin >> gas;

    cout << "Enter the fuel efficiency in miles per gallon: ";
    cin >> fueleff;

    cout << "Enter the price of gas per gallon: ";
    cin >> price;

    // if fueleff is miles per gallon, it is distance / gas, or distance is equal to 
    // fueleff * gas
    distance = fueleff * gas;
    // cost is equal to price * distance 
    cost = 100 / fueleff * price;

    cout << "The cost per 100 miles is $" << cost << endl;
    cout << "The distnace the car can go with the gas currently in tank is " << distance << " miles" << endl;

    return 0;
}