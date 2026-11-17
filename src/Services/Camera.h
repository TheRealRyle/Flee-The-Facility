//
// Created by Cocks Kardeiz on 07/09/2026.
//

#ifndef CPPGAME_CAMERA_H
#define CPPGAME_CAMERA_H


class Vector2d;

class Camera {
public:
    Camera(float x, float y);
    Vector2d GetCameraPosition();

private:
    Vector2d& position;
};


#endif //CPPGAME_CAMERA_H
