#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}


Polymorph::Polymorph(Polymorph const &cpy) : ASpell(cpy.getName(), cpy.getEffects())
{
}

Polymorph &Polymorph::operator=(Polymorph const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


Polymorph::~Polymorph()
{}

ASpell *Polymorph::clone() const
{
    return (new Polymorph(*this));
}
