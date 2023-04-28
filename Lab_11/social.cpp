// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Class profile

// This program  implements the class Profile that can store the info about a user of the 
// network.

// It has two private properties of type string: displayname and username.

// The public interface consists of two constructors initializing the private variables and 
// three functions:
// getUsername returns the username.
// getFullName returns the string in the format "displayname (@username)".
// setDisplayname allows to change the displayname property. (Username is a unique user 
// identifier and cannot change, while displayname can be any string and can be modified, so the class provides a mechanism for updating it.)

#include <iostream>
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

// A usage example
// (When submitting your code, please use this exact main function):

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
