/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Task D: Hangman Game!

Implement the following functions to your .cpp file:

Add the given `word`, `definition`, `pos` to the end of the respective global-arrays. The 
word should not be added to the global-arrays if it already exists or if the array reached 
maximum capacity(`g_MAX_WORDS`). Update `g_word_count` if the word is successfully added

Replace the given `word`'s  definition and pos with the given `definition` and `pos` 
(by modifying global-arrays `g_definitions` and `g_pos`). The modification will fail if the 
word doesn't exist in the dictionary.

Remove the given `word`, `word`'s definition and `word`'s pos from the respective global-
arrays if the word exists. Update `g_word_count` if the word is successfully removed
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <stdlib.h>
using namespace std;


const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string filename;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename){
  string line, colon, word, pos, def;

    ifstream fin(filename);
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); 
    }

  while (getline(fin, line)){
        colon = line.substr(0, line.find(" :"));
        word = colon.substr(0, line.find(" "));
        pos = colon.substr(line.find(" ")+1, line.find("\n"));
        def = line.substr(line.find(":")+2, line.find("\n"));

        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        g_definitions[g_word_count] = def;

        g_word_count++;
  }
  fin.close();
}

int getIndex(string word){
    int index;
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            index = i;
            break;
        } else {
            index = -1;
        }
    }
    return index;
}

string getDefinition(string word){
    string def = "";
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            def = g_definitions[i];
            break;
        } else {
            def = "NOT_FOUND";
        }
    }
    return def;
}

string getPOS(string word){
    string pos = "";
    for (int i = 0; i < g_word_count; i++){
        if (g_words[i] == word){
            pos = g_pos[i];
            break;
        } else {
            pos = "NOT_FOUND";
        }
    }
    return pos;
}

int countPrefix(string prefix){
    int count = 0;
    bool matching;
    for (int i = 0; i < g_word_count; i++){
        for (int k = 0; k < prefix.length(); k++){
            if (g_words[i][k] == prefix[k]){
                matching = true;
            } else {
                matching = false;
                break;
            }
        }
        if (matching == true){
            count++;
        } 
    }
    return count;
}

bool addWord(string word, string definition, string pos){
    int index;

    if (getIndex(word) > -1){
        return false;
    } else if (g_word_count >= 1000){
        return false;
    } else {
        g_word_count++;
        index = g_word_count-1;
        g_words[index] = word;
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
}

bool editWord(string word, string definition, string pos){
    int index = getIndex(word);
    if (index == -1){
        return false;
    } else {
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
}

bool removeWord(string word){
    int index = getIndex(word);
    int front;
    if (index == -1){
        return false;
    } else {
        for (int i = 0; i < g_word_count; i++){
            front = i + 1;
            if (i >= index){
                g_words[i] = g_words[front];
                g_definitions[i] = g_definitions[front];
                g_pos[i] = g_pos[front];
            }       
        }
        g_word_count--;
        return true;
    }
}

string maskWord(string word){
    // leave an underscore for every letter in the word
    string blank = "";
    for (int i = 0; i < word.length(); i++){
        blank = blank + "_";
    }
    return blank;
}

int getTries(int difficulty){
    // if int is 0, it is easy mode; give 9 tries
    if (difficulty == 0){
        return 9;
    } else if (difficulty == 1){
    // if int is 1, it is normal mode; give 7 tries
        return 7;
    } else if (difficulty == 2){
    // if int is 2, it is hard mode; give 5 tries
        return 5;
    }
}

void printAttempts(int tries, int difficulty){
    string attempts = "";
    // find out how many tries you can get given the difficulty level
    int level = getTries(difficulty);
    for (int i = 0; i < level; i++){
        if (i < tries){
            attempts = attempts + "O";
        } else {
            attempts = attempts + "X";
        }
        // print out X for every try that is left based on given amount of tries
    }
    cout << attempts;
}

bool revealLetter(string word, char letter, string &current){
    bool correctletter = false;
    string revealed = "";

    // so long as we are checking each letter in the given word
    for (int i = 0; i < word.length(); i++){
        if (letter == current[i]){
            // add the letter to the masked/blank word as well
            revealed = revealed + letter;
            // if letter has already been checked prior, return false
            correctletter = false;
        } else if (letter == word[i]){
            // if the letter matches with the letters being checked, and it hasnt been checked
            // before, return true
            revealed = revealed + letter;
            correctletter = true;
        } else {
            // otherwise, itll return false and leave an _ for the space with unrevealed letter
            revealed = revealed + "_";
            correctletter = false;
        }
    }
    current = revealed;
    return correctletter;
}

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}


// int main(){
//     string word = "__n___";
//     cout << revealLetter("genady", 'e', word) << endl;
//     cout << word;
// }