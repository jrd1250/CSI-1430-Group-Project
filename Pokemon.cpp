/*  Author: Ethan Van Sligtenhorst
    Title: Implementation file for Pokemon class
 */

#include "Pokemon.h"
#include <string>
#include <time.h>
#include <cmath>

// Default constructor
Pokemon::Pokemon()
{
    index = -1;
}

// Constructor that receives index of Pokemon, with all attributes that come
// with that particular Pokemon, like hp, defense, type, and name
Pokemon::Pokemon(int health, int dmg, int dmgRng, int def, string pokeType,
          string pokeName, string h, string b, string a, string l)
{
    index = 1;
    hp = health;
    maxHP = health;
    damage = dmg;
    damageRange = dmgRng;
    defense = def;
    maxDefense = 2 * def;
    type = pokeType;
    name = pokeName;
    head = h;
    body = b;
    arm = a;
    leg = l;

}

// This function allows the HP of the Pokemon to be set
void Pokemon::setHP(int a)
{
    hp = a;
    maxHP = a;
}

// This function returns the HP of the Pokemon
int Pokemon::getHP()
{
    return hp;
}

void Pokemon::setDamage(int a)
{
  damage = a;
}

int Pokemon::getDamage()
{
  return damage;
}

void Pokemon::setDamageRange(int a)
{
  damageRange = a;
}

int Pokemon::getDamageRange()
{
  return damageRange;
}

// This function allows the defense of the Pokemon to be set
void Pokemon::setDefense(int a)
{
    defense = a;
    maxDefense = 2 * a;
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

int Pokemon::getMaxHP()
{
  return maxHP;
}

int Pokemon::getMaxDefense()
{
  return maxDefense;
}

// This function allows the type of the Pokemon to be set
void Pokemon::setType(std::string a)
{
    type = a;
}

// This function returns the type of the Pokemon
std::string Pokemon::getType()
{
    return type;
}

// This function allows the name of the Pokemon to be set
void Pokemon::setName(std::string a)
{
    name = a;
}

// This function returns the name of the Pokemon
std::string Pokemon::getName()
{
    return name;
}

void Pokemon::setHead(std::string h)
{
  head = h;
}

std::string Pokemon::getHead()
{
  return head;
}

void Pokemon::setBody(std::string b)
{
  body = b;
}

std::string Pokemon::getBody()
{
  return body;
}

void Pokemon::setArm(std::string a)
{
  arm = a;
}

std::string Pokemon::getArm()
{
  return arm;
}

void Pokemon::setLeg(std::string l)
{
  leg = l;
}

std::string Pokemon::getLeg()
{
  return leg;
}

void Pokemon::PokeDraw(int x, int y, SDL_Plotter& g, std::ifstream& in)
{
  modDraw((x + 2), (y - 12), g, in, head, type, false);
  modDraw(x, y, g, in, body, type, false);
  modDraw((x - 20), y, g, in, arm, type, true);
  modDraw((x + 16), y, g, in, arm, type, false);
  modDraw((x - 16), (y + 15), g, in, leg, type, true);
  modDraw((x + 16), (y + 15), g, in, leg, type, false);

  in.close();
}

// This function decreases the HP of the Pokemon
void Pokemon::harm(int a)
{
    if(a > 0)
      hp -= a;
}

// This function increases the HP of the Pokemon
void Pokemon::heal(int a)
{
    hp += a;
    if(hp > maxHP)
      hp = maxHP;
}

// This function decreases the defense of the Pokemon
void Pokemon::sapDefense(int a)
{
    defense -= a;
    if(defense < 0)
      defense = 0;
}

// This function increases the defense of the Pokemon
void Pokemon::buffDefense(int a)
{
    defense += a;
    if(defense > maxDefense)
      defense = maxDefense;
}
void Pokemon::attack1(Pokemon& target)
{
  int attackDamage = damage + (rand() % damageRange + 1);
  int advantage = int(ceil(double(index - target.index) / 81.0));
  srand(time(NULL));

  if(advantage == -1 || advantage == 3)
    attackDamage = int(double(attackDamage) * 1.25);
  else if(advantage == 0)
  {}
  else
    attackDamage = int(double(attackDamage) * 0.75);

  attackDamage -= target.defense;

  target.harm(attackDamage);
}

void Pokemon::attack2(Pokemon& target)
{
  int attackDamage;
  int advantage = int(ceil(double(index - target.index) / 81.0));
  srand(time(NULL));
  attackDamage = damage - ((rand() % damageRange + 1) / 2);

  if(advantage == -1 || advantage == 3)
    attackDamage = int(double(attackDamage) * 1.25);
  else if(advantage == 0)
  {}
  else
    attackDamage = int(double(attackDamage) * 0.75);

  target.harm(attackDamage);
  Pokemon::heal(attackDamage);
}

void Pokemon::attack3(Pokemon& target)
{
  target.sapDefense(3);
  Pokemon::buffDefense(3);
}

void Pokemon::CreateIndex(int typeI, int headI, int bodyI, int armI, int legI)
{
  index = 1 + (typeI * 81) + (headI * 27) + (bodyI * 9) + (armI * 3) + legI;
}

void writeData(std::ofstream& out);
void readData(std::ifstream& in);

