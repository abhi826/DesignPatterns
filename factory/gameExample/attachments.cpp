#include "attachments.h"

//--------------------------------------
// StandardScope
//--------------------------------------
double StandardScope::mass() const {
    return 0.5;
}
std::string StandardScope::info() const {
    return "Standard Scope";
}

//--------------------------------------
// NightVisionScope
//--------------------------------------
double NightVisionScope::mass() const {
    return 0.7;
}
std::string NightVisionScope::info() const {
    return "Night Vision Scope";
}

//--------------------------------------
// Bayonet
//--------------------------------------
double Bayonet::mass() const {
    return 0.3;
}
std::string Bayonet::info() const {
    return "Bayonet";
}

//--------------------------------------
// GrenadeLauncher
//--------------------------------------
double GrenadeLauncher::mass() const {
    return 1.0;
}
std::string GrenadeLauncher::info() const {
    return "Grenade Launcher";
}

//--------------------------------------
// DesertCamo
//--------------------------------------
double DesertCamo::mass() const {
    return 0.1;
}
std::string DesertCamo::info() const {
    return "Desert Camo";
}

//--------------------------------------
// JungleCamo
//--------------------------------------
double JungleCamo::mass() const {
    return 0.1;
}
std::string JungleCamo::info() const {
    return "Jungle Camo";
}
