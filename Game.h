/*
Author: J.R.Diehl
Title: Header file for game functions library
*/

#include "Pokemon.h"
#include "Plotter.h"
#include "Draw.h"
#include <iostream>
#include <fstream>
#include <vector>

#ifndef GAME_H
#define GAME_H

Pokemon GenPoke(std::string heads[], std::string bodies[], std::string arms[],
             std::string legs[], std::string types[], std::string prefix[],
             std::string name1[], std::string name2[], std::string name3[],
             std::string name4[], int headDefenseMods[], int bodyHPMods[],
             int armDamageMods[], int legDamageMods[], int headNum,
             int bodyNum, int armNum, int legNum, int typeNum);

Pokemon GenFromID(int index, std::string heads[], std::string bodies[],
                std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[]);
/*
Player Start(SDL_Plotter& g, std::ifstream& in,
             std::string heads[], std::string bodies[],
             std::string arms[],
             std::string legs[], std::string types[], std::string prefix[],
             std::string name1[], std::string name2[], std::string name3[],
             std::string name4[], int headDefenseMods[], int bodyHPMods[],
             int armDamageMods[], int legDamageMods[], int headNum,
             int bodyNum, int armNum, int legNum, int typeNum);
*/
void Battle(Pokemon& active, Pokemon& enemy, SDL_Plotter& g,
            std::ifstream& in, std::ostream& out, int playerX, int playerY,
            int& victories, std::vector<Pokemon>& pokeTeam, const int MAX);

void Load(std::ifstream& in, std::string fileName, SDL_Plotter& g,
          int victories, std::vector<Pokemon>& pokeTeam, int& x, int& y,
          std::string heads[], std::string bodies[], std::string arms[],
          std::string legs[], std::string types[], std::string prefix[],
          std::string name1[], std::string name2[], std::string name3[],
          std::string name4[], int headDefenseMods[], int bodyHPMods[],
          int armDamageMods[], int legDamageMods[], std::ostream& out);

#endif // GAME_H
