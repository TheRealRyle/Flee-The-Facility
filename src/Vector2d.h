//
// Created by Cocks Kardeiz on 06/09/2026.
//

#ifndef CPPGAME_VECTOR2D_H
#define CPPGAME_VECTOR2D_H


class Vector2d {
    public:
    Vector2d();
    Vector2d(float x, float y);

    Vector2d Normalise(const Vector2d &vec) const;
    Vector2d& operator-=(const Vector2d& vec);
    Vector2d& operator+=(const Vector2d& vec);
    Vector2d& operator*=(const Vector2d& vec);
    Vector2d& operator/=(const Vector2d& vec);
    Vector2d& operator-(const Vector2d& vec);
    Vector2d& operator+(const Vector2d& vec);
    Vector2d& operator*(const Vector2d& vec);
    Vector2d& operator/(const Vector2d& vec);
    Vector2d & operator*(float scalar);
    Vector2d& operator*=(float scalar);
    Vector2d& operator/=(float scalar);
    Vector2d& operator/(float scalar);

    float x, y;
};


#endif //CPPGAME_VECTOR2D_H
