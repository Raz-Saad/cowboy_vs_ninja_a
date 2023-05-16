#include "Team.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    Team::Team(Charachter *leader) // constructor ,getting a pointer of a leader of the team
    {
        this->leader = leader;
        add(leader);
    }

    Team::~Team() // destructor
    {
        for (int i = 0; i < amount_of_members; i++)
        {
            if (group[i] != NULL)
            {
                delete group[i];
                group[i] = NULL;
            }
        }
        leader = NULL;
    }

    void Team::add(Charachter *charachter) // adds a Charachter to the team
    {
        if (amount_of_members < 10)
            group[amount_of_members++] = charachter;
        else
            throw std::runtime_error("can not add more than 10 charachter to a team");
    }
    void Team::attack(Team *other) // attacks other team
    {
        if (this->stillAlive() == 0)
        {
            throw std::runtime_error("can not attack all the members in the group are dead");
        }
        else
        {
        }
    }

    int Team::stillAlive() // returns the amount of live Charachter in the team
    {
        // int alive_counter = 0; // counts how many charachters in the team are alive
        // if (amount_of_members > 0)
        // {
        //     for (int i = 0; i < amount_of_members; i++)
        //     {
        //         if (group[i]->isAlive())
        //             alive_counter++;
        //     }
        // }
        // else
        // {
        //     throw std::runtime_error("there is no charachter in this team yet");
        // }

        // return alive_counter;
        return 0;
    }
    string Team::print()
    {
        return "nothing team";
    }
    int Team::get_amount_of_members() // returns how many members are in the group at the moment
    {
        return amount_of_members;
    }
    Charachter **Team::getGroup()
    {
        return group;
    }
}