// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Scheduling X after Y?

// Add a new function
// TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
// The function should produce and return a new TimeSlot for the movie nextMovie, scheduled 
// immediately after the time slot ts.
// For example, if the movie scheduled in ts starts at 14:10 and lasts 120 minutes, then the 
// time slot for the next movie should start at exactly 16:10.


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
        case ACTION: 
            g = "ACTION"; 
            break;
        case COMEDY: 
            g = "COMEDY"; 
            break;
        case DRAMA: 
            g = "DRAMA";  
            break;
        case ROMANCE: 
            g = "ROMANCE"; 
            break;
        case THRILLER: 
            g = "THRILLER"; 
            break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    cout << " [starts at "<<  ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endTime.h << ":"<<  endTime.m << "]" << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot after;
    after.startTime = addMinutes(ts.startTime, ts.movie.duration);
    after.movie = nextMovie;
    return after;
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

    Movie anotherRomance;
    anotherRomance.title = "Howl's Moving Castle";
    anotherRomance.genre = ROMANCE;
    anotherRomance.duration = 119;  
    scheduleAfter(showings[3], anotherRomance);
}