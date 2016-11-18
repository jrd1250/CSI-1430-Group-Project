/*
Author: J.R. Diehl
Title: Implementation file for game functions library
*/

#include "Plotter.h"
#include "Pokemon.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

const int SIZE = 700;
const int PLAYER_HEIGHT = 30;
const int PLAYER_WIDTH = 15;

void Draw(int x, int y, SDL_Plotter& g, ifstream& in)
{
    int xd,yd;
    int R,G,B;

    in.open("map1.dat");
    in.ignore(500, '\n');
    in.ignore(500, '\n');

    for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
      {
        in >> R >> G >> B;
        g.plotPixel(j, i, R, G, B);
      }
    }
    in.close();

    in.open("player1.dat");
    in.ignore(500, '\n');
    in.ignore(500, '\n');

    for(int n = 0; n < PLAYER_HEIGHT; n++)
    {
      for(int m = 0; m < PLAYER_WIDTH; m++)
      {
        in >> R >> G >> B;
        g.plotPixel(x + m, y + n, R, G, B);
      }
    }
    in.close();
}

void Start()
{

}

void Move()
{

}
