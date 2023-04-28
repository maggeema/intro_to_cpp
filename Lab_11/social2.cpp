// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Class Network | Adding users

// The three main functionalities of the class Network are: 1) adding new users to the network,
// 2) following, and 3) posting messages. We are going to develop them in these three tasks.

// Write a program social2.cpp, implementing the first version of the class Network (feel free to
//  copy your class Profile and anything else from the previous program).

// This first version of the class should be able to add new users and store their profiles, for
// that, the class has the following private variables:

// an array of registered user profiles,
// an integer numUsers, which stores the number of registered users.
// the size of the profiles array is defined as MAX_USERS=20, we cannot sign up more than this 
// number of users.
// The index in the array profile is the profile ID. As you keep adding new users, they are 
// receiving ID = 0, 1, 2, and so on. To look up the ID of a specific profile by its username, 
// we have a private function findID(usrn), it should return the ID of the user with that 
// username, or -1 if the user is not found in the profiles array.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile(){
        username = "";
        displayname = "";
    }

    // Return username
    string getUsername() {
        return username;
    }

    // Return name in the format: "displayname (@username)"
    string getFullName() {
        string result = "";
        result = displayname + "(@" + username + ")";
        return result;
    }

    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }
};


class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array: mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);

public:
    Network();
    bool addUser(string usrn, string dspn);

};

int Network::findID (string usrn){
    int index;
    for (int i = 0; i <= numUsers; i++){
        if (profiles[i].getUsername() == usrn){
            index = i;
            break;
        } else {
            index = -1;
        }
    }
    return index;
}

Network::Network(){
    numUsers = 0;
}

// checks to see if a username is valid (no spaces, no symbols) 
bool validName(string s){
    bool valid;
    // check if a username is empty
    if (s.length() < 0){
        valid = false;
    } else{
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ' || !isalnum(s[i])){
                valid = false;
                break;
            } else {
                valid = true;
            }
        }
    }
    return valid;
}

// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
bool Network::addUser(string usrn, string dspn){
    bool complete;

    if (numUsers < MAX_USERS && findID(usrn) == -1 && validName(usrn) == true){
    // checks if array profiles is full, if username is taken, or if username is valid
        Profile newUser(usrn, dspn);
        profiles[numUsers] = newUser;
        numUsers++;
        complete = true;
    } else {
        complete = false;
    }
    return complete;
}

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}