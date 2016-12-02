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
#include <SDL_ttf.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <time.h>                 //srand(), rand()

using namespace std;

int main(int argc, char ** argv)
{

    // DATA ABSTRACTIONS
    const int NUM_HEADS = 3,
              NUM_BODIES = 3,
              NUM_ARMS = 3,
              NUM_LEGS = 3,
              NUM_TYPES = 4,
              MAX_POKE = 4,
              SIZE = 700;

    SDL_Plotter g(SIZE,SIZE);
    int x = 330, y = 330;
    int cursorX = 195, cursorY = 297;
    int menuChoice = 1;
    int encounter = 0;
    int moves = 0;

    bool successfulLoad;

    int headDefenseMods[] = {3, 2, 1};
    int bodyHPMods[] = {5, 3, 8};
    int armDamageMods[] = {2, 5, 1};
    int legDamageMods[] = {4, 1, 2};

    char hitKey = 'f';

    ifstream in;
    ofstream out;

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
    Pokemon starterPoke;
    int battlesWon = 0;
    vector<Pokemon> team;

    Pokemon enemyPoke;

    srand(time(NULL));

    team.clear();

    Draw(0, 0, g, in, "startMenu.dat", false);
    Draw(cursorX, cursorY, g, in, "cursor.dat", false);

    do
    {
      g.update();

      if(g.kbhit())
      {
        hitKey = g.getKey();

        switch(hitKey)
        {
        case UP_ARROW:
        case 'W':
          cursorY -= 68;
          menuChoice--;
          if(cursorY < 297)
          {
            cursorY = 437;
            menuChoice = 3;
          }
          break;
        case DOWN_ARROW:
        case 'S':
          cursorY += 68;
          menuChoice++;
          if(cursorY > 437)
          {
            cursorY = 297;
            menuChoice = 1;
          }
          break;
        default:
          break;
        }
        Draw(0, 0, g, in, "startMenu.dat", false);
        Draw(cursorX, cursorY, g, in, "cursor.dat", false);
      }
    }while(hitKey != ' ');

    switch(menuChoice)
    {
    case 1:
      starterPoke = GenPoke(heads, bodies, arms, legs, types, prefix,
                         name1, name2, name3, name4, headDefenseMods,
                         bodyHPMods, armDamageMods, legDamageMods,
                         NUM_HEADS, NUM_BODIES, NUM_ARMS, NUM_LEGS,
                         NUM_TYPES);

      team.push_back(starterPoke);
      break;
    case 2:
      successfulLoad = Load(in, "save.dat", g, battlesWon, team, x, y, heads,
                            bodies, arms, legs, types, prefix, name1, name2,
                            name3, name4, headDefenseMods, bodyHPMods,
                            armDamageMods, legDamageMods, NUM_HEADS,
                            NUM_BODIES, NUM_ARMS, NUM_LEGS);
      if(successfulLoad == false)
      {
        starterPoke = GenPoke(heads, bodies, arms, legs, types, prefix,
                         name1, name2, name3, name4, headDefenseMods,
                         bodyHPMods, armDamageMods, legDamageMods,
                         NUM_HEADS, NUM_BODIES, NUM_ARMS, NUM_LEGS,
                         NUM_TYPES);

        team.push_back(starterPoke);
        x = 330;
        y = 330;
        battlesWon = 0;
      }
      break;
    case 3:
      g.setQuit(true);
      g.update();
    default:
      break;
    }

    while(!g.getQuit())
    {
      activePoke = team[0];

      Draw(0, 0, g, in, "map1.dat", false);
      Draw(x, y, g, in, "player1.dat", false);

      while (!g.getMenu())
      {
        g.update();

        if(g.kbhit()){
            hitKey = g.getKey();
            switch(hitKey)
            {
            case UP_ARROW:
            case 'W':
              y -= 30;
              if((x >= 533) && (x <= 582))
              {
                if(!((y <= 70) && (y >= 50)))
                  y += 30;
              }
              encounter = (rand() % 100) + (10 * moves);
              moves++;
              if(y < 0)
                y = SIZE - 30;
              break;
            case DOWN_ARROW:
            case 'S':
              y += 30;
              if((x >= 533) && (x <= 582))
              {
                if(!((y <= 70) && (y >= 50)))
                  y -= 30;
              }
              encounter = (rand() % 100) + (10 * moves);
              moves++;
              if(y > (SIZE - 30))
                y = 0;
              break;
            case LEFT_ARROW:
            case 'A':
              x -= 15;
              if((x >= 533) && (x <= 582))
              {
                if(!((y <= 70) && (y >= 50)))
                  x += 15;
              }
              encounter = (rand() % 100) + (10 * moves);
              moves++;
              if(x < 0)
                x = SIZE - 15;
              break;
            case RIGHT_ARROW:
            case 'D':
              x += 15;
              if((x >= 533) && (x <= 582))
              {
                if(!((y <= 70) && (y >= 50)))
                  x -= 15;
              }
              encounter = (rand() % 100) + (10 * moves);
              moves++;
              if(x > (SIZE - 15))
                x = 0;
              break;
            case ' ':
              break;
            case ESCAPE_KEY:
              g.setMenu(true);
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

              Battle(activePoke, enemyPoke, g, in, x, y, battlesWon, team,
                     MAX_POKE);
            }
            else
            {
              Draw(0, 0, g, in, "map1.dat", false);

              Draw(x, y, g, in, "player1.dat", false);
            }
        }
      }

      if(g.getMenu() && !g.getQuit())
      {
        gameMenu(g, in, team);
        activePoke = team[0];
        g.setMenu(false);
      }

      Save("save.dat", out, battlesWon, x, y, team);
    }

  return 0;
}
