//
// Created by Cocks Kardeiz on 24/09/2026.
//

#ifndef CPPGAME_TEXTUREHANDLER_H
#define CPPGAME_TEXTUREHANDLER_H
#include <functional>
#include <string>
#include <unordered_map>

struct SDL_Texture;
struct SDL_Renderer;

struct TextureDrawData {

};

class TextureHandler {
    public:
    static std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Textures;
    static std::unordered_map<std::string, std::string> NameToFilepath;
    static std::unordered_map<std::string, std::string> FilepathToName;

    static std::weak_ptr<SDL_Texture> CreateTexture(SDL_Renderer* ren,  const char* filepath);
    static void DestroyTexture(const char* filepath);
    static std::weak_ptr<SDL_Texture> GetTexture(SDL_Renderer* ren, const char* filepath);
    static bool GetTextureFromName(const std::string& name, std::weak_ptr<SDL_Texture>& tex);

    static void PreloadTextures(SDL_Renderer* ren);
    static void ClearTextures();
};


#endif //CPPGAME_TEXTUREHANDLER_H
