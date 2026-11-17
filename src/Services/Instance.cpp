//
// Created by Cocks Kardeiz on 24/09/2026.
//

#include "Instance.h"
#include "../Shared/Utils.h"


INSTANCE_TYPE Instance::GetInstanceType() {
    return type;
}

Instance::~Instance() = default;


Vector2d & Instance::getPosition() {
    return Position;
}

Vector2d & Instance::getSize() {
    return Size;
}

float & Instance::getMass() {
    return Mass;
}

bool & Instance::isAnchored() {
    return Anchored;
}

std::string & Instance::getName() {
    return Name;
}

std::string & Instance::getUUID() {
    return uuid;
}

Instance::Instance() {
    uuid = Utils::GenerateUUID();
}

Instance & Instance::setPosition(float x, float y) {
    Position.x = x;
    Position.y = y;
    return *this;
}

Instance & Instance::setPosition(const Vector2d &position) {
    Position.x = position.x;
    Position.y = position.y;
    return *this;
}

Instance & Instance::setSize(float x, float y) {
    Size.x = x;
    Size.y = y;
    return *this;
}

Instance & Instance::setSize(const Vector2d &size) {
    Size.x = size.x;
    Size.y = size.y;
    return *this;
}

Instance & Instance::setMass(float mass) {
    Mass = mass;
    return *this;
}

Instance & Instance::setAnchored(bool anchored) {
    Anchored = anchored;
    return *this;
}

Instance & Instance::setName(const std::string &name) {
    Name = name;
    return *this;
}
