#pragma once

#include <memory>
#include "attachments.h"

/**
 * The M16 base class: declares common rifle logic (getMass, shootAtTarget),
 * plus the "factory methods" (createScope, createSecondaryWeapon, createCamouflage)
 * that subclasses override to provide different attachments.
 */
class M16 {
public:
    M16(std::unique_ptr<Scope> scope, 
        std::unique_ptr<SecondaryWeapon> secondaryWeapon, 
        std::unique_ptr<Camouflage> camouflage);

    virtual ~M16();

    // Common logic for all M16 rifles
    double getMass() const;
    void shootAtTarget(double x, double y) const;

    M16(const M16&) = delete;
    M16(M16&&) = delete;
    M16& operator=(const M16&) = delete;


protected:
    // Factory Methods -- must be overridden by concrete subclasses
    virtual std::unique_ptr<Scope> createScope() const = 0;
    virtual std::unique_ptr<SecondaryWeapon> createSecondaryWeapon() const = 0;
    virtual std::unique_ptr<Camouflage> createCamouflage() const = 0;

private:
    // The rifle holds unique ownership of these attachments
    std::unique_ptr<Scope> scope_;
    std::unique_ptr<SecondaryWeapon> secondary_;
    std::unique_ptr<Camouflage> camo_;
};

//--------------------------------------
// Concrete M16 variants
//--------------------------------------
class DefaultM16 : public M16 {
public:
    DefaultM16();
    
protected:
    std::unique_ptr<Scope> createScope() const override;
    std::unique_ptr<SecondaryWeapon> createSecondaryWeapon() const override;
    std::unique_ptr<Camouflage> createCamouflage() const override;
};

class JungleM16 : public M16 {
public:
    JungleM16();
protected:
    std::unique_ptr<Scope> createScope() const override;
    std::unique_ptr<SecondaryWeapon> createSecondaryWeapon() const override;
    std::unique_ptr<Camouflage> createCamouflage() const override;
};
