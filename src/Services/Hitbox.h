//
// Created by Cocks Kardeiz on 18/09/2026.
//

#ifndef CPPGAME_HITBOX_H
#define CPPGAME_HITBOX_H
#include "../Vector2d.h"
#include "Instances/Part.h"

namespace Service {
    class Hitbox: Part {
        public:
            Hitbox(Vector2d position, Vector2d size);
    };
} // Service

#endif //CPPGAME_HITBOX_H
