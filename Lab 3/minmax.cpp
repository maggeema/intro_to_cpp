/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Minimum and maximum storage in 2018

This program finds the minimum and maximum storage in East basin in 2018.
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
    string junk, date;
    double eastSt, eastEl, westSt, westEl, min;
    double max = 0.0;
    // read one line from the file and save it to the string junk
    getline(fin, junk);

    // the condition of the while loop evaluates directly as a boolean value
    // (so long as there are values to read, it will keep corresponding lines to each 
    // column label; it will return false when there are no more lines to read)
    // the side effect is that it will assign each row to a corresponding column value
    while (fin >> date >> eastSt >> westSt >> westEl){

        // this loop reads the file line by line 
        // extracting 5 values on each iteration 

        // skips to the end of line, ignorring the remaining columns
        fin.ignore(INT_MAX, '\n');

        if (eastSt > max){
            if (max == 0.0){
                min = eastSt;
            }
            max = eastSt;
        } else if (eastSt < min){
            min = eastSt;
        }
    }

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;  
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;  
    fin.close();
}