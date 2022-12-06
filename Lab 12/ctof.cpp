//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: November 30, 2022
//This program converts celsius to farenheit

#include <iostream>

using namespace std;

int main(){
    double celsius;
    double farenheit;

    cout << "Enter degrees in celsius: ";
    cin >> celsius;
    farenheit = 9.0 / 5 * celsius + 32;

    cout << farenheit;
    return 0;
}