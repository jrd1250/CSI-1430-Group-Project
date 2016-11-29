/*
Author: J.R.Diehl
Title: Header file for game functions library
*/

#include "Pokemon.h"
#include "Plotter.h"
#include "Draw.h"
#include "Player.h"
#include <iostream>
#include <fstream>

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

#endif // GAME_H
