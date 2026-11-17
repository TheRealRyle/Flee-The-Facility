//
// Created by Cocks Kardeiz on 24/09/2026.
//

#ifndef CPPGAME_PART_H
#define CPPGAME_PART_H
#include "../Instance.h"

class Part: public Instance {
    public:
    INSTANCE_TYPE GetInstanceType() override {
        return PART;
    };

    void Draw() override;

    ~Part() override = default;
};


#endif //CPPGAME_PART_H
