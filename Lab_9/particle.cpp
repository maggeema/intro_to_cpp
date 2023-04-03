// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Making your own class Particle

// Write a new program particle.cpp (you may copy anything you want from 3d-space.cpp 
// if need be).

// The program should declare a new class Particle, which

// stores position and velocity of the particle, and
// provides the following programming interface:
// // dynamically allocate memory for a particle and initialize it
// Particle* createParticle(double x, double y, double z, 
//                          double vx, double vy, double vz);
// // set its velocity to (vx, vy, vz)
// void setVelocity(Particle *p, double vx, double vy, double vz);
// // get its current position
// Coord3D getPosition(Particle *p);
// // update particle's position after elapsed time dt
// void move(Particle *p, double dt);
// // delete all memory allocated for the particle passed by pointer
// void deleteParticle(Particle *p);
// Implement these five functions. deleteParticle must delete all dynamically allocated memory 
// that is created by createParticle function.

// Here is a usage example of the class and its programming interface. It models accelerated 
// motion of a particle, which is done by making the velocity of the particle increase on 
// each time step.

#include <iostream>
using namespace std;

class Particle {
public:
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

class Coord3D {
public:
    double x;
    double y;
    double z;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz){
    Particle *result = new Particle;
    result->x = x;
    result->y = y;
    result->z = z;
    result->vx = vx;
    result->vy = vy;
    result->vz = vz;

    return result;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz){
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// get its current position
Coord3D getPosition(Particle *p){
    Coord3D result;
    result.x = p->x;
    result.y = p->y;
    result.z = p->z;
    return result;
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt){
    p->x = p->x + p->vx * dt;
    p->y = p->y + p->vy * dt;
    p->z = p->z + p->vz * dt;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p){
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}