//
// Created by Cocks Kardeiz on 13/06/2026.
//

#include "Game.h"

#include <filesystem>
#include <SDL3/SDL_log.h>

#include "Services/TextureHandler.h"
#include "Services/Instances/ImagePart.h"

bool Game::running = false;

SDL_Renderer* Game::GetRenderer() {
    if (running) {
        return Application::ApplicationRenderer;
    }
    return nullptr;
}

Game::Game() {
    // sets the current path the root directory
    running = true;
    std::filesystem::current_path("../../");
    TextureHandler::PreloadTextures(Application::ApplicationRenderer);
};

Game::~Game() {
    TextureHandler::ClearTextures();
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Game ended");
};

void Game::Run() const {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Game Running");
    running = true;
    map->LoadMap("officialMap");
    ImagePart part = ImagePart();
    part.setImage(Image(std::string("Attack")))
    .ResizeImageAndPart(Vector2d(128, 128));
    part.setName("TestPart")
        .setAnchored(true)
        .setPosition(Vector2d(500, 500));
    // part.Check();
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_RenderClear(GetRenderer());
        part.Draw();
        SDL_RenderPresent(GetRenderer());
    }
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Game Stop Running");
}
