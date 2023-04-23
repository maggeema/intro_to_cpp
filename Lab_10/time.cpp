// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Simple functions for time

// Create a new program time.cpp. (Copy the class Time declaration in your program, it should 
// be placed before main() function.)

// Implement two new functions:

// int minutesSinceMidnight(Time time);
// int minutesUntil(Time earlier, Time later);
// The first function should return the number of minutes from 0:00AM until time.

// The second function should receive two Time arguments earlier and later and report how 
// many minutes separate the two moments. For example, when passing 10:30AM and 1:40PM:

// minutesUntil( {10, 30}, {13, 40} )  
// // ==> should return 190 minutes
// (A caveat: If the earlier moment of time happens to be after the later moment of time, 
// report a negative number of minutes. Although it's not difficult to achieve this if your 
// implementation for the first function is correct.)

#include <iostream>
using namespace std;

class Time { 
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time){
    int minutes;
    minutes = (time.h * 60) + time.m;
    return minutes;
}

int minutesUntil(Time earlier, Time later){
    int minutes;
    minutes = (later.h - earlier.h) * 60;
    minutes = minutes + (later.m - earlier.m);
    return minutes;
}

