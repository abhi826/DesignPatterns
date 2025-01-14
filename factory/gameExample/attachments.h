#pragma once

#include <string>

//--------------------------------------
// 1) Attachment Interfaces
//--------------------------------------
class Scope {
public:
    Scope() = default;
    virtual ~Scope() = default;
    virtual double mass() const = 0;
    virtual std::string info() const = 0;

    Scope(const Scope&) = delete;
    Scope(Scope&&) = delete;
    Scope& operator=(const Scope&) = delete;
    Scope& operator=(Scope&&) = delete;
};

class SecondaryWeapon {
public:
    SecondaryWeapon() = default;
    virtual ~SecondaryWeapon() = default;
    virtual double mass() const = 0;
    virtual std::string info() const = 0;

    SecondaryWeapon(const SecondaryWeapon&) = delete;
    SecondaryWeapon(SecondaryWeapon&&) = delete;
    SecondaryWeapon& operator=(const SecondaryWeapon&) = delete;
    SecondaryWeapon& operator=(SecondaryWeapon&&) = delete;
};

class Camouflage {
public:
    Camouflage() = default;
    virtual ~Camouflage() = default;
    virtual double mass() const = 0;
    virtual std::string info() const = 0;

    Camouflage(const Camouflage&) = delete;
    Camouflage(Camouflage&&) = delete;
    Camouflage& operator=(const Camouflage&) = delete;
    Camouflage& operator=(Camouflage&&) = delete;
};

//--------------------------------------
// 2) Concrete Scopes
//--------------------------------------
class StandardScope : public Scope {
public:
    double mass() const override;
    std::string info() const override;
};

class NightVisionScope : public Scope {
public:
    double mass() const override;
    std::string info() const override;
};

//--------------------------------------
// 3) Concrete Secondary Weapons
//--------------------------------------
class Bayonet : public SecondaryWeapon {
public:
    double mass() const override;
    std::string info() const override;
};

class GrenadeLauncher : public SecondaryWeapon {
public:
    double mass() const override;
    std::string info() const override;
};

//--------------------------------------
// 4) Concrete Camouflage
//--------------------------------------
class DesertCamo : public Camouflage {
public:
    double mass() const override;
    std::string info() const override;
};

class JungleCamo : public Camouflage {
public:
    double mass() const override;
    std::string info() const override;
};
