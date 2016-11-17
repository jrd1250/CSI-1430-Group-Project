/*
Author:                 J.R. Diehl,
Assignment Title:       Pokemon Group Project
Assignment Description: Main program file for Pokemon Project
Due Date:               11/30/2016
Date Created:           11/16/2016
Date Last Modified:     11/16/2016
*/

#include "Plotter.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(1000,1000);
    int x,y, xd, yd;
    int R,G,B;

    while (!g.getQuit())
    {
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
    	}
    	g.update();
    	if(g.kbhit()){
    	    g.getKey();
    	}
    }

  return 0;
}
