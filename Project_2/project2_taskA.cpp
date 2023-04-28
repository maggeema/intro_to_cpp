// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Dynamically Allocated Playlists

// Project 2 uses global arrays to store song information dynamically

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
#include <string>
using namespace std;

int g_curr_size = 2;

int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
string *g_genres = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];

// Replace the old global dynamically allocated arrays with new dynamically allocated arrays of 
// twice the size (`g_curr_size` * 2). Update `g_curr_size` accordingly. Make sure you copy the 
// contents of the older arrays. Do this for the following global-arrays: `g_song_names`, 
// `g_artist_names`, `g_song_durations`, `g_genres`

void allocateNew(){
    int size = g_curr_size*2;

    string *temp_songs = new string[size];
    string *temp_artists = new string[size];
    string *temp_genres = new string[size];
    int *temp_durations = new int[size];

    for (int i = 0; i < g_curr_size; i++){
        temp_songs[i] = g_song_names[i];
        temp_artists[i] = g_artist_names[i];
        temp_genres[i] = g_genres[i];
        temp_durations[i] = g_song_durations[i];
    }

    g_song_names = new string[size];
    g_artist_names = new string[size];
    g_genres = new string[size];
    g_song_durations = new int[size];

    for (int k = 0; k < g_curr_size; k++){
        g_song_names[k] = temp_songs[k];
        g_artist_names[k] = temp_artists[k];
        g_genres[k] = temp_genres[k];
        g_song_durations[k] = temp_durations[k];
    }

    g_curr_size = g_curr_size * 2;
    delete[] temp_songs;
    delete[] temp_artists;
    delete[] temp_genres;
    delete[] temp_durations;
}

// Reads the song, artists, song durations and genres into the global-arrays and set the value 
// of `g_number_of_songs` to the number of songs read. Call `allocateNew()` to allocate an array 
// of larger size if the dynamic arrays reach full capacity.

void readSongs(string filename){
    // string line;
    // int count = 0;

    // ifstream fin(filename);
    // if (fin.fail()) {
    //     cerr << "File cannot be opened for reading." << endl;
    //     exit(1); 
    // } 
    // while (getline(fin, line, '-')){
    //     if (count == 0){
    //         if (g_curr_size < g_number_of_songs){
    //             allocateNew();
    //         }
    //         g_artist_names[g_number_of_songs] = line.substr(line.find(":")+1); 
    //         int artist_length = g_artist_names[g_number_of_songs].length();
    //         int song_length = line.length() - artist_length;
    //         g_song_names[g_number_of_songs] = line.substr(0, song_length-1);

    //         count++;
    //     } else if (count == 1){
    //         if (g_curr_size < g_number_of_songs){
    //             allocateNew();
    //         }
    //     // set the words after the first dash to be genre
    //         g_genres[g_number_of_songs] = line;
    //         count++;
    //     } else if (count == 2){
    //         if (g_curr_size < g_number_of_songs){
    //             allocateNew();
    //         }
    //     // after last dash to space will be the the duration
    //         g_song_durations[g_number_of_songs] = std::stoi(line.substr(0, line.find(" mins")));
    //         g_number_of_songs++;

    //         // extract the words before the colon in the line 
    //         int subs = line.find("mins");
    //         g_artist_names[g_number_of_songs] = line.substr(line.find(":")+1); 
    //         int artist_length = g_artist_names[g_number_of_songs].length();
    //         int song_length = line.substr(subs+4).length() - artist_length;
    //         g_song_names[g_number_of_songs] = line.substr(subs+4, song_length-1);
    //         // extract the words after the colon but before the dash 
    //         count = 1;
    //     }

    //     // cout << count << "\t" << line << "\n-end of iteration-\n";
    //     // count++;
    //     // if (count == 3){
    //     //   count = 1;
    //     // }
        
    // }

    int posA, posB;
    string line;

    ifstream fin(filename);
    if (fin.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    while (getline(fin, line)){
        if (g_number_of_songs >= g_curr_size){
            allocateNew();
        }

        posA = 0;
        posB = line.find(':', posA);
        g_song_names[g_number_of_songs] = line.substr(posA, (posB - posA));
        posA = posB + 1;
        posB = line.find('-', posA);
        g_artist_names[g_number_of_songs] = line.substr(posA, (posB-posA));
        posA = posB + 1;
        posB = line.find('-', posA);
        g_genres[g_number_of_songs] = line.substr(posA, (posB - posA));
        posA = posB + 1;
        posB = line.find(' ', posA);
        g_song_durations[g_number_of_songs] = stoi(line.substr(posA, (posB - posA)));
        g_number_of_songs++;
    }
    fin.close();
}

int main() {
  string filename;
  cout << "Enter file name: ";
  getline(cin, filename);
  readSongs(filename);

//   cout << g_number_of_songs << endl;
//   cout << g_curr_size << endl;

  for (int i = 0; i < g_number_of_songs; i++) {
    cout << g_song_names[i] << " " << g_artist_names[i] << " " << g_genres[i] << " " << g_song_durations[i] << endl;
  }
}