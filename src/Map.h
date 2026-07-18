//
// Created by Cocks Kardeiz on 20/06/2026.
//

#ifndef CPPGAME_MAP_H
#define CPPGAME_MAP_H
#include <tmx.h>
#include <string>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>

struct TmxMapDeleter {
    void operator()(tmx_map* map) const {
        if (map)
        {
            SDL_Log("freeing tmx_map");
            tmx_map_free(map);
        }
    }
};

class Map {
public:
    std::string currentMap;
    void LoadMap(const char* mapName);

    void DrawCurrentMap();

private:
    std::unique_ptr<tmx_map, TmxMapDeleter> _map = nullptr;
    std::weak_ptr<SDL_Renderer> _renderer;
};


#endif //CPPGAME_MAP_H
