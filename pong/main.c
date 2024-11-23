// import required libraries
#include <SDL2/SDL.h>
#include <stdio.h>


int main(int argc, char* argv[]){
    // initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not be initialized, SDL error %s\n", SDL_GetError());
        return 1;
    } 

    //create window
    SDL_Window* window = SDL_CreateWindow("Pong game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    if (!window){
        printf("SDL WIndow could not be created, SDL Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        printf("Renderer could not be created, SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //game loop flag
    int quit = 0;

    //event handler
    SDL_Event e;

    // game loop
    while (!quit){
        //handle events
        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
        }

        // clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //render here

        //present the renderer
        SDL_RenderPresent(renderer);


    }


    //clean up and close
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();



    return (0);

}