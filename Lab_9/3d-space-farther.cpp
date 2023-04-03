// Author: Maggie Ma
// Course: CSCI-135
// Instructor: Genady Maryash
// Assignment: Farther from the origin?

// In the same file 3d-space.cpp, add a function

// Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
// Which receives the coordinates of two points (passed as pointers), and returns the pointer of 
// the point that is farther away from the origin.

// A usage example:

// int main() {
//     Coord3D pointP = {10, 20, 30};
//     Coord3D pointQ = {-20, 21, -22};

//     cout << "Address of P: " << &pointP << endl;
//     cout << "Address of Q: " << &pointQ << endl << endl;

//     Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
//     cout << "ans = " << ans << endl; // So which point is farther?
// }
// When testing your code, look at the reported address of the answer ans and determine whether 
// it reports P or Q. You can use a calculator or WolframAlpha to check the numbers. Try other 
// coordinates of points P and Q to confirm that the program works.

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

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?
}