/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Comparing elevations

This program asks the user to input two dates (the beginning and the end of the interval). 
The program should check each day in the interval and report which basin had higher elevation 
on that day by printing “East” or “West”, or print “Equal” if both basins are at the same
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
    string junk, date, start, end, day;
    double eastSt, eastEl, westSt, westEl;
    // read one line from the file and save it to the string junk
        getline(fin, junk);

    cout << "Enter starting date: " << endl;
    cin >> start;
    string start_month = start.substr(0, 2);
    string start_day = start.substr(3, 2);
    cout << "Enter ending date: " << endl;
    cin >> end;
    string end_month = end.substr(0, 2);
    string end_day = end.substr(3, 2);
    cout << "\n\n";

    // the condition of the while loop evaluates directly as a boolean value
    // (so long as there are values to read, it will keep corresponding lines to each 
    // column label; it will return false when there are no more lines to read)
    // the side effect is that it will assign each row to a corresponding column value
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){

        // this loop reads the file line by line 
        // extracting 5 values on each iteration 

        // skips to the end of line, ignorring the remaining columns
        fin.ignore(INT_MAX, '\n');


        // extract the months, days and years. so long as the month int and day int are 
        // currently less than the end month and day, keep reading the data and comparing
        // i don't have to compare years because our file only has data for the year 2018
        string month = date.substr(0, 2);
        string day = date.substr(3, 2);

        // if the values for month and day match up, tell the computer to start comparing
        if (month == start_month && day == start_day){
            if (eastEl < westEl){
                cout << date << " " << "West" << endl;
                if (month == end_month && day == end_day){
                    break;
                }
            } else if (eastEl > westEl){
                cout << date << " " << "East" << endl;
                if (month == end_month && day == end_day){
                    break;
                }
            } 

            while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
                fin.ignore(INT_MAX, '\n');
                month = date.substr(0, 2);
                day = date.substr(3, 2);

                if (month == end_month && day == end_day){
                    if (eastEl < westEl){
                        cout << date << " " << "West" << endl;
                    } else if (eastEl > westEl){
                        cout << date << " " << "East" << endl;
                    }
                    break;
                } else {
                    if (eastEl < westEl){
                        cout << date << " " << "West" << endl;
                    } else if (eastEl > westEl){
                        cout << date << " " << "East" << endl;
                    }
                }
            }
        } 
    }

    fin.close();
}