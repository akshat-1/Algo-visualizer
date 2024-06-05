#include <SDL2/SDL.h>
#include<bits/stdc++.h>
using namespace std;

const int SCREEN_WIDTH=910;
const int SCREEN_HEIGHT=750;
SDL_Renderer* render= NULL;
void draw(int x =-1, int y=-1, int z =-1)
{
    SDL_PumpEvents();
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderClear(render);



}
int main()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout<<"ERROR"<<endl;
    }
        SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000,1000,0);
    while(true)
    {
        

    }
}

