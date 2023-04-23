// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Simple functions for time

// Add a new function to your program time.cpp:

// Time addMinutes(Time time0, int min);
// The function should create and return a new moment of time that is min minutes after time0. 
// Example:

// addMinutes({8, 10}, 75)
// // ==> should return {9, 25}
// (We will not test how your function behaves if the new returned time will be on the next 
// day, feel free to assume that it will remain withing the same day, <= 23:59.)

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

Time addMinutes(Time time0, int min){
    time0.m += min;
    while (time0.m >= 60){
        time0.h++;
        time0.m -= 60;
    }

    return time0;
}