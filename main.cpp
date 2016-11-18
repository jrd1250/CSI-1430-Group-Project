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
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int SIZE = 700;

int main(int argc, char ** argv)
{
    SDL_Plotter g(SIZE,SIZE);
    int x = 350, y = 350;
    ifstream in;

    Draw(x, y, g, in);

    while (!g.getQuit())
    {

        /*
    	x = rand()%g.getCol();
    	y = rand()%g.getRow();
    	R = rand()%256;
    	G = rand()%256;
    	B = rand()%256;
    	for(xd = 0; xd < 10 && x + xd < g.getCol(); xd++ ){
    		for(yd = 0; yd < 10 && y + yd < g.getRow(); yd++ ){
    	    	g.plotPixel( x + xd, y + yd, R, G, B);
    	    	g.plotPixel( x + xd, y + yd, R, G, B);

    		}
    	}*/
    	g.update();

    	//NOTE: FIX TOP OF MAP CRASH
    	if(g.kbhit()){
    	    if(g.getKey() == 'W' || g.getKey() == UP_ARROW)
            y-=30;
          else if(g.getKey() == 'S' || g.getKey() == DOWN_ARROW)
            y+=30;
          else if(g.getKey() == 'A' || g.getKey() == LEFT_ARROW)
            x-=15;
          else if(g.getKey() == 'D' || g.getKey() == RIGHT_ARROW)
            x+=15;

          Draw(x, y, g, in);

    	}
    }

  return 0;
}
