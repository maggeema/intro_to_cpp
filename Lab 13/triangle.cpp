//Name: Maggie Ma
//Email: maggie.ma94@bcmail.cuny.edu
//Date: December 6, 2022
//This program asks the user for a number and a character other than space ...
//... and draws a triangle of that height and width using character graphics

#include <iostream>
using namespace std;

int main(){
    int num;
    char symbol;
    int counter = 1;

    cout << "Enter an int: ";
    cin >> num;
    cout << "Enter a symbol other than space: ";
    cin >> symbol;

    for(int i = 0; i < num; i++){
        int space = (num - counter);
        //print num - counter amount of whitespace
        for (int j = 0; j < space; j++){
            cout << " ";
        }

        //print symbol counter number of times
        for (int k = 0; k < counter; k++){
            cout << symbol;
        }
        //increase counter 
        cout << "\n";
        counter+=1;
    }
    return 0;
}