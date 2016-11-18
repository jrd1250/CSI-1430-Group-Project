/*
Author: J.R. Diehl
Title: Header for Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>

// CreateSprite(head, body, arms, legs, type);
// NOTE: This function should be implemented using libjpeg

class Pokemon
{
private:
  const int ID;
  int hp,
      defense;
  string type,
         name;

public:
  // CONSTRUCTORS
  Pokemon();
  Pokemon(const int index, int hp, int defense, string type, string name);

  // SET & GET
  void setHP(int);
  int getHP();
  void setDefense(int);
  int getDefense();
  int getIndex();
  void setType(string);
  string getType();
  void setName(string);
  string getName();

  // COMBAT
  void damage(int);
  void heal(int);
  void sapDefense(int);
  void buffDefense(int);
  void attack1(Pokemon target);
  void attack2(Pokemon target);
  void attack3(Pokemon target);

  // DATA MANAGEMENT
  void writeData(ofstream& out);
  void readData(ifstream& in);

};

#endif // POKEMON_H
