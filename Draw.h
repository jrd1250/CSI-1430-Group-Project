/*
Author: J.R. Diehl
Title: Draw Library Header File
*/

#include "Plotter.h"
#include <fstream>

#ifndef DRAW_H
#define DRAW_H

void Draw(int x, int y, SDL_Plotter& g, std::ifstream& in,
          std::string toDraw, bool flip);

void modDraw(int x, int y, SDL_Plotter& g, std::ifstream& in,
             std::string toDraw, std::string modColor, bool flip);

#endif // DRAW_H
