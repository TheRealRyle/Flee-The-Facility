//
// Created by Cocks Kardeiz on 13/06/2026.
//

#include "Game.h"

#include <filesystem>
#include <SDL3/SDL_log.h>

Game::Game() {
    // sets the current path the root directory
    std::filesystem::current_path("../../");
};

Game::~Game() {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Game ended");
};

void Game::Run() {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Game Running");
    running = true;
    map->LoadMap("officialMap");
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }
}