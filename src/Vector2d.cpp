//
// Created by Cocks Kardeiz on 06/09/2026.
//

#include "Vector2d.h"

#include <valarray>

Vector2d::Vector2d()
    :x(0), y(0)
{}

Vector2d::Vector2d(float x, float y)
    :x(x), y(y)
{}

Vector2d Vector2d::Normalise(const Vector2d &vec) const {
    const auto magnitude = std::sqrt(x * x + y * y);
    return {x / magnitude, y / magnitude};
}

Vector2d & Vector2d::operator-=(const Vector2d &vec) {
    return *this - vec;
}

Vector2d & Vector2d::operator+=(const Vector2d &vec) {
    return *this + vec;
}

Vector2d & Vector2d::operator*=(const Vector2d &vec) {
    return *this * vec;
}

Vector2d & Vector2d::operator/=(const Vector2d &vec) {
    return *this / vec;
}

Vector2d & Vector2d::operator-(const Vector2d &vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2d & Vector2d::operator+(const Vector2d &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2d & Vector2d::operator*(const Vector2d &vec) {
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2d & Vector2d::operator/(const Vector2d &vec) {
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2d & Vector2d::operator*(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2d & Vector2d::operator*=(float scalar) {
    return *this * scalar;
}

Vector2d & Vector2d::operator/=(float scalar) {
    return *this / scalar;
}

Vector2d & Vector2d::operator/(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
