#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 800
#define CENTER_X (WIDTH / 2)
#define CENTER_Y (HEIGHT / 2)
#include "./inc/Algoritmos.h"

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
    //int radio;
    //printf("Teclea el radio de la circuferencia: ");
    //scanf("%d", &radio);
//*****************************************ELIPSE****************************************** */
    /*int a, b;
    printf("Teclea el semieje mayor (a) de la elipse: ");
    scanf("%d", &a);
    printf("Teclea el semieje menor (b) de la elipse: ");
    scanf("%d", &b);*/

    //int A = (a > b) ? a : b;
    //int B = (a > b) ? b : a;

    /*if(A == B)
    {
        printf("ERROR. Los valores tecleados no corresponden a una elipse, si no a una circuferencia.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    else if(B > abs((A / 2)))
    {
        printf("ERROR. EL UMBRAL ES DEMASIADO GRANDE. 'b' debe ser menor o igual que la mitad de 'a'.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }*/

//*****************************************PARABOLA****************************************** */
    int p;
    printf("Teclea el parametro de abertura de la parabolo: ");
    scanf("%d", &p);

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

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rojo para destacar el centro
        SDL_RenderDrawPoint(renderer, CENTER_X, CENTER_Y);
//**********************************RECTA****************************************** */
        //x0 = 400      x1 = 300
        //y0 = 400      y1 = 300
        //drawLine(renderer, 0, 0, 300, 300);

//**********************************CIRCUFERENCIA****************************************** */
        //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        //CircleSecondOrderDifference(renderer,0, 0, radio);
        //CircleSecondOrderDifference(renderer,0, 0, 200);
//**********************************ELIPSE****************************************** */
        //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        //if(a == b) _exit;
        //drawEllipse(renderer, CENTER_X, CENTER_Y, a, b);
        //drawEllipse(renderer, 0, 0, 300, 250);
//**********************************PARABOLA****************************************** */
        //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        drawParabola(renderer, p);
        //drawParabola(renderer, CENTER_X, CENTER_Y, p);
        //drawParabola(renderer, 200);
//**********************************HIPERBOLA****************************************** */
        //a = 100       b = 50
        //drawHyperbola(renderer, 50, 50, CENTER_X, CENTER_Y);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
