// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Overlapping time slots?

// Add a new function
// bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
// The function should return true if the two time slots overlap, otherwise return false. 
// (Take into account the starting times of the time slots and the duration of the scheduled 
// movies.)

// Modify main function to test your code.
// Hint: You may use minutesUntil to check which time slot is earlier, then find the how long 
// is the interval between their starting times. They overlap if the movie duration is greater 
// than the interval between the time slots' starting times. Alternatively, converting times 
// into minutes since midnight can be a good idea as well.

// (By the way, if you want to be accurate, if one movie starts at 10:00 and lasts 90 minutes 
// until 11:30, then it does not overlap with a movie that starts exactly at 11:30. However, 
// they would overlap if the latter movie started one minute earlier, at 11:29.)

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

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    bool overlap = false;
    int interval;
    if (ts1.startTime.h < ts2.startTime.h){
        interval = minutesUntil(ts1.startTime, ts2.startTime);
        if (interval <= ts1.movie.duration){
            overlap = true;
        }
    } else if (ts1.startTime.h > ts2.startTime.h){
        interval = minutesUntil(ts2.startTime, ts1.startTime);
        if (interval <= ts2.movie.duration){
            overlap = true;
        }
    } else {
        overlap = true;
    }

    return overlap;
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
    TimeSlot newShowing = scheduleAfter(showings[3], anotherRomance);

    if (timeOverlap(showings[4], newShowing) == true){
        cout << "You cannot watch both these movies due to overlapping showtimes." << endl;
    }
}