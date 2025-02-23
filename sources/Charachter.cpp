#include "Charachter.hpp"
using namespace std;
namespace ariel
{
    Charachter::Charachter(string name, Point location, int HitPoints)
    {
        this->location = location;
        this->name = name;
        this->HitPoints = HitPoints;
    }
    Charachter::Charachter()
    {
    }

    bool Charachter::isAlive() // return true if hitpoint > 0
    {
        if (HitPoints > 0)
            return true;
        else
            return false;
    }
    double Charachter::distance(Charachter *other) // return the distance bettwen the Charachters
    {
        return location.distance(other->getLocation());
    }
    void Charachter::hit(int amount) // substract amount from hitpoints
    {
        HitPoints -= amount;
    }
    string Charachter::getName() // return the name of the Charachter
    {
        return name;
    }
    int Charachter::geHitPoints() // return the hp of a Charachter
    {
        return HitPoints;
    }
    Point Charachter::getLocation() // return the location of a Charachter
    {
        return location;
    }
    string Charachter::print() // prints name,hp,location (look on git)
    {
        return "nothing";
    }
}