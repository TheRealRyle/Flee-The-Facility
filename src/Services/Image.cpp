//
// Created by Cocks Kardeiz on 24/09/2026.
//

#include "Image.h"
#include "../Game.h"
#include "../Shared/StringFunctions.h"
#include <string_view>
#include <charconv>

#include "../Vector2d.h"

template<typename T>
bool parseNumber(std::string_view str, T& value)
{
    auto [ptr, ec] = std::from_chars(
        str.data(),
        str.data() + str.size(),
        value
    );

    return ec == std::errc{} && ptr == str.data() + str.size();
}

struct TextureBaseData {
    int width = 0.0;
    int height = 0.0;
    int sprites = 0;
};

void ReadTextureDataFromFilepath(const char *filepath, TextureBaseData& data) {
    const auto content = std::string(filepath);
    const auto tokens = StringFunctions::split(content, "_");
    for (const auto& token : tokens) {
        SDL_Log("Token: %s", token.c_str());
    }
    if (tokens.size() != 2)
        data.width = data.height = data.sprites = 0;
    else {
        const auto values = StringFunctions::split(tokens[1], "x");
        if (values.size() > 2) {
            parseNumber(values.at(0), data.width);
            parseNumber(values.at(1), data.height);
            if (values.size() > 2)
                parseNumber(values.at(2), data.sprites);
        }
    }
}


Image::Image() {
    TextureHandler::GetTextureFromName(std::string("Empty"), tex);
    content = "ASSETS/RAW/Empty.png";
    ParseImageData();
}

Image::Image(const char *filepath) {
    content = filepath;
    tex = TextureHandler::GetTexture(Game::GetRenderer(), filepath);
    ParseImageData();
}

Image::Image(const std::string &imageName) {
    if (!TextureHandler::GetTextureFromName(imageName, tex)) {
        content = "ASSETS/RAW/Empty.png";
        name = "Empty";
    }
    else {
        content = TextureHandler::NameToFilepath.at(imageName).c_str();
        name = imageName;
    }
    ParseImageData();
}

void Image::SetImageSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
}

void Image::SetImageDrawSize(const Vector2d &newSize) {
    drawWidth = newSize.x;
    drawHeight = newSize.y;
}

void Image::ParseImageData() {
    TextureBaseData data;
    ReadTextureDataFromFilepath(content, data);
    width = data.width;
    height = data.height;
    drawWidth = static_cast<float>(data.width);
    drawHeight = static_cast<float>(data.height);
    sprites = data.sprites;
    if (sprites > 0)
        isAnimated = true;
}

void Image::UpdateContent(const char *filepath) {
    content = filepath;
}

void Image::NextSprite() {
    currentSprite = (currentSprite + 1) % sprites;
}

void Image::GetDrawData(ImgDrawData &data, const Vector2d& position) const {

    // setup source rect
    data.src.x = static_cast<float>(currentSprite * width);
    data.src.y = static_cast<float>(currentSprite * height);
    data.src.w = static_cast<float>(width);
    data.src.h = static_cast<float>(height);

    // setup destination
    data.dst.x = position.x;
    data.dst.y = position.y;
    data.dst.w = static_cast<float>(drawWidth);
    data.dst.h = static_cast<float>(drawHeight);

    if (const auto shared_ptr = tex.lock())
        data.texture = shared_ptr.get();

}

