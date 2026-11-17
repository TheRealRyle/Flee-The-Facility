//
// Created by Cocks Kardeiz on 13/06/2026.
//

#ifndef CPPGAME_GAME_H
#define CPPGAME_GAME_H
#include "Application.h"
#include "Map.h"

class Game {
    Application application = Application();
    std::unique_ptr<Map> map = std::make_unique<Map>();
public:
    static bool running;
    static SDL_Renderer* GetRenderer();

    Game();
    ~Game();

    void Run() const;
};

#endif //CPPGAME_GAME_H
