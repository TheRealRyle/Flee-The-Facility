//
// Created by Cocks Kardeiz on 20/10/2026.
//

#include "ImagePart.h"
#include <SDL3/SDL_log.h>
#include <format>
#include <SDL3/SDL_render.h>

#include "../../Game.h"

ImagePart::ImagePart()
    : image(Image())
{}

ImagePart::~ImagePart() {
    SDL_Log("Image: %s was deleted", getUUID().c_str());
}

void ImagePart::Check() {
    ImgDrawData data;
    image.GetDrawData(data, getPosition());
    SDL_Log("Image: %s was drawn (size %f; width %f)", getUUID().c_str(), data.dst.w, data.dst.h);
}


void ImagePart::Draw() {
    ImgDrawData data;
    image.GetDrawData(data, getPosition());
    // SDL_Log("Image: %s was drawn (size %f; width %f)", getUUID().c_str(), data.dst.w, data.dst.h);
    const auto succ = SDL_RenderTexture(Game::GetRenderer(), data.texture, &data.src, &data.dst);
    if (!succ) {
        SDL_Log("Failed to draw texture: %s", SDL_GetError());
    }
}

ImagePart& ImagePart::setImage(const Image& img) {
    image = img;
    return *this;
}

ImagePart & ImagePart::ResizeImage(const Vector2d &size) {
    image.SetImageDrawSize(size);
    return *this;
}

ImagePart & ImagePart::ResizeImageAndPart(const Vector2d &size) {
    image.SetImageDrawSize(size);
    setSize(size);
    return *this;
}


