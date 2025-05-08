#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Clase base
class MagicalCreature {
protected:
    string name;
    int health;
    int attackPower;
    int defensePower;

public:
    MagicalCreature(string n, int h, int atk, int def)
        : name(n), health(h), attackPower(atk), defensePower(def) {}

    virtual void showInfo() const {
        cout << "Nombre: " << name << ", Vida: " << health
             << ", Ataque: " << attackPower
             << ", Defensa: " << defensePower << endl;
    }

    virtual void attack(MagicalCreature* target, int power) {
        int damage = power - target->defensePower;
        if (damage < 0) damage = 0;
        target->health -= damage;
        if (target->health < 0) target->health = 0;
        cout << name << " ataca a " << target->name << " causando " << damage << " de dano." << endl;
    }

    string getName() const {
        return name;
    }

    virtual ~MagicalCreature() {}
};

// Subclases
class Dragon : public MagicalCreature {
public:
    Dragon(string n, int h, int atk, int def)
        : MagicalCreature(n, h, atk, def) {}

    void showInfo() const override {
        cout << "[Dragon] ";
        MagicalCreature::showInfo();
    }
};

class Hada : public MagicalCreature {
public:
    Hada(string n, int h, int atk, int def)
        : MagicalCreature(n, h, atk, def) {}

    void showInfo() const override {
        cout << "[Hada] ";
        MagicalCreature::showInfo();
    }
};

// Buscar criatura por nombre
MagicalCreature* findCreature(const string& name, const vector<MagicalCreature*>& creatures) {
    for (MagicalCreature* c : creatures) {
        if (c->getName() == name)
            return c;
    }
    return nullptr;
}

int main() {
    vector<MagicalCreature*> creatures;
    string line;

    while (true) {
        getline(cin, line);
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "CREA_DRAGON") {
            string name;
            int h, atk, def;
            ss >> name >> h >> atk >> def;
            creatures.push_back(new Dragon(name, h, atk, def));
        }
        else if (command == "CREA_HADA") {
            string name;
            int h, atk, def;
            ss >> name >> h >> atk >> def;
            creatures.push_back(new Hada(name, h, atk, def));
        }
        else if (command == "MOSTRAR") {
            for (MagicalCreature* c : creatures) {
                c->showInfo();
            }
        }
        else if (command == "ATACA") {
            string attackerName, targetName;
            int power;
            ss >> attackerName >> targetName >> power;

            MagicalCreature* attacker = findCreature(attackerName, creatures);
            MagicalCreature* target = findCreature(targetName, creatures);

            if (attacker && target && attacker != target) {
                attacker->attack(target, power);
            } else {
                cout << "Atacante o objetivo no valido.\n";
            }
        }
        else if (command == "SALIR") {
            cout << "Saliendo...\n";
            break;
        }
        else {
            cout << "Comando invalido.\n";
        }
    }

    // Liberar memoria
    for (MagicalCreature* c : creatures) {
        delete c;
    }

    return 0;
}
