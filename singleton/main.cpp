#include <iostream>
#include <vector>
#include "pasture.h"

class Farm {
private:

    static Farm* instance;

    std::vector<Pasture*> pastures;

    Farm() = default;
public:

    static Farm* getInstance() {
        if (instance == nullptr) {
            instance = new Farm();
        }
        return instance;
    }

    void addPasture(Pasture* pasture) {
        pastures.push_back(pasture);
    }

    void removePasture(Pasture* pasture) {
        for (auto it = pastures.begin(); it != pastures.end(); ++it) {
            if (*it == pasture) {
                pastures.erase(it);
                return;
            }
        }
    }
    void printStatus() {
        std::cout << "Farm status:" << std::endl;
        for (auto pasture : pastures) {
            pasture->printStatus();
        }
        std::cout << std::endl;
    }
};

Farm* Farm::instance = nullptr;


int main() {
    Farm* farm = Farm::getInstance();
    auto* pasture1 = new Pasture();
    auto* pasture2 = new Pasture();
    farm->addPasture(pasture1);
    farm->addPasture(pasture2);

    farm->printStatus();

    pasture1->setGrassAvailability(false);

    {
        Farm* farm2 = Farm::getInstance();
        std::cout << "Farm2 is:" << std::endl;
        farm2->printStatus();
    }

    farm->printStatus();

    farm->removePasture(pasture1);

    farm->printStatus();

    return 0;
}
