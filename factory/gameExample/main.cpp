#include "M16.h"
#include <memory>
#include <iostream>

int main() {
    // Use the default M16
    std::unique_ptr<M16> defaultRifle = std::make_unique<DefaultM16>();
    std::cout << "Default M16 mass: " << defaultRifle->getMass() << " kg\n";
    defaultRifle->shootAtTarget(10.0, 25.0);

    // Use the jungle M16
    std::unique_ptr<M16> jungleRifle = std::make_unique<JungleM16>();
    std::cout << "Jungle M16 mass: " << jungleRifle->getMass() << " kg\n";
    jungleRifle->shootAtTarget(5.0, 12.0);

    return 0;
}
