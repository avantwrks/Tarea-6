#ifndef HADA_H
#define HADA_H

#include "MagicalCreature.h"

class Hada : public MagicalCreature {
public:
    Hada(const std::string& name, int health, int attackPower, int defense);
};

#endif // HADA_H
