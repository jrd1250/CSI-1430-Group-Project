/*
Author: J.R. Diehl
Title: Draw Library Implementation File
*/

#include "Draw.h"
#include <stdlib.h>
#include <time.h>

void Draw(int x, int y, SDL_Plotter& g, std::ifstream& in,
          std::string toDraw, bool flip)
{
    int row, col;
    int R,G,B;

    in.open(toDraw.c_str());

    if(in.is_open())
    {
      in >> row >> col;

      if(flip)
      {
        for(int i = 0; i < row; i++)
        {
          for(int j = col; j > 0; j--)
          {
            in >> R >> G >> B;
            if(R == 255 && G == 255 && B == 255)
            {}
            else
            {
              g.plotPixel(x + j, y + i, R, G, B);
            }
          }
        }
      }
      else
      {
        for(int i = 0; i < row; i++)
        {
          for(int j = 0; j < col; j++)
          {
            in >> R >> G >> B;
            if(R == 255 && G == 255 && B == 255)
            {}
            else
            {
              g.plotPixel(x + j, y + i, R, G, B);
            }
          }
        }
      }
      in.close();
    }
}

void modDraw(int x, int y, SDL_Plotter& g, std::ifstream& in,
          std::string toDraw, std::string modColor, bool flip)
{
    int row, col;
    int R,G,B;
    int lR, lG, lB, dR, dG, dB;   //modified values for R, G, and B in light
                                  //and dark

    if(modColor == "Fire")
    {
      dR = 207;
      dG = 16;
      dB = 26;
      lR = 227;
      lG = 132;
      lB = 36;
    }
    else if(modColor == "Water")
    {
      dR = 19;
      dG = 31;
      dB = 249;
      lR = 126;
      lG = 219;
      lB = 226;
    }
    else if(modColor == "Earth")
    {
      dR = 113;
      dG = 92;
      dB = 23;
      lR = 114;
      lG = 109;
      lB = 92;
    }
    else if(modColor == "Air")
    {
      dR = 86;
      dG = 218;
      dB = 48;
      lR = 237;
      lG = 237;
      lB = 107;
    }
    else
    {
      dR = dG = dB = 0;
      lR = lG = lB = 127;
    }

    in.open(toDraw.c_str());
    if(in.is_open())
    {
      in >> row >> col;

      if(flip)
      {
        for(int i = 0; i < row; i++)
        {
          for(int j = col; j > 0; j--)
          {
            in >> R >> G >> B;
            if(R == 255 && G == 255 && B == 255)
            {}
            else if(R == 127 && G == 127 && B == 127)
            {
              g.plotPixel(x + j, y + i, lR, lG, lB);
            }
            else if(R == 0 && G == 0 && B == 0)
            {
              g.plotPixel(x + j, y + i, dR, dG, dB);
            }
          }
        }
      }
      else
      {
        for(int i = 0; i < row; i++)
        {
          for(int j = 0; j < col; j++)
          {
            in >> R >> G >> B;
            if(R == 255 && G == 255 && B == 255)
            {}
            else if(R == 127 && G == 127 && B == 127)
            {
              g.plotPixel(x + j, y + i, lR, lG, lB);
            }
            else if(R == 0 && G == 0 && B == 0)
            {
              g.plotPixel(x + j, y + i, dR, dG, dB);
            }
          }
        }
      }

      in.close();
    }
}
