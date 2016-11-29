/*  Author:             J.R.Diehl, Ethan Van Sligtenhorst (comments)
    Title:              Header file for draw library.
    Description:        Includes declaration of several methods that allow
                            the Pokemon colors to be decided based on their
                            type.
    Due Date:           12/1/2016
    Date Last Modified: ---
    Date Created:       11/28/2016
 */

#include "Plotter.h"        // SDL_Plotter
#include <fstream>          // ifstream

#ifndef DRAW_H
#define DRAW_H

/*  Description:   This method allows the caller to draw a Pokemon with colors
                    that do not necessary pertain to Pokemon type.
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
    Return:        void
 */
void Draw(int x, int y, SDL_Plotter& g, std::ifstream& in,
          std::string toDraw, bool flip);

/*  Description:   This method allows the caller to draw a Pokemon with colors
                    that specifically pertain to the the Pokemon type.
    Precondition:  All values passed in as parameters already exist and
                    are valid.
    Postcondition: All values passed in as parameters remain unchanged.
    Return:        void
 */
void modDraw(int x, int y, SDL_Plotter& g, std::ifstream& in,
             std::string toDraw, std::string modColor, bool flip);

#endif // DRAW_H

