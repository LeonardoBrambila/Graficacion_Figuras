#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 800
#define CENTER_X (WIDTH / 2)
#define CENTER_Y (HEIGHT / 2)

void PlotPoint_PARABOLA(SDL_Renderer* renderer, int x, int y, int p)
{
    if(p < 0)
    {
        SDL_RenderDrawPoint(renderer, CENTER_X + x, CENTER_Y + y); //cuadrante superior
        SDL_RenderDrawPoint(renderer, CENTER_X - x, CENTER_Y + y);
    }
    else
    {
        SDL_RenderDrawPoint(renderer, CENTER_X + x, CENTER_Y - y); //cuadrante inferior
        SDL_RenderDrawPoint(renderer, CENTER_X - x, CENTER_Y - y);
    }
}

void drawParabola(SDL_Renderer* renderer, int p)
{
    int x = 0;
    int y = 0;
    int absP = abs(p);
    int d = 1 - absP;
    int p2 = 2 * absP;
    int p4 = 2 * p2;

    //REGION1
    // si x < |p|
    while (x < absP && y <= CENTER_Y)
    {
        PlotPoint_PARABOLA(renderer, x, y, p);
        if (d >= 0)
        {
            y++;
            d -= p2;
        }
        x++;
        d += 2 * x + 1;
    }

    //REGION2
    if (d == 1) 
        d = 1 - p4;
    else 
        d = 1 - p2;

    while (y <= CENTER_Y)
    {
        PlotPoint_PARABOLA(renderer, x, y, p);
        if (d <= 0)
        {
            x++;
            d += 4 * x;
        }
        y++;
        d -= p4;
    }
}
