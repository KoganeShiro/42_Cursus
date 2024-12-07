
#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
    std::string name;
    std::string effects;

public:
    ASpell(std::string const &name, std::string const &effects);
    virtual ~ASpell();
    std::string getName() const;
    std::string getEffects() const;

    virtual ASpell *clone() const = 0;
    void   launch(ATarget &target) const;
};

