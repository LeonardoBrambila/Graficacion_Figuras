#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
/*
//EJEMPLO
x = 0;
y = b;

d1 = b^2 - a^2 + a^2/4;

Pintar4Pixeles(x,y)
while(a^2 (y - 1/2) > b^2 (x + 1))
{
	//Este(E)
	if(d1 < 0)
		d1 = d1 + b^2(2x +3)
		//DeltaE b^2(2x +3)
		x = x+1
	//SuroEste(SE)
	else
		d1 = d1 + b^2(2x+3) + a^2(-2y + 2)
		//DeltaSE b^2(2x+3) + a^2(-2y + 2)
		x = x+1
		y = y-1
	Pintar4Pixeles(x,y)
}
d2 = b^2(x + (1/2))^2 + a^2(y-1)^2 - a^2b^2
while(y > 0)
{
	if(d2 > 0)
		//SE
		d2 = d2 + b^2(2x+2) + a^2(-2y+3)
		//DeltaSE b^2(2x+2) + a^2(-2y+3)
		x = x+1
		y = y-1
	else
		//S
		d2 = d2 + a^2(-2y+3)
		//DeltaS a^2(-2y+3)
		y = y-1
	Pintar4Pixeles(x,y)*/

//dibuja un punto y las simetrias en los 4 cuadrantes
void PointsElipse(SDL_Renderer* renderer, int xc, int yc, int x, int y)
{
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
}

//dibuja un elipse usando el algoritmo de punto medio
void drawEllipse(SDL_Renderer* renderer, int xc, int yc, double a, double b)
{
    double x = 0;
    double y = b;
    //int a2 = a * a;
    //int b2 = b * b;
    double d1 = (b*b)-(a*a*b)+(0.25*a*a);
    //int dx = 2 * b2 * x;
    //int dy = 2 * a2 * y;
    //int dx = (a2*(y-0.5) > b2*(x+1));

    //PointsElipse(renderer, xc, yc, x, y);

    //REGIN1
    while((a*a)*(y-0.5) > (b*b)*(x+1))
    {
        //E
        if(d1 < 0)
        {
            //x++;
            //dx += 2 * b2;
            d1 += (b*b)*(2*x+3);
        }
        //SE
        else
        {
            //x++;
            //y--;
            //dx += 2 * b2;
            //dy -= 2 * a2;
            d1 += (b*b)*(2*x+3)+(a*a)*(-2*y+2);
            y--;
        }
        x++;
        PointsElipse(renderer, xc, yc, x, y);
    }

    //REGION2
    double d2 = (b*b)*((x+0.5)*(x+0.5))+(a*a)*((y-1)*(y-1))-(a*a)*(b*b);
    while(y > 0)
    {
        //SE
        if(d2 < 0)
        {
            //y--;
            //dy -= 2 * a2;
            d2 += (b*b)*(2*x+2)+(a*a)*(-2*y+3);
            x++;
        }
        //S
        else
        {
            //y--;
            //x++;
            //dx += 2 * b2;
            //dy -= 2 * a2;
            d2 += (a*a)*(-2*y+3);
        }
        y--;
        PointsElipse(renderer, xc, yc, x, y);
    }
}

