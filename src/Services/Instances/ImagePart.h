//
// Created by Cocks Kardeiz on 20/10/2026.
//

#ifndef CPPGAME_IMAGEPART_H
#define CPPGAME_IMAGEPART_H
#include "Part.h"


class ImagePart final: public Part {
    public:
    ImagePart();
    ~ImagePart() override;
    void Draw() override;

    ImagePart& setImage(const Image& img);
    ImagePart& ResizeImage(const Vector2d& size);
    ImagePart& ResizeImageAndPart(const Vector2d& size);
    void Check();

    protected:
    Image image;
};


#endif //CPPGAME_IMAGEPART_H
