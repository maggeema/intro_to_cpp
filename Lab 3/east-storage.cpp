/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: East Basin Storage

This program asks the user to input a string representing the date (in MM/DD/YYYY) and prints
out the East basin storage on that day.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    // if this is true or false (boolean value), then...
    if (fin.fail()) {
        // cerr is similar to cout, but prints out an error instead of just any string
        cerr << "File cannot be opened for reading." << endl;
        // exit if failed to open the file
        exit(1); 
    }

    // new string variable
    string junk, date, date_input;
    double eastSt, eastEl, westSt, westEl;
    // read one line from the file and save it to the string junk
    getline(fin, junk);


    cout << "Enter date: ";
    cin >> date_input;

    // the condition of the while loop evaluates directly as a boolean value
    // (so long as there are values to read, it will keep corresponding lines to each 
    // column label; it will return false when there are no more lines to read)
    // the side effect is that it will assign each row to a corresponding column value
    while (fin >> date >> eastSt >> westSt >> westEl){

        // this loop reads the file line by line 
        // extracting 5 values on each iteration 

        // skips to the end of line, ignorring the remaining columns
        fin.ignore(INT_MAX, '\n');

        if (date == date_input){
          cout << "East basin storage: " << eastSt << " billion gallons";  
        }
    }

    fin.close();
}