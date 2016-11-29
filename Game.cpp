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
                int armDamageMods[], int legDamageMods[], int headNum,
                int bodyNum, int armNum, int legNum, int typeNum)
{
  Pokemon genPokemon;

  int headIndex, bodyIndex, armIndex, legIndex, typeIndex;
  int tempHP, tempDamage, tempRange, tempDefense;

  std::string name;

  srand(time(NULL));

  headIndex = rand() % headNum;
  bodyIndex = rand() % bodyNum;
  armIndex = rand() % armNum;
  legIndex = rand() % legNum;
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

  genPokemon.CreateIndex(typeIndex, headIndex, bodyIndex, armIndex, legIndex);

  return genPokemon;
}

Pokemon GenFromID(int index, std::string heads[], std::string bodies[],
                std::string arms[],
                std::string legs[], std::string types[], std::string prefix[],
                std::string name1[], std::string name2[], std::string name3[],
                std::string name4[], int headDefenseMods[], int bodyHPMods[],
                int armDamageMods[], int legDamageMods[])
{
  Pokemon genPokemon;
  int headIndex, bodyIndex, armIndex, legIndex, typeIndex;
  int tempHP, tempDamage, tempRange, tempDefense;
  std::string name;

  index--;
  typeIndex = index / 81;
  index %= 81;
  headIndex = index / 27;
  index %= 27;
  bodyIndex = index / 9;
  index %= 9;
  armIndex = index / 3;
  index %= 3;
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

  genPokemon.CreateIndex(typeIndex, headIndex, bodyIndex, armIndex, legIndex);

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
            std::ifstream& in, std::ostream& out, int playerX, int playerY,
            int& victories, std::vector<Pokemon>& pokeTeam, const int MAX)
{
  bool playerTurn = true;
  int option = 1;
  int catchPoke;
  int enemyChoice;
  int cursorX = 248, cursorY = 492;
  char hitKey;

  out << "Your Stats:\n\n" << "Name: " << active.getName()
                 << std::endl << "HP: " << active.getHP() << std::endl
                 << "Damage: " << active.getDamage() << std::endl
                 << "Range: " << active.getDamageRange() << std::endl
                 << "Defense: " << active.getDefense() << std::endl
                 << "ID: " << active.getIndex() << std::endl << std::endl;

  srand(time(NULL));

  Draw(0, 0, g, in, "battleScreen.dat", false);

  active.PokeDraw(177, 310, g, in);
  enemy.PokeDraw(490, 310, g, in);

  Draw(cursorX, cursorY, g, in, "cursor.dat", false);

  while((active.getHP() > 0) && (enemy.getHP() > 0))
  {
    out << "Your HP: " << active.getHP() << std::endl;
    out << "Enemy HP: " << enemy.getHP() << std::endl;
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
          case 4:
          default:
            break;
          }
          out << "Player used attack #" << option << std::endl;
          playerTurn = false;
        default:
          break;
        }
        Draw(0, 0, g, in, "battleScreen.dat", false);

        active.PokeDraw(177, 310, g, in);
        enemy.PokeDraw(490, 310, g, in);

        Draw(cursorX, cursorY, g, in, "cursor.dat", false);
      }
    }
    enemyChoice = rand() % 3 + 1;

    out << "Enemy uses attack #" << enemyChoice << "!\n\n";

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
    out << active.getName() << " has been killed!\n";

    pokeTeam.erase(pokeTeam.begin());

    if(pokeTeam.empty())
    {
      out << "You died!\n";
      Draw(0, 0, g, in, "gameOver.dat", false);
      while(!g.kbhit())
      {
        g.update();
      }
      g.setQuit(true);
    }
    else
    {
      active = pokeTeam[0];
      out << "Your Stats:\n\n" << "Name: " << active.getName()
                 << std::endl << "HP: " << active.getHP() << std::endl
                 << "Damage: " << active.getDamage() << std::endl
                 << "Range: " << active.getDamageRange() << std::endl
                 << "Defense: " << active.getDefense() << std::endl
                 << "ID: " << active.getIndex() << std::endl << std::endl;
      Draw(0, 0, g, in, "map1.dat", false);
      Draw(playerX, playerY, g, in, "player1.dat", false);
    }
  }
  else
  {
    srand(time(NULL));

    catchPoke = rand() % 100 + 1;
    out << "You defeated the " << enemy.getName() << "!\n";
    Draw(0, 0, g, in, "map1.dat", false);
    Draw(playerX, playerY, g, in, "player1.dat", false);
    active.setHP(active.getMaxHP());
    active.setDefense(active.getMaxDefense() / 2);
    victories++;
    out << "You have won " << victories << " battles!\n";

    if(int(catchPoke) > 70)
    {
      enemy.setHP(enemy.getMaxHP());
      enemy.setDefense(enemy.getMaxDefense() / 2);
      out << "You caught " << enemy.getName() << "!\n";
      if(pokeTeam.size() >= MAX)
      {
        out << enemy.getName() << " replaced " << pokeTeam[MAX - 1].getName() << "!\n";
        pokeTeam.pop_back();
        pokeTeam.push_back(enemy);
      }
      else
      {
        pokeTeam.push_back(enemy);
      }

    }

  }
}

void Load(std::ifstream& in, std::string fileName, SDL_Plotter& g,
          int victories, std::vector<Pokemon>& pokeTeam, int& x, int& y,
          std::string heads[], std::string bodies[], std::string arms[],
          std::string legs[], std::string types[], std::string prefix[],
          std::string name1[], std::string name2[], std::string name3[],
          std::string name4[], int headDefenseMods[], int bodyHPMods[],
          int armDamageMods[], int legDamageMods[], std::ostream& out)
{
  int pokemonRead = 0,
      id;

  Pokemon poke;

  pokeTeam.clear();

  in.open(fileName.c_str());

  if(in.is_open())
  {
    out << "Reading from save file...\n\n";
    in.ignore(500, '\n');

    in >> victories >> x >> y;

    out << "battlesWon set to " << victories << ".\n";

    while((in >> id) && pokemonRead < 4)
    {
      poke = GenFromID(id, heads, bodies, arms, legs, types, prefix, name1,
                       name2, name3, name4, headDefenseMods, bodyHPMods,
                       armDamageMods, legDamageMods);

      pokeTeam.push_back(poke);

      pokemonRead++;

      out << "ID for Pokemon #" << pokemonRead << ": " << id << "\n";
    }

    in.close();

    Draw(0, 0, g, in, "map1.dat", false);
    Draw(x, y, g, in, "player1.dat", false);
    out << "Screen Loaded.\n\n";
  }

}
