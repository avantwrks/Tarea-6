#ifndef DRAGON_H
#define DRAGON_H

#include "MagicalCreature.h"

class Dragon : public MagicalCreature {
public:
    Dragon(const std::string& name, int health, int attackPower, int defense);
};

#endif // DRAGON_H
