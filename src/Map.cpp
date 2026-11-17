//
// Created by Cocks Kardeiz on 20/06/2026.
//

#include "Map.h"
#include <SDL3_image/SDL_image.h>
#include <exception>
#include <filesystem>
#include <format>
#include "Application.h"
#include "Vector2d.h"

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
    switch (tmx_errno) {
        case E_UNKN:
            return tmx_strerr();
        case E_INVAL:
            return "Invalid argument, example: you passed NULL to tmx_load().";
        default:
            return tmx_strerr();
    }
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
    // auto layer = _map->ly_head;
    //
    // while (layer != nullptr) {
    //     /* render only visible layers */
    //     if (!layer->visible) {
    //         layer = layer->next;
    //         continue;
    //     }
    //
    //     for (int cell_y = 0; cell_y < _map->height; cell_y++)
    //     {
    //         for (int cell_x = 0; cell_x < _map->width; cell_x++)
    //         {
    //             // get the gid, allows us the get the current tile
    //             const auto cellNbr = (cell_y * _map->width) + cell_x;
    //             const auto gid = (layer->content.gids[cellNbr]) & TMX_FLIP_BITS_REMOVAL;
    //             const auto tile = _map->tiles[gid];
    //
    //             // verify current tile isn't empty
    //             if (tile == nullptr)
    //                 continue;
    //
    //             const auto ts = tile->tileset;
    //
    //             SDL_FRect src_rect; // image source
    //             SDL_FRect dest_rect; // render location
    //
    //             const auto tile_width = static_cast<float>(ts->tile_width);
    //             const auto tile_height = static_cast<float>(ts->tile_height);
    //
    //             // on recupere les coordonee du camera, car ou desine le tile actuelle en fonction d'ou ce trouve la camera
    //             Vector2d camPos = LocalPlayer->camera.GetCameraPosition();
    //             float cameraX = camPos.x;
    //             float cameraY = camPos.y;
    //             //application.player.GetCameraPosition(cameraX, cameraY);
    //
    //
    //             // recuperer l'image source + indiquer les coordonee d'affichage
    //             src_rect.x = (float)tile->ul_x;
    //             src_rect.y = (float)tile->ul_y;
    //             dest_rect.w = (float)tile_width  * SCALE ;
    //             dest_rect.h = (float)tile_height  * SCALE ;
    //             src_rect.w = (float)tile_width;
    //             src_rect.h = (float)tile_height;
    //             dest_rect.x = (cell_x * tile_width * SCALE) + cameraX ;
    //             dest_rect.y = ((cell_y + MAP_Y_OFFSET) * tile_height * SCALE) + cameraY;
    //
    //             // on cree la texture en fonction de l'image source (tileset ou le tile actuelle)
    //             SDL_Texture* tex = nullptr;
    //             if (tile->image && tile->image->resource_image) {
    //                 tex = (SDL_Texture*)tile->image->resource_image;
    //             }
    //             else if (ts->image && ts->image->resource_image) {
    //                 tex = (SDL_Texture*)ts->image->resource_image;
    //             }
    //
    //             // si on n'a pas pu cree le texture, on ne peut don't pas continuer.
    //             if (tex == nullptr) {
    //                 SDL_Log("Texture missing at gid=%u", gid);
    //                 continue;
    //             }
    //
    //             // on affiche l'image sur le canvas (texture)
    //             auto objectPos = Vector2d(dest_rect.x, dest_rect.y);
    //             auto objectSize = Vector2d(dest_rect.w * SCALE, dest_rect.h * SCALE);
    //             //                auto inverseCamPosOnX = camPos * Vector2d(1, 0);
    //
    //
    //             // affiche que les tile dans le viewport (que l'on peut voir)
    //             //                if (isObjectInView(camPos, objectPos, objectSize))
    //             SDL_RenderTexture(renderer, tex, &src_rect, &dest_rect);
    //         }
    //     }
    //     layer = layer->next;
    // }
}