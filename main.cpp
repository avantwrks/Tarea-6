#include <iostream>
#include <vector>
#include <sstream>
#include "Dragon.h"
#include "Hada.h"

int main() {
    std::vector<MagicalCreature*> criaturas;
    std::string linea;

    while (std::getline(std::cin, linea)) {
        std::stringstream ss(linea);
        std::string comando;
        ss >> comando;

        if (comando == "CREA_DRAGON") {
            std::string nombre;
            int vida, ataque, defensa;
            ss >> nombre >> vida >> ataque >> defensa;
            criaturas.push_back(new Dragon(nombre, vida, ataque, defensa));
        }
        else if (comando == "CREA_HADA") {
            std::string nombre;
            int vida, ataque, defensa;
            ss >> nombre >> vida >> ataque >> defensa;
            criaturas.push_back(new Hada(nombre, vida, ataque, defensa));
        }
        else if (comando == "MOSTRAR") {
            for (auto criatura : criaturas) {
                criatura->showStatus();
            }
        }
        else if (comando == "ATACA") {
            std::string atacante, objetivo;
            int poder;
            ss >> atacante >> objetivo >> poder;

            MagicalCreature* atacador = nullptr;
            MagicalCreature* victima = nullptr;

            for (auto criatura : criaturas) {
                if (criatura->getName() == atacante) atacador = criatura;
                if (criatura->getName() == objetivo) victima = criatura;
            }

            if (atacador && victima) {
                atacador->attack(victima, poder);
            }
        }
        else if (comando == "SALIR") {
            break;
        }
        else {
            std::cout << "Opcion invalida." << std::endl;
        }
    }

    for (auto criatura : criaturas) {
        delete criatura;
    }

    return 0;
}
