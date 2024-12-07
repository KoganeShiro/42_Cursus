
#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
    std::string type;

public:
    ATarget(std::string const &type);
    virtual ~ATarget();
    std::string getType() const;

    virtual ATarget *clone() const = 0;
    void getHitBySpell(ASpell const &spell);

};

