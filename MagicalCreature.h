#ifndef MAGICALCREATURE_H
#define MAGICALCREATURE_H

#include <string>

class MagicalCreature {
protected:
    std::string name;
    int health;
    int attackPower;
    int defense;

public:
    MagicalCreature(const std::string& name, int health, int attackPower, int defense);
    virtual ~MagicalCreature() = default;

    std::string getName() const;
    int getHealth() const;
    int getAttackPower() const;
    int getDefense() const;
    bool isDead() const;

    virtual void attack(MagicalCreature* target, int power);
    virtual void showStatus() const;
};

#endif // MAGICALCREATURE_H
