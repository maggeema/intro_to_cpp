// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 10

// This program defined a function, formatDate, that returns the formatted string given
// a pointer to a date object: string formatDate(Date *d);

// Example: 
// int main() {
//     Date midterm1 = Date{10, 17, 2022}; // output: Oct 17, 2022
//     cout << formatDate(&midterm) << endl;

//     Date christmas = Date (12, 25, 2022); // output Dec 25, 2022
//     cout << formatDate(&christmas) << endl;
// }

#include <iostream>
using namespace std;

class Date {
    public:
        int month;
        int day;
        int year;
};

string formatDate(Date *d){
    string result = "";
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < sizeof(months); i++){
        if (d->month == i+1){
            result += months[i];
            break;
        }
    }
    result = result + " " + to_string(d->day) + ", " + to_string(d->year);
    return result;
}

// int main() {
//     Date midterm1 = Date{10, 17, 2022}; // output: Oct 17, 2022
//     cout << formatDate(&midterm1) << endl;

//     Date christmas = Date{12, 25, 2022}; // output Dec 25, 2022
//     cout << formatDate(&christmas) << endl;
// }