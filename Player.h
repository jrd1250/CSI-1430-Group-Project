/*
Author: J.R. Diehl
Title: Header file for player class
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include "Pokemon.h"
#include "Draw.h"

class Player
{
private:
  int numPokemon,
      battlesWon,
      playerNum,
      currMap;
  std::string name;
  Pokemon activePokemon;

public:
  // CONSTRUCTORS
  Player();
  Player(Pokemon active);
  Player(int pokeNum, int victory, int m,
         std::string name, Pokemon active);

  // SET & GET
  void setNumPokemon(int);
  int getNumPokemon();
  void setBattlesWon(int);
  int getBattlesWon();
  void setName(std::string);
  std::string getName();
  void setActivePokemon(Pokemon);
  Pokemon getActivePokemon();


  // SAVE & LOAD
  void Save(std::ofstream& out);
  void Load(std::ifstream& in);
};

#endif // PLAYER_H
