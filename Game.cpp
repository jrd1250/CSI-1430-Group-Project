/*
Author: J.R. Diehl
Title: Implementation file for game functions library
*/

#include "Plotter.h"
#include "Pokemon.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>


Pokemon GenPoke(std::string heads[], std::string bodies[], std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[], int typeNum,
                const int MAXHEAD, const int MAXBODY, const int MAXARM,
                const int MAXLEG)
{
  Pokemon genPokemon;

  int headIndex, bodyIndex, armIndex, legIndex, typeIndex;
  int tempHP, tempDamage, tempRange, tempDefense;

  std::string name;

  srand(time(NULL));

  headIndex = rand() % MAXHEAD;
  bodyIndex = rand() % MAXBODY;
  armIndex = rand() % MAXARM;
  legIndex = rand() % MAXLEG;
  typeIndex = rand() % typeNum;
  tempHP = 30 + bodyHPMods[bodyIndex];
  tempDamage = 8 + armDamageMods[armIndex] + legDamageMods[legIndex];
  tempRange = 3;
  tempDefense = 3 + headDefenseMods[headIndex];

  name = prefix[typeIndex] + name1[headIndex] + name2[bodyIndex] +
         name3[armIndex] + name4[legIndex];

  genPokemon = Pokemon(tempHP, tempDamage, tempRange, tempDefense,
                      types[typeIndex], name, heads[headIndex],
                      bodies[bodyIndex], arms[armIndex],
                      legs[legIndex]);

  genPokemon.CreateIndex(typeIndex, headIndex, bodyIndex, armIndex, legIndex,
                         MAXHEAD, MAXBODY, MAXARM, MAXLEG);

  return genPokemon;
}

Pokemon GenFromID(int index, std::string heads[], std::string bodies[],
                std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[],
                const int MAXHEAD, const int MAXBODY, const int MAXARM,
                const int MAXLEG)
{
  Pokemon genPokemon;
  int headIndex, bodyIndex, armIndex, legIndex, typeIndex;
  int tempHP, tempDamage, tempRange, tempDefense;
  int idMod = MAXHEAD * MAXBODY * MAXARM * MAXLEG;
  std::string name;

  index--;
  typeIndex = index / idMod;
  index %= idMod;
  idMod /= MAXHEAD;
  headIndex = index / idMod;
  index %= idMod;
  idMod /= MAXBODY;
  bodyIndex = index / idMod;
  index %= idMod;
  idMod /= MAXARM;
  armIndex = index / idMod;
  index %= idMod;
  legIndex = index;

  srand(time(NULL));

  tempHP = 30 + bodyHPMods[bodyIndex];
  tempDamage = 8 + armDamageMods[armIndex] + legDamageMods[legIndex];
  tempRange = 3;
  tempDefense = 3 + headDefenseMods[headIndex];

  name = prefix[typeIndex] + name1[headIndex] + name2[bodyIndex] +
         name3[armIndex] + name4[legIndex];

  genPokemon = Pokemon(tempHP, tempDamage, tempRange, tempDefense,
                      types[typeIndex], name, heads[headIndex],
                      bodies[bodyIndex], arms[armIndex],
                      legs[legIndex]);

  genPokemon.CreateIndex(typeIndex, headIndex, bodyIndex, armIndex, legIndex,
                         MAXHEAD, MAXBODY, MAXARM, MAXLEG);

  return genPokemon;
}
/*
Player Start(SDL_Plotter& g, std::ifstream& in,
             std::string heads[], std::string bodies[],
             std::string arms[],
             std::string legs[], std::string types[], std::string prefix[],
             std::string name1[], std::string name2[], std::string name3[],
             std::string name4[], int headDefenseMods[], int bodyHPMods[],
             int armDamageMods[], int legDamageMods[], int headNum,
             int bodyNum, int armNum, int legNum, int typeNum)
{
  bool selection = false;
  int option = 1;
  int cursorX = 196, cursorY = 297;
  Draw(0, 0, g, in, "startMenu.dat", false);
  Draw(cursorX, cursorY, g, in, "cursor.dat", false);

  Player gamePlayer;

  while(!selection)
  {
    g.update();

    if(g.kbhit()){
      hitKey = g.getKey();
      switch(hitKey)
      {
      case UP_ARROW:
      case 'W':
        option--;
        cursorY -= 68;
        if(cursorY < 297)
        {
          cursorY = 433;
          option = 3;
        }
        break;
      case DOWN_ARROW:
      case 'S':
        option++;
        cursorY += 68;
        if(cursorY > 433)
        {
          cursorY = 297;
          option = 1;
        }
        break;
      case ' ':
        switch(option)
        {
        case 1:
          break;
        case 2:
          active.attack2(enemy);
          break;
        case 3:
          active.attack3(enemy);
        default:
          break;
        }
      }
  }
}
*/
void Battle(Pokemon& active, Pokemon& enemy, SDL_Plotter& g,
            std::ifstream& in, int playerX, int playerY,
            int& victories, std::vector<Pokemon>& pokeTeam, const int MAX)
{
  bool playerTurn = true;
  int option = 1;
  int catchPoke;
  int enemyChoice;
  int cursorX = 248, cursorY = 492;
  int playerHPX = 160, playerHPY = 362;
  int enemyHPX = 472, enemyHPY = 362;
  char hitKey;

  srand(time(NULL));

  Draw(0, 0, g, in, "battleScreen.dat", false);
  active.setHP(active.getMaxHP());
  active.setDefense(active.getMaxDefense() / 2);

  active.HPDraw(playerHPX, playerHPY, g, in, false);
  enemy.HPDraw(enemyHPX, enemyHPY, g, in, false);

  active.PokeDraw(177, 310, g, in);
  enemy.PokeDraw(490, 310, g, in);

  Draw(cursorX, cursorY, g, in, "cursor.dat", false);

  while((active.getHP() > 0) && (enemy.getHP() > 0))
  {
    while(playerTurn)
    {
      g.update();

      if(g.kbhit()){
        hitKey = g.getKey();
        switch(hitKey)
        {
        case UP_ARROW:
        case 'W':
          option--;
          cursorY -= 42;
          if(cursorY < 492)
          {
            cursorY = 618;
            option = 4;
          }
          break;
        case DOWN_ARROW:
        case 'S':
          option++;
          cursorY += 42;
          if(cursorY > 618)
          {
            cursorY = 492;
            option = 1;
          }
          break;
        case ' ':
        switch(option)
        {
        case 1:
          active.attack1(enemy);
          break;
        case 2:
          active.attack2(enemy);
          break;
        case 3:
          active.attack3(enemy);
          break;
        case 4:
          switchMenu(g, in, pokeTeam);
          active = pokeTeam[0];
        default:
          break;
        }
          if(option != 4)
            playerTurn = false;
        default:
          break;
        }

        Draw(0, 0, g, in, "battleScreen.dat", false);

        active.HPDraw(playerHPX, playerHPY, g, in, false);
        enemy.HPDraw(enemyHPX, enemyHPY, g, in, false);

        active.PokeDraw(177, 310, g, in);
        enemy.PokeDraw(490, 310, g, in);

        Draw(cursorX, cursorY, g, in, "cursor.dat", false);
      }
    }
    enemyChoice = rand() % 3 + 1;

    switch(enemyChoice)
    {
    case 1:
      enemy.attack1(active);
      break;
    case 2:
      enemy.attack2(active);
      break;
    case 3:
      enemy.attack3(active);
    default:
      break;
    }
    playerTurn = true;
  }
  if(active.getHP() <= 0)
  {
    pokeTeam.erase(pokeTeam.begin());

    if(pokeTeam.empty())
    {
      Draw(0, 0, g, in, "gameOver.dat", false);
      while(!g.kbhit())
      {
        g.update();
      }
      g.setMenu(true);
      g.setQuit(true);
    }
    else
    {
      active = pokeTeam[0];
      Draw(0, 0, g, in, "map1.dat", false);
      Draw(playerX, playerY, g, in, "player1.dat", false);

      g.Sleep(1000);
    }
  }
  else
  {
    srand(time(NULL));

    Draw(0, 0, g, in, "battleScreen.dat", false);
    active.PokeDraw(177, 310, g, in);

    catchPoke = rand() % 100 + 1;

    victories++;

    if(int(catchPoke) > 70)
    {
      if(int(pokeTeam.size()) >= MAX)
      {
        pokeTeam.pop_back();
        pokeTeam.push_back(enemy);
      }
      else
      {
        pokeTeam.push_back(enemy);
      }
    }

    g.Sleep(500);

    Draw(0, 0, g, in, "map1.dat", false);
    Draw(playerX, playerY, g, in, "player1.dat", false);
  }
}

//save function
void Save(std::string fileName, std::ofstream& output, int battlesWon,
          int xCoord, int yCoord, std::vector<Pokemon>& pokeTeam)
{
  output.open(fileName.c_str());
  output << "This is a save file for Pokemon Infinite\n\n" << battlesWon
         << "\n" << xCoord << "\n" << yCoord << "\n";

  for(int i = 0; i < int(pokeTeam.size()); i++)
  {
    output << pokeTeam[i].getIndex() << " ";
  }
  output.close();
}

bool Load(std::ifstream& in, std::string fileName, SDL_Plotter& g,
          int victories, std::vector<Pokemon>& pokeTeam, int& x, int& y,
          std::string heads[], std::string bodies[], std::string arms[],
          std::string legs[], std::string types[], std::string prefix[],
          std::string name1[], std::string name2[], std::string name3[],
          std::string name4[], int headDefenseMods[], int bodyHPMods[],
          int armDamageMods[], int legDamageMods[], const int MAXHEAD,
          const int MAXBODY, const int MAXARM, const int MAXLEG)
{
  int pokemonRead = 0,
      id;
  bool openedFile = false;

  Pokemon poke;

  pokeTeam.clear();

  in.open(fileName.c_str());

  if(in.is_open())
  {
    in.ignore(500, '\n');

    in >> victories >> x >> y;

    while((in >> id) && pokemonRead < 4)
    {
      openedFile = true;
      poke = GenFromID(id, heads, bodies, arms, legs, types, prefix, name1,
                       name2, name3, name4, headDefenseMods, bodyHPMods,
                       armDamageMods, legDamageMods, MAXHEAD, MAXBODY,
                       MAXARM, MAXLEG);

      pokeTeam.push_back(poke);

      pokemonRead++;
    }

    in.close();

    Draw(0, 0, g, in, "map1.dat", false);
    Draw(x, y, g, in, "player1.dat", false);
  }

  return openedFile;
}

void gameMenu(SDL_Plotter& g, ifstream& in, std::vector<Pokemon>& pokeTeam)
{
  int cursorX = 24, cursorY = 294;
  int option = 1;
  char hitKey = 'f';

  Draw(0, 0, g, in, "gameMenu.dat", false);
  Draw(cursorX, cursorY, g, in, "cursor.dat", false);

  while(hitKey != ' ')
  {
    g.update();

    if(g.kbhit()){
      hitKey = g.getKey();
      switch(hitKey)
      {
      case UP_ARROW:
      case 'W':
        option--;
        cursorY -= 68;
        if(cursorY < 294)
        {
          cursorY = 430;
          option = 3;
        }
        break;
      case DOWN_ARROW:
      case 'S':
        option++;
        cursorY += 68;
        if(cursorY > 430)
        {
          cursorY = 294;
          option = 1;
        }
        break;
      case ' ':
      default:
        break;
      }
      Draw(0, 0, g, in, "gameMenu.dat", false);
      Draw(cursorX, cursorY, g, in, "cursor.dat", false);
      }
  }

  switch(option)
  {
  case 1:
    break;
  case 2:
    switchMenu(g, in, pokeTeam);
    break;
  case 3:
    g.setQuit(true);
  default:
    break;
  }
}

void switchMenu(SDL_Plotter& g, ifstream& in, std::vector<Pokemon>& pokeTeam)
{
  int cursorX = 150, cursorY = 250, max_X = 150;
  int option = 0, maxOption = int(pokeTeam.size()) - 1;
  char hitKey = 'f';

  Pokemon temp;

  max_X += 100 * maxOption;

  Draw(0, 0, g, in, "switch.dat", false);

  for(int i = 0; i < int(pokeTeam.size()); i++)
  {
    pokeTeam[i].PokeDraw(190 + (i * 100), 291, g, in);
  }

  Draw(cursorX, cursorY, g, in, "select.dat", false);

  while(hitKey != ' ')
  {
    g.update();

    if(g.kbhit()){
      hitKey = g.getKey();
      switch(hitKey)
      {
      case LEFT_ARROW:
      case 'A':
        option--;
        cursorX -= 100;
        if(cursorX < 150)
        {
          cursorX = max_X;
          option = maxOption;
        }
        break;
      case RIGHT_ARROW:
      case 'D':
        option++;
        cursorX += 100;
        if(cursorX > max_X)
        {
          cursorX = 150;
          option = 0;
        }
        break;
      case ESCAPE_KEY:
        option = 0;
        hitKey = ' ';
        break;
      case ' ':
      default:
        break;
      }
      Draw(0, 0, g, in, "switch.dat", false);
      for(int i = 0; i < int(pokeTeam.size()); i++)
      {
        pokeTeam[i].PokeDraw(190 + (i * 100), 291, g, in);
      }

      Draw(cursorX, cursorY, g, in, "select.dat", false);
      }
  }

  switch(option)
  {
  case 0:
    break;
  case 1:
    temp = pokeTeam[0];
    pokeTeam[0] = pokeTeam[1];
    pokeTeam[1] = temp;
    break;
  case 2:
    temp = pokeTeam[0];
    pokeTeam[0] = pokeTeam[2];
    pokeTeam[2] = temp;
    break;
  case 3:
    temp = pokeTeam[0];
    pokeTeam[0] = pokeTeam[3];
    pokeTeam[3] = temp;
  default:
    break;
  }

  g.Sleep(500);

}
