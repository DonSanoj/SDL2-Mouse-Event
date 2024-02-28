#include <vector>
#include <SDL2/SDL.h>
#include <iostream>

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
        }
    }
    

    return 0;
}