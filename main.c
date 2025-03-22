#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 800
#define CENTER_X (WIDTH / 2)
#define CENTER_Y (HEIGHT / 2)
#include "./inc/Algoritmos.h"

void drawAxes(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 

    //eje x
    SDL_RenderDrawLine(renderer, 0, CENTER_Y, WIDTH, CENTER_Y);

    //eje y
    SDL_RenderDrawLine(renderer, CENTER_X, 0, CENTER_X, HEIGHT);
}

int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Crear ventana
    SDL_Window* window = SDL_CreateWindow(
        "Algoritmo Punto Medio",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN
    );
    if (!window) {
        fprintf(stderr, "Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Crear renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Error al crear el renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
//**********************************CIRCUFERENCIA****************************************** */
    /*int radio;
    printf("Teclea el radio de la circuferencia: ");
    scanf("%d", &radio);
    if(radio <= 0)
    {
        printf("ERROR. El valor de radio no puede ser negativo.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }*/
//*****************************************ELIPSE****************************************** */
    /*int a, b;
    printf("Teclea el semieje mayor (a) de la elipse: ");
    scanf("%d", &a);
    printf("Teclea el semieje menor (b) de la elipse: ");
    scanf("%d", &b);

    if(a <= 0 || b <= 0)
    {
        printf("ERROR. Los valores tecleados no son validos para una elipse.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }*/

//*****************************************PARABOLA****************************************** */
    //int p;
    //printf("Teclea el parametro de abertura de la parabola: ");
    //scanf("%d", &p);

    // Bucle principal
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        drawAxes(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, CENTER_X, CENTER_Y);
//**********************************RECTA****************************************** */
        //x0 = 400      x1 = 300
        //y0 = 400      y1 = 300
        //drawLine(renderer, 0, 0, 300, 300);
//**********************************CIRCUFERENCIA****************************************** */
        //CircleSecondOrderDifference(renderer,0, 0, radio);
        //CircleSecondOrderDifference(renderer,0, 0, 300);
//**********************************ELIPSE****************************************** */
        //if(a == b) _exit;
        //drawEllipse(renderer, CENTER_X, CENTER_Y, a, b);
        //drawEllipse(renderer, CENTER_X, CENTER_Y, 300, 150);
//**********************************PARABOLA****************************************** */
        //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        //drawParabola(renderer, p);
        //drawParabola(renderer, 200);
        
//**********************************HIPERBOLA****************************************** */
        //a = 50       b = 50
        drawHyperbola(renderer, 50, 50, CENTER_X, CENTER_Y);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
