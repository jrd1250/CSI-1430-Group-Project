/*
Author: Nathaniel Haynes
Title:  Player.cpp file
*/

#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Pokemon.h"

Player::Player()
{
  srand(time(NULL));

  numPokemon = 0;
  battlesWon = 0;
  currMap = -1;
  name = "DudeGuy";
  activePokemon = Pokemon();
  team.push_back(activePokemon);
}

Player::Player(Pokemon active)
{
  numPokemon = 0;
  battlesWon = 0;
  currMap = -1;
  name = "DudeGuy";
  activePokemon = active;
  team.push_back(active);
}

Player::Player(int pokeNum, int victory, int m,
         std::string name, Pokemon active)
{
  numPokemon = pokeNum;
  battlesWon = victory;
  currMap = m;
  name = name;
  activePokemon = active;
  team.push_back(active);
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
  battlesWon = n;
}

int Player::getBattlesWon()
{
  return battlesWon;
}

void Player::setName(std::string n)
{
  name = n;
}

std::string Player::getName()
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

void Player::addToTeam(Pokemon p)
{
  team.push_back(p);
}

void Player::Save(std::ofstream& out)
{
  out << "Save File for " << std::endl << name << std::endl << std::endl
      << numPokemon << ' ' << battlesWon << ' ' << currMap
      << ' ' << name << ' ';
}

void Player::Load(std::ifstream& in)
{

}

