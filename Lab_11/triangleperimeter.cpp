// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Dynamically Allocated Playlists

// Define a structure Triangle that contains three Point members. Write a function that 
// computes the perimeter() of a t. Write a program that reads the coordinates
// of the points, calls your function, and displays the result

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};

double distance(Point x, Point y) {
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
}

double perimeter(Triangle t) {
    return distance(t.p1, t.p2) + distance(t.p2, t.p3) +
           distance(t.p1, t.p3);
}

int main() {
    Point p1, p2, p3;
    cout << "Enter x of point 1: ";
    cin >> p1.x;
    cout << "Enter y of point1: ";
    cin >> p1.y;
    cout << "Enter x of point 2: ";
    cin >> p2.x;
    cout << "Enter y of point 2: ";
    cin >> p2.y;
    cout << "Enter x of point 3: ";
    cin >> p3.x;
    cout << "Enter y of point 3: ";
    cin >> p3.y;

    Triangle t;
    t.p1 = p1;
    t.p2 = p2;
    t.p3 = p3;

    cout << "Perimeter is " << perimeter(t) << endl;
    return 0;
}