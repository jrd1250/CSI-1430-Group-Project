/*
Author: J.R. Diehl; edited by Ethan Van Sligtenhorst
Title: Header for Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <fstream>
#include "Plotter.h"
#include "Draw.h"

// CreateSprite(head, body, arms, legs, type);
// NOTE: This function should be implemented using libjpeg

class Pokemon
{
private:
   int    index,          // Identification of individual Pokemon
          hp,             // Health of Pokemon
          damage,         // Base damage of Pokemon
          damageRange,    // Damage range of Pokemon
          defense,        // Ability of Pokemon to "deflect" attack damage
          maxHP,          // Max HP of pokemon (equal to base HP, will be
                          // set in HP set function)
          maxDefense;     // Max Defense of pokemon (equal to twice base
                          // defense, will be set in defense set function)

   std::string  type,     // Type of Pokemon (fire, water, earth, air)
                name,     // Name of Pokemon
                head,     // Pokemon head
                body,     // Pokemon body
                arm,      // Pokemon arm
                leg;      // Pokemon leg

public:
  // CONSTRUCTORS
  Pokemon();
  Pokemon(int hp, int damage, int damageRange, int defense, std::string type,
          std::string name, std::string head, std::string body,
          std::string arm, std::string leg);

  // SET & GET
  void setHP(int);
  int getHP();
  void setDamage(int);
  int getDamage();
  void setDamageRange(int);
  int getDamageRange();
  void setDefense(int);
  int getDefense();
  int getIndex();
  int getMaxHP();
  int getMaxDefense();
  void setType(std::string);
  std::string getType();
  void setName(std::string);
  std::string getName();
  void setHead(std::string);
  std::string getHead();
  void setBody(std::string);
  std::string getBody();
  void setArm(std::string);
  std::string getArm();
  void setLeg(std::string);
  std::string getLeg();

  // GRAPHICS
  void PokeDraw(int x, int y, SDL_Plotter& g, std::ifstream& in);

  // COMBAT
  void harm(int);
  void heal(int);
  void sapDefense(int);
  void buffDefense(int);
  void attack1(Pokemon& target);
  void attack2(Pokemon& target);
  void attack3(Pokemon& target);

  // DATA MANAGEMENT
  void CreateIndex(int, int, int, int, int, const int, const int, const int,
                   const int);
  void HPDraw(int x, int y, SDL_Plotter& g, std::ifstream& in,
              bool flip);
};

#endif // POKEMON_H
