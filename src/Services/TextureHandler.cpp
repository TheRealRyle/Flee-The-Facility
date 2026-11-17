//
// Created by Cocks Kardeiz on 24/09/2026.
//

#include "TextureHandler.h"
#include <SDL3_image/SDL_image.h>
#include <filesystem>
#include "../Shared/StringFunctions.h"

struct SDLTextureDeleter {
    std::string filepath;
    void operator()(SDL_Texture* texture) const {
        SDL_Log("destroying SDL_Texture: %s", filepath.c_str());
        SDL_DestroyTexture(texture);
    }
};

std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> TextureHandler::Textures = {};
std::unordered_map<std::string, std::string> TextureHandler::FilepathToName = {};
std::unordered_map<std::string, std::string> TextureHandler::NameToFilepath = {};

std::weak_ptr<SDL_Texture> TextureHandler::CreateTexture(SDL_Renderer* ren, const char *filepath)
{
    auto tex = std::shared_ptr<SDL_Texture>(
        IMG_LoadTexture(ren, filepath),
        SDLTextureDeleter{
            .filepath = filepath,
        }
    );

    if (!tex) {
        throw std::runtime_error("Failed to load texture");
    }

    // Set the name of the texture to just the file name, with texture information stripped out
    const auto fp = std::string(filepath);
    const auto lastSlash = fp.find_last_of('/');
    const auto fpSlash = fp.substr(lastSlash + 1, fp.size() - lastSlash);
    const auto tokens = StringFunctions::split(fpSlash, "_");
    const auto id = !tokens.empty() ? tokens[0] : fp;

    // add the texture to the list of textures
    Textures.insert({id, tex}); // for finding by name
    Textures.insert({fp, tex}); // for finding by filepath

    // mapping purposes
    FilepathToName.insert({fp, id});
    NameToFilepath.insert({id, fp});

    SDL_Log("Loaded %s as %s", fp.c_str(), id.c_str());

    return tex;
}

void TextureHandler::DestroyTexture(const char* filepath) {
    Textures.erase(std::string(filepath));
}

std::weak_ptr<SDL_Texture> TextureHandler::GetTexture(SDL_Renderer* ren, const char *filepath) {
    if (const auto stringPath = std::string(filepath); Textures.contains(stringPath))
        return Textures.at(stringPath);
    return CreateTexture(ren, filepath);
}

bool TextureHandler::GetTextureFromName(const std::string& name, std::weak_ptr<SDL_Texture>& tex) {
    if (Textures.contains(name)) {
        tex = Textures.at(name);
        return true;
    }
    tex = Textures["Empty"];
    return false;
}

void TextureHandler::PreloadTextures(SDL_Renderer* ren) {
    const auto path = std::filesystem::path("ASSETS/RAW");
    for (const auto& file : (std::filesystem::directory_iterator(path)))
    {
        SDL_Log("Loading %s", file.path().string().c_str());
        const auto stringPath = file.path().string();
        const auto filepath = stringPath.c_str();
        CreateTexture(ren, filepath);
    }
}

void TextureHandler::ClearTextures() {
    Textures.clear(); // this will remove all refrences to the textures, which will initiate the cleanup of all the textures
    FilepathToName.clear();
    NameToFilepath.clear();
}

