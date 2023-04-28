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

class Song{
    public:
        string name;
        string artist;
        int duration;
        string genre;
};

int g_capacity = 2;
int g_size = 0;

Song *g_songs = new Song[g_capacity];

// create a new "void allocateNew()"
void allocateNew(){
    Song *temp_songs = new Song[g_capacity*2];

    for (int i = 0; i < g_capacity; i++){
        temp_songs[i].name = g_songs[i].name;
        temp_songs[i].artist = g_songs[i].artist;
        temp_songs[i].genre = g_songs[i].genre;
        temp_songs[i].duration = g_songs[i].duration;
    }

    g_songs = new Song[g_capacity*2];
    for (int j = 0; j < g_capacity; j++){
        g_songs[j].name = temp_songs[j].name;
        g_songs[j].artist = temp_songs[j].artist;
        g_songs[j].genre = temp_songs[j].genre;
        g_songs[j].duration = temp_songs[j].duration;
    }

    g_capacity = g_capacity*2;
    delete[] temp_songs;
}

// create a new "readSongs(string filename)"
void readSongs(string filename){
    string line;
    int posA, posB;

    ifstream fin(filename);
    if (fin.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    while (getline(fin, line)){
        if (g_size >= g_capacity){
            allocateNew();
        }

        posA = 0;
        posB = line.find(':', posA);
        g_songs[g_size].name = line.substr(posA, (posB - posA));
        posA = posB + 1;
        posB = line.find('-', posA);
        g_songs[g_size].artist = line.substr(posA, (posB-posA));
        posA = posB + 1;
        posB = line.find('-', posA);
        g_songs[g_size].genre = line.substr(posA, (posB - posA));
        posA = posB + 1;
        posB = line.find(' ', posA);
        g_songs[g_size].duration = stoi(line.substr(posA, (posB - posA)));
        g_size++;        
    }
    fin.close();
}

Song *getSongsFromDuration(int duration, int &durationsCount, int filter){
    durationsCount = 0;
    Song *durationSongs = new Song[g_size];
    for (int i = 0; i < g_size; i++){
        if (filter == 0 && g_songs[i].duration > duration){
            durationSongs[i] = g_songs[i];
            durationsCount++;
        } else if (filter == 1 && g_songs[i].duration < duration){
            durationSongs[i] = g_songs[i];
            durationsCount++;
        } else if (filter == 2 && g_songs[i].duration == duration){
            durationSongs[i] = g_songs[i];
            durationsCount++;
        }
    }
    return durationSongs;
}

Song *getGenreSongs(string genre, int& genreCount){
    genreCount = 0; 
    Song *genreSongs = new Song[g_size];
    for (int i = 0; i < g_size; i++){
        if (g_songs[i].genre == genre){
            genreSongs[i] = g_songs[i];
            genreCount++;
        }
    }
    return genreSongs;
}


string *getUniqueArtists(int &uniqueCount){
    string *artist = new string[g_size];
    int artistCount;
    for (int i = 0; i < g_size; i++){
        artistCount = 0;
        for (int k = 0; k < g_size; k++){
            if (g_songs[i].artist == artist[k]){
                artistCount++;
            } 
        }
        if (artistCount == 0){
                artist[i] = g_songs[i].artist;
        }
    }
    return artist;
}

string getFavoriteArtist(){
    if (g_size == 0){
        return "NONE";
    }

    int max = 0;
    int count = 0;
    string fav_artist;
    string *uniqueArtists = new string[g_size];
    for (int i = 0; i < g_size; i++){
        for (int k = 0; k < g_size; k++){
            if (g_songs[k].artist == uniqueArtists[i]){
                count++;
            }
        }
        if (count > max){
            max = count;
            fav_artist = g_songs[i].artist;
        }
    }
    return fav_artist;
}

int main(){
    string filename;
    cout << "Enter file name: ";
    getline(cin, filename);
    readSongs(filename);
    // readSongs("classical_rep_playlist.txt");
    for (int i = 0; i < g_size; i++){
        cout << g_songs[i].name << "\n" << g_songs[i].artist << "\n" << g_songs[i].genre << "\n" << g_songs[i].duration << "\n\n END OF ITERATION \n\n";
    }

}