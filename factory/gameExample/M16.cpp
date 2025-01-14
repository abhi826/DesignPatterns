#include "M16.h"
#include <iostream>

//--------------------------------------
// 1) M16 base class
//--------------------------------------
M16::M16(std::unique_ptr<Scope> scope, 
        std::unique_ptr<SecondaryWeapon> secondaryWeapon, 
        std::unique_ptr<Camouflage> camouflage)
    : scope_(std::move(scope))
    , secondary_(std::move(secondaryWeapon))
    , camo_(std::move(camouflage))
{
}

M16::~M16() = default;

double M16::getMass() const {
    static constexpr double baseRifleMass = 3.0;
    return baseRifleMass
           + scope_->mass()
           + secondary_->mass()
           + camo_->mass();
}

void M16::shootAtTarget(double x, double y) const {
    std::cout << "Shooting at (" << x << ", " << y << ") using:\n";
    std::cout << "  - " << scope_->info() << "\n";
    std::cout << "  - " << secondary_->info() << "\n";
    std::cout << "  - " << camo_->info() << "\n\n";
    // A real implementation might do a complex ballistic calculation.
}

//--------------------------------------
// 2) DefaultM16
//--------------------------------------
DefaultM16::DefaultM16():M16(DefaultM16::createScope(), 
                             DefaultM16::createSecondaryWeapon(), 
                             DefaultM16::createCamouflage())
{

}
std::unique_ptr<Scope> DefaultM16::createScope() const {
    return std::make_unique<StandardScope>();
}

std::unique_ptr<SecondaryWeapon> DefaultM16::createSecondaryWeapon() const {
    return std::make_unique<Bayonet>();
}

std::unique_ptr<Camouflage> DefaultM16::createCamouflage() const {
    return std::make_unique<DesertCamo>();
}

//--------------------------------------
// 3) JungleM16
//--------------------------------------
JungleM16::JungleM16():M16(JungleM16::createScope(), 
                           JungleM16::createSecondaryWeapon(), 
                           JungleM16::createCamouflage())
{


}
std::unique_ptr<Scope> JungleM16::createScope() const {
    return std::make_unique<NightVisionScope>();
}

std::unique_ptr<SecondaryWeapon> JungleM16::createSecondaryWeapon() const {
    return std::make_unique<GrenadeLauncher>();
}

std::unique_ptr<Camouflage> JungleM16::createCamouflage() const {
    return std::make_unique<JungleCamo>();
}
