#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

//dibujar un punto y las simetrias en los 8 octantes
void PlotPoint(SDL_Renderer* renderer, int xc, int yc, int x, int y)
{
    int screenX, screenY;

    screenX = xc + x + 400;
    screenY = -(yc + y) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//1

    screenX = xc - x + 400;
    screenY = -(yc + y) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//2

    screenX = xc + x + 400;
    screenY = -(yc - y) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//3

    screenX = xc - x + 400;
    screenY = -(yc - y) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//4

    screenX = xc + y + 400;
    screenY = -(yc + x) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//5

    screenX = xc - y + 400;
    screenY = -(yc + x) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//6

    screenX = xc + y + 400;
    screenY = -(yc - x) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//7

    screenX = xc - y + 400;
    screenY = -(yc - x) + 400;
    SDL_RenderDrawPoint(renderer, screenX, screenY);//8
}
/*
4F(x,y)
F(x,y)-1/4

dE = 3
dSE = -2r + 5

d0{dE = 3
    dSE = -2r + 5
do = F(1, r-1/2)

if(d < 0)
	d = d+dE
	dE = dE+2
	dsE = dsE+2
	x = x+1
else
	d = d+dsE
	dE = dE+2
	dsE = dse +4
	x = x+1
	y = y-1
Pintar8pixeles(x,y)
*/

//circunferencia usando el algoritmo de diferencia de segundo orden
/*
 * Algoritmo de diferencia de segundo orden para graficar una circunferencia.
 *
 * Parámetros:
 *   renderer -> Puntero al renderizador de SDL2.
 *   xc, yc -> Coordenadas del centro de la circunferencia.
 *   r -> Radio de la circunferencia.
 */
void CircleSecondOrderDifference(SDL_Renderer* renderer, int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;//Decision inicial
    int deltaE = 3;
    int deltaSE = 5 - 2 * r;
    //int delta2E = 2;
    //int delta2SE = 2;

    //Dibuja el primer grupo de puntos
    PlotPoint(renderer, xc, yc, x, y);

    //Ciclo que debe de iterar hasta que x llegue a y
    while(x < y)
    {
        //x++;
        if(p < 0)
        {
            p += deltaE;
            deltaE += 2;
            deltaSE += 2;
        }
        else
        {
            y--;
            p += deltaSE;
            deltaE += 2;
            deltaSE += 4;
        }
        x++;
        //dibuja las simetrias de la circuferencia
        PlotPoint(renderer, xc, yc, x, y);
    }
}