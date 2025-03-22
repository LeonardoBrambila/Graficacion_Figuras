#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

void print_pixel(SDL_Renderer* renderer, int x, int y, int x1, int y1)
{
    SDL_RenderDrawPoint(renderer, x1 + x, y1 + y);
    SDL_RenderDrawPoint(renderer, x1 + x, y1 - y);
    SDL_RenderDrawPoint(renderer, x1 - x, y1 - y);
    SDL_RenderDrawPoint(renderer, x1 - x, y1 + y);
}

void drawHyperbola(SDL_Renderer* renderer, int a, int b, int x1, int y1)
{
    a = abs(a);
    b = abs(b);
    int x = a;
    int y = 0;
    int d = 2 * a * a - 2 * a * b * b - b * b;
    
    while(y <= (b * b * x) / (a * a))
    //while ((x * x) * (b * b) <= (y * y) * (a * a) + (a * a * b * b))
    {
        print_pixel(renderer, x, y, x1, y1);
        if(d < 0) d += 2 * a * a * (2 * y + 3);
        else
        {
            d += 2 * a * a * (2 * y + 3) - 4 * b * b * (x + 1);
            x++;
        }
        y++;
    }
    
    int init = 100;
    while(init--)
    {
        if(d < 0) d += 2 * b * b * (3 + 2 * x);
        else
        {
            d += 2 * b * b * (3 + 2 * x) - 4 * a * a * (y + 1);
            y++;
        }
        x++;
        print_pixel(renderer, x, y, x1, y1);
    }
}