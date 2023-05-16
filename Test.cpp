#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "sources/Team.hpp"
#include "sources/Point.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Check point class")
{
    Point point1(1.2, 5.5);
    Point point2(2.4, 10);

    // check initialization
    CHECK(point1.getX() == 1.2);
    CHECK(point1.getY() == 5.5);

    // check distance function
    CHECK(point1.distance(point2) == 4.65725);

    // check moveTowards function
    Point point3 = Point::moveTowards(point1, point2, 4);
    CHECK(point1.distance(point3) <= 4);
}

TEST_CASE("Test 2 - Check Charachter functions")
{
    Point a(10.0, 20.0);
    Point b(20.0, 20.0);
    Cowboy *Raz = new Cowboy("Raz", a);
    Cowboy *Maor = new Cowboy("Maor", b);
    CHECK(Raz->getName() == "Raz");
    CHECK(Raz->geHitPoints() == 110);
    CHECK(Raz->isAlive() == true);
    CHECK(((Raz->getLocation().getX() == a.getX()) && (Raz->getLocation().getY() == a.getY())));
    CHECK(Raz->distance(Maor) == 10);

    Raz->hit(25);
    CHECK(Raz->geHitPoints() == 85);
}
TEST_CASE("Test 3 - Check Cowboy initialization and functions")
{
    Point a(5, 10);
    Point b(7, 8);
    Cowboy *Raz = new Cowboy("Raz", a);
    Cowboy *Maor = new Cowboy("Maor", b);
    CHECK(Raz->geHitPoints() == 110);
    CHECK(Raz->getAmmo_amount() == 6);
    Raz->shoot(Maor);
    CHECK(Raz->getAmmo_amount() == 5);

    CHECK(Raz->hasboolets() == true);
    Raz->reload();
    CHECK(Raz->getAmmo_amount() == 6);
}
TEST_CASE("Test 4 - Cowboy check throws")
{
    Point a(5, 10);
    Point b(7, 8);
    Cowboy *Raz = new Cowboy("Raz", a);
    Cowboy *Maor = new Cowboy("Maor", b);

    for (int i = 0; i < 6; i++)
    {
        Raz->shoot(Maor);
    }
    CHECK(Raz->getAmmo_amount() == 0);
    CHECK_THROWS(Raz->shoot(Maor)); // no ammo left to shoot with
    Raz->reload();
    CHECK(Raz->getAmmo_amount() == 6);
    Raz->shoot(Maor);
    CHECK(Raz->getAmmo_amount() == 5);

    Raz->hit(110);
    CHECK(Raz->isAlive() == false); // cowboy is dead
    CHECK_THROWS(Raz->shoot(Maor)); // cowboy is dead he cant shoot
}

TEST_CASE("Test 5 - Check YoungNinja initialization")
{
    Point a(10, 20);
    YoungNinja *Raz = new YoungNinja("Raz", a);

    CHECK(Raz->geHitPoints() == 100);
    CHECK(Raz->getSpeed() == 14);
}

TEST_CASE("Test 6 - Check TrainedNinja initialization")
{
    Point a(10, 20);
    TrainedNinja *Raz = new TrainedNinja("Raz", a);

    CHECK(Raz->geHitPoints() == 120);
    CHECK(Raz->getSpeed() == 12);
}

TEST_CASE("Test 7 - Check OldNinja initialization")
{
    Point a(10, 20);
    OldNinja *Raz = new OldNinja("Raz", a);

    CHECK(Raz->geHitPoints() == 150);
    CHECK(Raz->getSpeed() == 8);
}

TEST_CASE("Test 8 - Ninja check throws")
{
    Point a(0, 0);
    Point b(0.5, 0);
    TrainedNinja *Raz = new TrainedNinja("Raz", a);
    TrainedNinja *Maor = new TrainedNinja("Maor", b);

    Raz->hit(120);
    CHECK_THROWS(Raz->slash(Maor)); // ninja is dead cannot attack
    Point c(5, 0);
    TrainedNinja *Ely = new TrainedNinja("Ely", c);
    CHECK_THROWS(Maor->slash(Ely)); // enemy is too far to attack
}

TEST_CASE("Test 9 - Check Team initialization and functions")
{
    Point a(0, 0);
    Point b(7, 8);
    TrainedNinja *Raz = new TrainedNinja("Raz", a);
    Cowboy *Maor = new Cowboy("Maor", b);

    Team team(Raz);
    team.add(new YoungNinja("Yogi", Point(64, 57)));
    CHECK(team.get_amount_of_members() == 2);
    team.add(Maor);

    CHECK(team.get_amount_of_members() == 3);
    CHECK(team.stillAlive() == 3);

    Maor->hit(110);
    CHECK(team.stillAlive() == 2);
}

TEST_CASE("Test 10 - Team check throws")
{
    Point a(0, 0);
    Point b(5, 5);
    TrainedNinja *pp1 = new TrainedNinja("pp1", a);
    Cowboy *pp2 = new Cowboy("pp2", b);
    Cowboy *pp3 = new Cowboy("pp3", a);
    TrainedNinja *pp4 = new TrainedNinja("pp4", b);
    Cowboy *pp5 = new Cowboy("pp5", a);
    TrainedNinja *pp6 = new TrainedNinja("pp6", b);
    OldNinja *pp7 = new OldNinja("pp7", a);
    OldNinja *pp8 = new OldNinja("pp8", b);
    YoungNinja *pp9 = new YoungNinja("pp9", a);
    YoungNinja *pp10 = new YoungNinja("pp10", b);
    OldNinja *pp11 = new OldNinja("pp11", b);

    Team team(pp1);
    team.add(pp2);
    team.add(pp3);
    team.add(pp4);
    team.add(pp5);
    team.add(pp6);
    team.add(pp7);
    team.add(pp8);
    team.add(pp9);
    team.add(pp10);
    CHECK(team.get_amount_of_members() == 10);
    CHECK_THROWS(team.add(pp11)); // cant have more than 10 memebers in a team

    for (int i = 0; i < 10; i++)
    {
        team.getGroup()[i]->hit(200);
    }
    CHECK(team.stillAlive() == 0);

    Team team_B(pp11);
    CHECK_THROWS(team.attack(&team_B)); // all players in the team are dead cant attack
}
