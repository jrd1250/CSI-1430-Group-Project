/*
Author: Nathaniel Haynes
Title:  Player.cpp file
*/

#include <string>
#include "Player.h"
#include "Pokemon.h"

Player::Player()
{
  numPokemon = 0;
  battleWon = 0;
  currMap = -1;
  name = "PokeMan";
  //Pokemon team placeholder for team<> in Pokemon class
}

Player::Player(int pokeNum, int victory, string name, Pokemon active)
{
  numPokemon = pokeNum;
  battleWon = victory;
  currMap = -1;
  name = name;
  //Placeholder for Pokemon active vector
}

void Player::setNumPokemon(int n)
{
  numPokemon = n;
}

int Player::getNumPokemon()
{
  return numPokemon;
}

void Player::setBattlesWon(int n)
{
  battleWon = n;
}

int Player::getBattlesWon()
{
  return battleWon;
}

void Player::setName(string n)
{
  name = n;
}

string Player::getName()
{
  return name;
}

/*void Player::setActivePokemon(Pokemon::Pokemon n)
{
  placeholder for vector team<> active pokemon
}
*/
Pokemon Player::getActivePokemon()
{
  return activePokemon;
}
/*
void Player::Save(ofstream& out)
{

}

void Player::Load(ifstream& in)
{

}
*/
