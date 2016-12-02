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
             int armDamageMods[], int legDamageMods[], int typeNum,
             const int MAXHEAD, const int MAXBODY, const int MAXARM,
             const int MAXLEG);

Pokemon GenFromID(int index, std::string heads[], std::string bodies[],
                std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[],
                const int MAXHEAD, const int MAXBODY, const int MAXARM,
                const int MAXLEG);
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
            std::ifstream& in, int playerX, int playerY,
            int& victories, std::vector<Pokemon>& pokeTeam, const int MAX);

//save function
void Save(std::string fileName, std::ofstream& output, int battlesWon,
          int xCoord, int yCoord, std::vector<Pokemon>& pokeTeam);

bool Load(std::ifstream& in, std::string fileName, SDL_Plotter& g,
          int victories, std::vector<Pokemon>& pokeTeam, int& x, int& y,
          std::string heads[], std::string bodies[], std::string arms[],
          std::string legs[], std::string types[], std::string prefix[],
          std::string name1[], std::string name2[], std::string name3[],
          std::string name4[], int headDefenseMods[], int bodyHPMods[],
          int armDamageMods[], int legDamageMods[], const int MAXHEAD,
          const int MAXBODY, const int MAXARM, const int MAXLEG);

void gameMenu(SDL_Plotter& g, ifstream& in, std::vector<Pokemon>& pokeTeam);

void switchMenu(SDL_Plotter& g, ifstream& in, std::vector<Pokemon>& pokeTeam);

#endif // GAME_H
