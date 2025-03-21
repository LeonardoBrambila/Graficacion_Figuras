#ifndef SDL2_ALGORITMOS_H
# define SDL2_ALGORITMOS_H

# include "SDL2/SDL.h"

void transformCoordinates(int *x, int *y);
void drawLine(SDL_Renderer* renderer, int x0, int y0, int x1, int y1);
void PlotPoint(SDL_Renderer* renderer, int xc, int yc, int x, int y);
void CircleSecondOrderDifference(SDL_Renderer* renderer, int xc, int yc, int r);
void draw4Pixels(SDL_Renderer* renderer, int x, int y);
void PointsElipse(SDL_Renderer* renderer, int xc, int yc, int x, int y);
void drawEllipse(SDL_Renderer* renderer, int xc, int yc, double a, double b);
void PlotPoint_PARABOLA(SDL_Renderer* renderer, int x, int y);
void drawParabola(SDL_Renderer* renderer, int p);
//void drawParabola(SDL_Renderer *renderer, int h, int k, int scale);
void print_pixel(SDL_Renderer* renderer, int x, int y, int x1, int y1);
void drawHyperbola(SDL_Renderer* renderer, int a, int b, int x1, int y1);


# endif