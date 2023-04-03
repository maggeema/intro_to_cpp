// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Velocity and moving objects

// Let's consider an object moving in 3D space. We already know how to describe its position. 
// (We will be assuming metric system, thus distances will be implicitly measured in meters and 
// time in seconds.)

// The object's velocity can be represented in the same 3D coordinate system as its displacement 
// per second in the coordinates x, y, and z:

// Coord3D vel = {5, -3, 1}; // x, y, z components of the velocity
// When moving at constant velocity vel , the object's new position after the elapsed time dt 
// can be computed as

// x' = x + vel.x * dt;

// y' = y + vel.x * dt;

// z' = z + vel.x * dt;
// Let's implement it. In the same program, write a function

// void move(Coord3D *ppos, Coord3D *pvel, double dt);
// which gets the position and the velocity of an object and has to compute object's new 
// coordinates after the time 

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
    public: 
        double x;
        double y;
        double z;
};

double length(Coord3D *p){
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}

Coord3D *fartherFromOrigin(Coord3D*p1, Coord3D *p2){
  Coord3D *p;
    if (length(p1) > length(p2)){
        p = p1;
    } else if (length(p1) < length(p2)){
        p = p2;
    }
  return p;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}

int main() {
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
}