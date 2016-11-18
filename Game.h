/*
Author: J.R.Diehl
Title: Header file for game functions library
*/

#include "Plotter.h"
#include "Pokemon.h"
#include <fstream>

#ifndef GAME_H
#define GAME_H

void Draw(int x, int y, SDL_Plotter& g, ifstream& in);

void Start();

void Move(int x, int y, SDL_Plotter& g, ifstream& in);

void Battle(Pokemon active, Pokemon enemy)

#endif // GAME_H
