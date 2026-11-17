//
// Created by Cocks Kardeiz on 24/09/2026.
//

#ifndef CPPGAME_IMAGE_H
#define CPPGAME_IMAGE_H
#include <SDL3/SDL_rect.h>

#include "TextureHandler.h"

struct Vector2d;

struct ImageDrawData {
    SDL_Texture *texture;
    SDL_FRect src;
    SDL_FRect dst;
} typedef ImgDrawData;

class Image {
    std::weak_ptr<SDL_Texture> tex;
    const char* content{}; // filepath of the image
    std::string name; // name of the image

    void ParseImageData();

    protected:
    int width {};
    int height {};
    int sprites {};
    int currentSprite {};
    float drawWidth {};
    float drawHeight {};

    public:
    void GetDrawData(ImgDrawData &data, const Vector2d& position) const;
    void NextSprite();
    explicit Image();
    explicit Image(const char* filepath);
    explicit Image(const std::string &imageName);

    void SetImageSize(int newWidth, int newHeight);
    void SetImageDrawSize(const Vector2d& newSize);
    bool isAnimated{};
    void UpdateContent(const char *filepath);
    int FPS{};
};


#endif //CPPGAME_IMAGE_H
