//
// Created by Cocks Kardeiz on 13/06/2026.
//

#include "Application.h"
#include <stdexcept>
#include <SDL3/SDL.h>

SDL_Renderer* Application::ApplicationRenderer;

Application::Application()
{
    if (!SDL_CreateWindowAndRenderer("Game", 800, 800, SDL_WINDOW_FULLSCREEN, &window, &renderer))
        throw std::runtime_error("Failed to create window");

    ApplicationRenderer = renderer;
    if (ApplicationRenderer == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INVALID, "RENDER FRIED");
    } else
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "RENDER GOOD");
}

Application::~Application()
= default;