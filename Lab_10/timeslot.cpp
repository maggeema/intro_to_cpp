// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Time slot ending time and print time slot

// In the same program time.cpp, implement your own printing function 
// printTimeSlot(TimeSlot ts). It should make output in the following format:

// Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
// The ending time is the starting time + movie duration.

// Write main function that defines at least five time slots

// morning, daytime, and evening defined previously,
// plus add a couple of your own time slots with some of your favorite movies (their 
// duration time can be found in IMDB).
// The program output should look like:

// $ ./time
// Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
// Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]
// Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]
//  -- your time slot #1 --
//  -- your time slot #2 --
//  --        ...        --
// When defining your own time slots, please make sure they end before midnight, 23:59, so 
// the ending time does not show the next day.

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class Time { 
public:
    int h;
    int m;
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
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

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    cout << " [starts at "<<  ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endTime.h << ":"<<  endTime.m << "]" << endl;
}

int main(){
    Movie action;
    action.title = "Paprika";
    action.genre = ACTION;
    action.duration = 90;

    Movie comedy;
    comedy.title = "Ponyo";
    comedy.genre = COMEDY;
    comedy.duration = 111;

    Movie drama;
    drama.title = "Your Name";
    drama.genre = DRAMA;
    drama.duration = 112;

    Movie romance;
    romance.title = "The Wind Rises";
    romance.genre = ROMANCE;
    romance.duration = 140;

    Movie thriller;
    thriller.title = "Perfect Blue";
    thriller.genre = THRILLER;
    thriller.duration = 81;

    TimeSlot showings[5] = {{thriller, {18, 30}}, {romance, {15, 10}}, {drama, {21, 15}}, {comedy, {9, 45}}, {action, {12, 20}}};

    for (int i = 0; i < sizeof(showings); i++){
        if (showings[i].startTime.h < 12){
            // morning
            printTimeSlot(showings[i]);
        } else if (showings[i].startTime.h >= 12 && showings[i].startTime.h < 15){
            // earlyAfternoon 
            printTimeSlot(showings[i]);
        } else if (showings[i].startTime.h >= 15 && showings[i].startTime.h < 18){
            // lateAfternoon 
            printTimeSlot(showings[i]);
        } else if (showings[i].startTime.h >= 18 && showings[i].startTime.h < 21){
            // evening
            printTimeSlot(showings[i]);
        } else if (showings[i].startTime.h >= 21 && showings[i].startTime.h <= 23){
            // night
            printTimeSlot(showings[i]);
        } 
    }
}