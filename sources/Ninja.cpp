#include "Ninja.hpp"

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
    }
}