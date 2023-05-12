// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Quiz 12

// define a class, Customer, with a private string data memebers name and unique id

#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string name;
    string unique_id;
public:
    Customer();

    Customer(string name, string unique_id);
    string get_name();
    string get_unique_id();
    void set_name(string name);
    void set_unique_id(string uniqueId);
};

Customer::Customer() {}

Customer::Customer(string name, string unique_id) : name(name), unique_id(unique_id) {}

string Customer::get_name() {
    return name;
}

string Customer::get_unique_id() {
    return unique_id;
}

void Customer::set_name(string name) {
    this->name = name;
}

void Customer::set_unique_id(string uniqueId) {
    unique_id = uniqueId;
}