/*
Author:                 J.R. Diehl,
Assignment Title:       Pokemon Group Project
Assignment Description: Main program file for Pokemon Project
Due Date:               11/30/2016
Date Created:           11/16/2016
Date Last Modified:     11/16/2016
*/

#include "Plotter.h"
#include "Pokemon.h"
#include "Draw.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <time.h>                 //srand(), rand()

using namespace std;



int main(int argc, char ** argv)
{
    const int NUM_HEADS = 3,
              NUM_BODIES = 3,
              NUM_ARMS = 3,
              NUM_LEGS = 3,
              NUM_TYPES = 4,
              MAX_POKE = 4,
              SIZE = 700;

    SDL_Plotter g(SIZE,SIZE);
    int x = 330, y = 330;
    int encounter = 0;
    int moves = 0;

    int headDefenseMods[] = {3, 2, 1};
    int bodyHPMods[] = {5, 3, 8};
    int armDamageMods[] = {2, 5, 1};
    int legDamageMods[] = {4, 1, 2};

    char hitKey;

    ifstream in;

    string types[] = {"Fire", "Earth", "Air", "Water"};
                          // Array of Pokemon types
    string heads[] = {"head1.dat", "head2.dat", "head3.dat"};
                          // Array of head file names
    string bodies[] = {"body1.dat", "body2.dat", "body3.dat"};
                          // Array of body file names
    string arms[] = {"arm1.dat", "arm2.dat", "arm3.dat"};
                          // Array of arm file names
    string legs[] = {"leg1.dat", "leg2.dat", "leg3.dat"};
                          // Array of leg file names
    string prefix[] = {"Fiery ", "Dirty ", "Breezy ", "Squishy "};
                          // Array of prefixes
    string name1[] = {"Pi", "Char", "Squir"};
                          // Array of first syllable
    string name2[] = {"ka", "gil", "man"};
                          // Array of second syllable
    string name3[] = {"saur", "dill", "guy"};
                          // Array of third syllable
    string name4[] = {" of Speed", " of Cunning", " of Strength"};
                          // Array of last name section


    // Player Variables
    Pokemon activePoke;
    int battlesWon = 0;
    vector<Pokemon> team;

    Pokemon enemyPoke;

    srand(time(NULL));

    Draw(0, 0, g, in, "map1.dat", false);
    Draw(x, y, g, in, "player1.dat", false);

    activePoke = GenPoke(heads, bodies, arms, legs, types, prefix,
                         name1, name2, name3, name4, headDefenseMods,
                         bodyHPMods, armDamageMods, legDamageMods,
                         NUM_HEADS, NUM_BODIES, NUM_ARMS, NUM_LEGS,
                         NUM_TYPES);

    team.insert(team.begin(), activePoke);

    Load(in, "testSave.txt", g, battlesWon, team, x, y, heads, bodies, arms, legs,
         types, prefix, name1, name2, name3, name4, headDefenseMods,
         bodyHPMods, armDamageMods, legDamageMods, cout);

    activePoke = team[0];

    cout << "Your Stats:\n\n" << "Name: " << activePoke.getName()
                 << endl << "HP: " << activePoke.getHP() << endl
                 << "Damage: " << activePoke.getDamage() << endl
                 << "Range: " << activePoke.getDamageRange() << endl
                 << "Defense: " << activePoke.getDefense() << endl
                 << "ID: " << activePoke.getIndex() << endl << endl;

    while (!g.getQuit())
    {
    	g.update();

    	if(g.kbhit()){
          hitKey = g.getKey();
          switch(hitKey)
          {
          case UP_ARROW:
          case 'W':
            y -= 30;
            encounter = (rand() % 100) + (10 * moves);
            moves++;
            if(y < 0)
              y = SIZE - 30;
            break;
          case DOWN_ARROW:
          case 'S':
            y += 30;
            encounter = (rand() % 100) + (10 * moves);
            moves++;
            if(y > (SIZE - 30))
              y = 0;
            break;
          case LEFT_ARROW:
          case 'A':
            x -= 15;
            encounter = (rand() % 100) + (10 * moves);
            moves++;
            if(x < 0)
              x = SIZE - 15;
            break;
          case RIGHT_ARROW:
          case 'D':
            x += 15;
            encounter = (rand() % 100) + (10 * moves);
            moves++;
            if(x > (SIZE - 15))
              x = 0;
            break;
          case ' ':
            encounter = 200;
            moves = 0;
            break;
          default:
            break;
          }

          if (encounter >= 175)
          {
            encounter = 0;
            moves = 0;

            enemyPoke = GenPoke(heads, bodies, arms, legs, types, prefix,
                                name1, name2, name3, name4, headDefenseMods,
                                bodyHPMods, armDamageMods, legDamageMods,
                                NUM_HEADS, NUM_BODIES, NUM_ARMS, NUM_LEGS,
                                NUM_TYPES);

            cout << "Enemy Stats:\n\n" << "Name: " << enemyPoke.getName()
                 << endl << "HP: " << enemyPoke.getHP() << endl
                 << "Damage: " << enemyPoke.getDamage() << endl
                 << "Range: " << enemyPoke.getDamageRange() << endl
                 << "Defense: " << enemyPoke.getDefense() << endl
                 << "ID: " << enemyPoke.getIndex() << endl << endl;

            Battle(team[0], enemyPoke, g, in, cout, x, y, battlesWon, team,
                   MAX_POKE);
          }
          else
          {
            Draw(0, 0, g, in, "map1.dat", false);

            Draw(x, y, g, in, "player1.dat", false);
          }
    	}
    }

  return 0;
}
