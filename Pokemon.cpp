/*  Author: Ethan Van Sligtenhorst
    Title: Implementation file for Pokemon class
 */

using namespace std;

#include "Pokemon.h"
#include <string>

// Default constructor
Pokemon::Pokemon()

// Constructor that receives index of Pokemon, with all attributes that come
// with that particular Pokemon, like hp, defense, type, and name
Pokemon::Pokemon(const int in, int health, int def, string pokeType, string pokeName)
{
    index = in;
    hp = health;
    defense = def;
    type = pokeType;
    name = pokeName;

}

// This function allows the HP of the Pokemon to be set
void Pokemon::setHP(int a)
{
    hp = a;
}

// This function returns the HP of the Pokemon
int Pokemon::getHP()
{
    return hp;
}

// This function allows the defense of the Pokemon to be set
void Pokemon::setDefense(int a)
{
    defense = a;
}

// This function returns the defense of the Pokemon
int Pokemon::getDefense()
{
    return defense;
}

// This function returns the index of the Pokemon.
int Pokemon::getIndex()
{
    return index;
}

// This function allows the type of the Pokemon to be set
void Pokemon::setType(string a)
{
    type = a;
}

// This function returns the type of the Pokemon
string Pokemon::getType()
{
    return type;
}

// This function allows the name of the Pokemon to be set
void Pokemon::setName(string a)
{
    name = a;
}

// This function returns the name of the Pokemon
string Pokemon::getName()
{
    return name;
}

// This function decreases the HP of the Pokemon
void Pokemon::damage(int a)
{
    hp -= a;
}

// This function increases the HP of the Pokemon
void Pokemon::heal(int a)
{
    hp += a;
}

// This function decreases the defense of the Pokemon
void Pokemon::sapDefense(int a)
{
    defense -= a;
}

// This function increases the defense of the Pokemon
void Pokemon::buffDefense(int a)
{
    defense += a;
}
void attack1(Pokemon target);
void attack2(Pokemon target);
void attack3(Pokemon target);

void writeData(ofstream& out);
void readData(ifstream& in);

