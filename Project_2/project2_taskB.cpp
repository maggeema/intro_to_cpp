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

void readSongs(string filename){
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

string *getGenreSongs(string genre, int& genreCount){
    genreCount = 0; 
    string *genreSongs = new string[g_number_of_songs];
    for (int i = 0; i < g_number_of_songs; i++){
        if (g_genres[i] == genre){
            genreSongs[i] = g_song_names[i];
            genreCount++;
        }
    }
    return genreSongs;
}

string*getSongsFromDuration(int duration, int &durationsCount, int filter){
    durationsCount = 0;
    string *durationSongs = new string[g_number_of_songs];
    for (int i = 0; i < g_number_of_songs; i++){
        if (filter == 0 && g_song_durations[i] > duration){
            durationSongs[i] = g_song_names[i];
            durationsCount++;
        } else if (filter == 1 && g_song_durations[i] < duration){
            durationSongs[i] = g_song_names[i];
            durationsCount++;
        } else if (filter == 2 && g_song_durations[i] == duration){
            durationSongs[i] = g_song_names[i];
            durationsCount++;
        }
    }
    return durationSongs;
}

string *getUniqueArtists(int &uniqueCount){
    uniqueCount = 0; 
    string *unique = new string[g_number_of_songs];
    for (int i = 0; i < g_number_of_songs; i++){
        int samediff = 0;
        for (int k = 0; k < uniqueCount; k++){
            if (g_artist_names[i] == unique[k]){
                samediff++;
            } else if (samediff == 0){
                unique[i] = g_artist_names[i];
                uniqueCount++;
            }
        }
    }
    return unique;
}

string getFavoriteArtist(){
    if (g_number_of_songs == 0){
        return "NONE";
    }
    int uniqueCount = 0;
    string *unique = getUniqueArtists(uniqueCount);
    int counter[uniqueCount];
    for (int i = 0; i < uniqueCount; i++){
        counter[i] = 0;
    }
    for (int j = 0; j < uniqueCount; j++){
      for (int k = 0; k < uniqueCount; k++){
        if (unique[j] == g_artist_names[k]){
          counter[j]++;
        }
      }
    }
    int max = 0;
    
    for (int m = 0; m < uniqueCount; m++){
      if (counter[m] > max){
        max = counter[m];
      } else if (max == counter[m]){
        return unique[m];
      } 
    }
  return "NONE";
}

// int main(){
//   readSongs("classical_rep_playlist.txt");
//   for (int i = 0; i < g_number_of_songs; i++){
//     cout << g_song_names[i] << g_artist_names[i] << g_genres[i] << endl;
//   }
// }
