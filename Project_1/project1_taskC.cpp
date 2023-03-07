/*
Author: Maggie Ma
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Task C: Dictionary Admin Operations

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
        // if the word exists when you try to search for it and return false
        return false;
    } else if (g_word_count >= 1000){
        // if there is no room in the dictionary for the word, return false
        return false;
    } else {
        // if there is room and word doesnt already exist, add it to the list 
        g_word_count++;
        index = g_word_count-1;
        g_words[index] = word;
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
}

bool editWord(string word, string definition, string pos){
    // find the word and its index
    int index = getIndex(word);
    if (index == -1){
        // if word cannot be found in dictionary, return false
        return false;
    } else {
        // if the index of word is able to be found, change corresponding index in def array
        // and pos array with the new given definition and pos
        g_definitions[index] = definition;
        g_pos[index] = pos;
        return true;
    }
}

bool removeWord(string word){
    // find the word and its index
    int index = getIndex(word);
    int front;
    if (index == -1){
        // if word cannot be found in the list, return false
        return false;
    } else {
        for (int i = 0; i < g_word_count; i++){
            front = i + 1;
            if (i >= index){
                g_words[i] = g_words[front];
                g_definitions[i] = g_definitions[front];
                g_pos[i] = g_pos[front];
            }
        // g_words[g_word_count] = "";
        // g_definitions[g_word_count] = "";
        // g_pos[g_word_count] = "";            
        }
        g_word_count--;
        return true;
    }
}

// int main(){
//     cout << "Enter file name: ";
//     cin >> filename;
//     readWords(filename);

//     bool added = addWord("Intern", "confine (someone) as a prisoner, especially for political or military reasons", "verb");
//   cout << "ADD THE WORD INTERN: \n";
//   for (int i = 0; i < g_word_count; i++){
//     cout << g_words[i] << " ";
//   }
//   cout << "\n\n";
//   cout << "ADD THE WORD STUDENT: \n";
//     bool edited = editWord("Intern", "a student or trainee who works, sometimes without pay, at a trade or occupation in order to gain work experience", "noun");
//     bool addanother = addWord("Student", "a person who is studying at a school or college.", "noun");
//   for (int j = 0; j < g_word_count; j++){
//     cout << g_words[j] << " ";
//     cout << g_pos[j] << " ";
//     cout << g_definitions[j] << "\n";
//   }
//   cout << "\n\n" << "CURRENT WORD COUNT: " << g_word_count << "\n\n";
//   cout << "REMOVE THE WORD INTERN: \n";
//     bool removed = removeWord("Intern");
//   for (int k = 0; k < g_word_count; k++){
//     cout << g_words[k] << " ";
//     cout << g_pos[k] << " ";
//     cout << g_definitions[k] << "\n";
//   }
//   cout << "\n\nCURRENT WORD COUNT: " << g_word_count;
// }