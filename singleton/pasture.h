#include <iostream>

class Pasture {
private:

    bool isGrassAvailable;
public:
    Pasture() : isGrassAvailable(true) {

    }
    void setGrassAvailability(bool availability) {
        isGrassAvailable = availability;
    }
    void printStatus() const {
        std::cout << "Pasture status: grass is " << (isGrassAvailable ? "available" : "not available") << std::endl;
    }
};
