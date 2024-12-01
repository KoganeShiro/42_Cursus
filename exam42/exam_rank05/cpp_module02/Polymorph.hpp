

#pragma once

#include "ASpell.hpp"


class Polymorph : public ASpell
{

public:
    Polymorph();
    Polymorph(std::string const &name, std::string const &effect);
    ~Polymorph();
    Polymorph(Polymorph const &cpy);
    Polymorph &operator=(Polymorph const &cpy);
    ASpell *clone() const;
};
