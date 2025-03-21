#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#define WIDTH 800
#define HEIGHT 800
#define CENTER_X (WIDTH / 2)
#define CENTER_Y (HEIGHT / 2)

void PlotPoint_PARABOLA(SDL_Renderer* renderer, int x, int y)
{
    SDL_RenderDrawPoint(renderer, CENTER_X + x, CENTER_Y + y); // Cuadrante superior
    SDL_RenderDrawPoint(renderer, CENTER_X - x, CENTER_Y + y); // Cuadrante inferior
}

void drawParabola(SDL_Renderer* renderer, int p)
{
    int x = 0, y = 0;
    int d = 1 - p; 
    int p2 = 2 * p;
    int p4 = 2 * p2;

    // Primera región: Mientras x < p (zona inicial)
    while (x < p && y <= CENTER_Y)
    {
        PlotPoint_PARABOLA(renderer, x, y);
        if (d >= 0)
        {
            y++;
            d -= p2;
        }
        x++;
        d += 2 * x + 1;
    }

    // Segunda región: cuando la curvatura se vuelve más vertical
    if (d == 1) 
        d = 1 - p4;
    else 
        d = 1 - p2;

    while (y <= CENTER_Y)
    {
        PlotPoint_PARABOLA(renderer, x, y);
        if (d <= 0)
        {
            x++;
            d += 4 * x;
        }
        y++;
        d -= p4;
    }
}