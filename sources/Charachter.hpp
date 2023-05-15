#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel
{
    class Charachter
    {
        Point location;
        int HitPoints;
        string name;

    public:
        Charachter();
        Charachter(string name, Point location, int HitPoints); // constructor
        bool isAlive();                                         // return true if hitpoint > 0
        double distance(Charachter *other);                     // return the distance bettwen the Charachters
        void hit(int amount);                                   // substract amount from hitpoints
        string getName();                                       // return the name of the Charachter
        int geHitPoints();                                      // return the hp of a Charachter
        Point getLocation();                                    // return the location of a Charachter
        virtual string print();                                           // prints name,hp,location (look on git)
    };

}