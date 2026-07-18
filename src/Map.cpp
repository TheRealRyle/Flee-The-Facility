//
// Created by Cocks Kardeiz on 20/06/2026.
//

#include "Map.h"
#include <SDL3_image/SDL_image.h>
#include <exception>
#include <filesystem>
#include <format>
#include "Application.h"

void* SDL_tex_loader(const char* path)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading texture from path: %s", path);

    SDL_Texture* tex = IMG_LoadTexture(Application::ApplicationRenderer, path);

    if (!tex)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "IMG_LoadTexture FAILED: %s", SDL_GetError());
        return nullptr;
    }

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Texture loaded: %p", static_cast<void*>(tex));

    return tex;
}

void SDL_tex_free(void* texture)
{
    if (texture)
        SDL_DestroyTexture(static_cast<SDL_Texture*>(texture));
}

const char* GetMapLoadErrorMessage() {
    auto error = tmx_errno;
    switch (error) {
        case E_UNKN:
            return tmx_strerr();
        case E_INVAL:
            return "Invalid argument, example: you passed NULL to tmx_load().";
        default:
            return tmx_strerr();
    }
    return nullptr;
}

void Map::LoadMap(const char *mapName) {
    try {
        tmx_img_load_func = SDL_tex_loader;
        tmx_img_free_func = SDL_tex_free;

        const auto pathString = std::format("{}/{}.tmx", "ASSETS/Maps", mapName);
        const std::filesystem::path path = pathString.c_str();
        const auto fileExists = std::filesystem::exists(path);
        if (!fileExists)
            throw std::runtime_error("Map file does not exist");
        const char* filePath = path.c_str();
        const auto loadedMap = tmx_load(filePath);
        if (loadedMap == nullptr) {
            const auto runTimeError = std::format("Failed to load map %s", GetMapLoadErrorMessage());
            throw std::runtime_error(runTimeError);
        }
        _map.reset(loadedMap);
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loaded map");
    } catch (std::exception &e) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL, "%s", e.what());
    }
}

void Map::DrawCurrentMap() {
    
}