/*
Author: J.R.Diehl
Title: Header file for game functions library
Due Date: 12/1/16
Date Created: 11/17/16
Date Last Modified: 11/29/16
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
                int armDamageMods[], int legDamageMods[], int headNum,
                int bodyNum, int armNum, int legNum, int typeNum);
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
            std::ifstream& in, std::ostream& out, int playerX, int playerY);
//save function
std::string Save(std::string fileName, std::ofstream&, int& battlesWon,
                 int& xCoord, int& yCoord, std::vector<Pokemon>& pokeTeam);

#endif // GAME_H

