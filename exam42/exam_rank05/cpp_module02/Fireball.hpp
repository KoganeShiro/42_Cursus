

#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
    Fireball();
    Fireball(std::string const &name, std::string const &effect);
    ~Fireball();
    Fireball(Fireball const &cpy);
    Fireball &operator=(Fireball const &cpy);
    ASpell *clone() const;
};

