#include <vector>
#include <SDL.h>
#include <iostream>
#include <cstdlib> // Add missing include directive

int main() {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
    SDL_CreateWindowAndRenderer(2000, 2000, 0, &window, &renderer);
    SDL_Event event;

    SDL_Point current;

    std::vector<SDL_Point> vector_of_points;

    while (true)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                auto button = SDL_GetMouseState(&x, &y);

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    vector_of_points.emplace_back(x, y);
                }
            }
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&current.x, &current.y);
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_c){
                vector_of_points.clear();
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < vector_of_points.size() - 1; i++) {
            SDL_RenderDrawLine(renderer, vector_of_points[i].x, vector_of_points[i].y, vector_of_points[i + 1].x, vector_of_points[i + 1].y);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(150);
    }
    

    return 0;
}