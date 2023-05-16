#include "Ninja.hpp"
#include <stdexcept>
using namespace std;

namespace ariel
{
    Ninja::Ninja(string name, Point location, int HitPoints, int speed) : Charachter(name, location, HitPoints) // constructor
    {
        this->speed = speed;
    }
    void Ninja::move(Charachter *other)
    {
    }
    void Ninja::slash(Charachter *other)
    {
        // if (this->isAlive() && this->distance(other)<=1)
        // {
        // }
        // else
        // {
        //     throw std::runtime_error("can not slash,ninja is dead or the enemy is too far");
        // }
    }
    // return speed
    int Ninja::getSpeed()
    {
        return speed;
    }
}