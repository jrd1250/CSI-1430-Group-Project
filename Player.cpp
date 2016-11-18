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
  name = "DudeGuy";
  activePokemon = Pokemon();
}

Player::Player(int pokeNum, int victory, int n, int m,
         string name, Pokemon active)
{
  numPokemon = pokeNum;
  battleWon = victory;
  playerNum = n;
  currMap = m;
  name = name;
  activePokemon = active;
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

void Player::setActivePokemon(Pokemon n)
{
  activePokemon = n;
}

Pokemon Player::getActivePokemon()
{
  return activePokemon;
}

void Player::Save(std::ofstream& out)
{
  out << "Save File for player" << playerNum << std::endl
      << numPokemon << ' ' << battlesWon << ' ' << playerNum << ' ' << currMap
      << ' ' << name << ' ';
}

void Player::Load(std::ifstream& in)
{

}

