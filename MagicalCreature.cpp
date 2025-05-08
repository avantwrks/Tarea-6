#include "MagicalCreature.h"
#include <iostream>
#include <algorithm>

MagicalCreature::MagicalCreature(const std::string& name, int health, int attackPower, int defense)
    : name(name), health(health), attackPower(attackPower), defense(defense) {}

std::string MagicalCreature::getName() const {
    return name;
}

int MagicalCreature::getHealth() const {
    return health;
}

int MagicalCreature::getAttackPower() const {
    return attackPower;
}

int MagicalCreature::getDefense() const {
    return defense;
}

bool MagicalCreature::isDead() const {
    return health <= 0;
}

void MagicalCreature::attack(MagicalCreature* target, int power) {
    int realDamage = std::max(0, power - target->defense);
    target->health = std::max(0, target->health - realDamage);
}

void MagicalCreature::showStatus() const {
    std::cout << "[" << name << ", " << health << ", " << attackPower << ", " << defense << "]";
    if (isDead()) {
        std::cout << " Muerto";
    }
    std::cout << std::endl;
}
