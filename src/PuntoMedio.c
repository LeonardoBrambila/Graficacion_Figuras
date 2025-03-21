#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
//#include "./inc/Algoritmos.h"

/*
 * Función para transformar coordenadas de un sistema cartesiano a la ventana de renderizado.
 * Se centra el origen en (400,400) y se invierte el eje Y.
 */
void transformCoordinates(int *x, int *y)
{
    *x += 400; 
    *y = 400 - *y; // cambia el eje 'y' y lo mueve al nuevo origen
}

// Algoritmo de punto medio para dibujar líneas
/*
 * Algoritmo de punto medio para dibujar líneas en un espacio rasterizado.
 * Utiliza SDL_RenderDrawPoint para graficar cada punto de la línea.
 *
 * Parámetros:
 *   renderer -> Puntero al renderizador de SDL2.
 *   x0, y0 -> Coordenadas iniciales de la línea.
 *   x1, y1 -> Coordenadas finales de la línea.
 */
void drawLine(SDL_Renderer* renderer, int x0, int y0, int x1, int y1)
{
    // Transformar coordenadas
    transformCoordinates(&x0, &y0);
    transformCoordinates(&x1, &y1);
    
    //Calculo de fiferencias
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    //int sx = (x0 < x1) ? 1 : -1;
    //int sy = (y0 < y1) ? 1 : -1;
    int d = dx - dy;//desicion para el parametro
    int sx, sy;

    //Desplazamiento en X
    if(x0 < x1) sx = 1;
    else sx = -1;

    //Desplazamiento en Y
    if(y0 < y1) sy = 1;
    else sy = -1;

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    while(1)
    {
        //int screenX = x0 + 400;
        //int screenY = -y0 + 400;
        //SDL_RenderDrawPoint(renderer, screenX, screenY);
        SDL_RenderDrawPoint(renderer, x0, y0);//pinta el pixel actual

        //Truncamiento
        if(x0 == x1 && y0 == y1) break;
        
        //determina el siguiente punto, con el punto actual
        int e2 = 2 * d;
        if(e2 > -dy)
        {
            d -= dy;
            x0 += sx;
        }
        if(e2 < dx)
        {
            d += dx;
            y0 += sy;
        }
    }
}