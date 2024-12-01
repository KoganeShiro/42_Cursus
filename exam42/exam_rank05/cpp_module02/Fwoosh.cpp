
#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}


Fwoosh::Fwoosh(Fwoosh const &cpy) : ASpell(cpy.getName(), cpy.getEffects())
{
}

Fwoosh &Fwoosh::operator=(Fwoosh const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


Fwoosh::~Fwoosh()
{}

ASpell *Fwoosh::clone() const
{
    return (new Fwoosh(*this));
}
