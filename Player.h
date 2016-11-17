/*
Author: J.R. Diehl
Title: Header file for player class
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <fstream>
#include "Pokemon.h"

class Player
{
private:
  int numPokemon,
      battlesWon,
      currMap;
  string name;
  Pokemon team<>,
          activePokemon;

public:
  // CONSTRUCTORS
  Player();
  Player(int pokeNum, int victory, string name, Pokemon active)

  // SET & GET
  void setNumPokemon(int);
  int getNumPokemon();
  void setBattlesWon(int);
  int getBattlesWon();
  void setName(string);
  string getName();
  void setActivePokemon(Pokemon);
  Pokemon getActivePokemon();

  // SAVE & LOAD
  void Save(ofstream& out);
  void Load(ifstream& in);
};

#endif // PLAYER_H
