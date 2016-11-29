/*  Author:             J.R.Diehl, Ethan Van Sligtenhorst (comments)
    Title:              Header file for game functions library.
    Description:        Includes declaration of several methods that allow
                            for actual gameplay to occur (generating Pokemon,
                            player characters, and battles.
    Due Date:           12/1/2016
    Date Last Modified: ---
    Date Created:       11/28/2016
 */

#include "Pokemon.h"
#include "Plotter.h"
#include "Draw.h"
#include <iostream>
#include <fstream>
#include <vector>

#ifndef GAME_H
#define GAME_H

/*  Description:   This method allows the caller to generate a Pokemon with
                    randomly selected features.
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
                   Returns an object of type Pokemon with the given features.
    Return:        Pokemon
 */
Pokemon GenPoke(std::string heads[], std::string bodies[], std::string arms[],
             std::string legs[], std::string types[], std::string prefix[],
             std::string name1[], std::string name2[], std::string name3[],
             std::string name4[], int headDefenseMods[], int bodyHPMods[],
             int armDamageMods[], int legDamageMods[], int headNum,
             int bodyNum, int armNum, int legNum, int typeNum);

/*  Description:   This method allows the caller to generate a Pokemon with
                    features that correspond to the ID passed in.
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
                   Returns an object of type Pokemon with the given features.
    Return:        Pokemon
 */
Pokemon GenFromID(int index, std::string heads[], std::string bodies[],
                std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[]);

/*  Description:   This method
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
                   Returns an object of type Player with the given features.
    Return:        Player
 */
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
 
void Load(std::ifstream& in, std::string fileName, SDL_Plotter& g,
          int victories, std::vector<Pokemon>& pokeTeam, int& x, int& y,
          std::string heads[], std::string bodies[], std::string arms[],
          std::string legs[], std::string types[], std::string prefix[],
          std::string name1[], std::string name2[], std::string name3[],
          std::string name4[], int headDefenseMods[], int bodyHPMods[],
          int armDamageMods[], int legDamageMods[], std::ostream& out);

/*  Description:   This method allows for fighting between the player's Pokemon
                    and the Pokemon that are randomly generated when the player
                    walks across a certain point on the map.
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
    Return:        void
 */
void Battle(Pokemon& active, Pokemon& enemy, SDL_Plotter& g,
            std::ifstream& in, std::ostream& out, int playerX, int playerY,
            int& victories, std::vector<Pokemon>& pokeTeam, const int MAX);

#endif // GAME_H
