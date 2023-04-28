// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Class Network: Following others

// Write a new program social3.cpp, which is an improved version of the previous program.

// The class Network should be changed to keep the friendship (following) relation between the 
// users.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }

    Profile(){
        username = "";
        displayname = "";
    }

    string getUsername() {
        return username;
    }

    string getFullName() {
        string result = "";
        result = displayname + "(@" + username + ")";
        return result;
    }

    void setDisplayName(string dspn){
        displayname = dspn;
    }
};


class Network {
private:
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];   
    // friendship matrix; following[id1][id2] == true when id1 is following id2  
    bool following[MAX_USERS][MAX_USERS];    // new:
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();                         // new
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
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}

bool validName(string s){
    bool valid;
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

bool Network::addUser(string usrn, string dspn){
    bool complete;

    if (numUsers < MAX_USERS && findID(usrn) == -1 && validName(usrn) == true){
        Profile newUser(usrn, dspn);
        profiles[numUsers] = newUser;
        numUsers++;
        complete = true;
    } else {
        complete = false;
    }
    return complete;
}

// make usrn1 follow usrn2 (if both useranmes are in the network)
// return true if success (if both useranmes exist), otherwise return false
bool Network::follow(string usrn1, string usrn2){
    if (findID(usrn1) > -1 && findID(usrn2) > -1){
        for (int i = 0; i < numUsers; i++){
            if (profiles[i].getUsername() == usrn1){
                for (int k = 0; k < numUsers; k++){
                    if (profiles[k].getUsername() == usrn2){
                        following[i][k] = true;
                    }
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

// print dot file (graphical representation of the network)
void Network::printDot(){
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++){
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }
    for (int j = 0; j < MAX_USERS; j++){
        for (int k = 0; k < MAX_USERS; k++){
            string usrn1 = profiles[j].getUsername();
            string usrn2 = profiles[k].getUsername();
            if (following[j][k] == true){
                cout << "  \"@" << usrn1 << "\" -> \"@" << usrn2 << "\"" << endl; 
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}