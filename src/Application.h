//
// Created by Cocks Kardeiz on 13/06/2026.
//

#ifndef CPPGAME_APPLICATION_H
#define CPPGAME_APPLICATION_H
#include <SDL3/SDL_render.h>

struct SDL_Window;

class Application {
public:
    Application();
    ~Application();
    static SDL_Renderer* ApplicationRenderer;
private:
    SDL_Window *window{};
    SDL_Renderer *renderer{};
};


#endif //CPPGAME_APPLICATION_H
