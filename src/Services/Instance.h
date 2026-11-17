//
// Created by Cocks Kardeiz on 24/09/2026.
//

#ifndef CPPGAME_INSTANCE_H
#define CPPGAME_INSTANCE_H
#include "../Vector2d.h"
#include <string>

#include "Image.h"

typedef enum INSTANCE_TYPE {
    PART,
    NONE,
} INSTANCE_TYPE;

class Instance {
    public:
    virtual INSTANCE_TYPE GetInstanceType();
    virtual ~Instance();
    virtual void Draw() = 0;
    Instance();

    Instance& setPosition(float x, float y);
    Instance& setPosition(const Vector2d& position);
    Instance& setSize(float x, float y);
    Instance& setSize(const Vector2d& size);
    Instance& setMass(float mass);
    Instance& setAnchored(bool anchored);
    Instance& setName(const std::string& name);

    Vector2d& getPosition();
    Vector2d& getSize();
    float& getMass();
    bool& isAnchored();
    std::string& getName();
    std::string& getUUID();

private:
    INSTANCE_TYPE type = NONE;
    Vector2d Position {};
    Vector2d Size {};
    float Mass = 1.0f;
    bool Anchored = false;
    bool Massless = false;
    bool CanCollide = false;
    std::string Name {};
    std::string uuid;
};


#endif //CPPGAME_INSTANCE_H
