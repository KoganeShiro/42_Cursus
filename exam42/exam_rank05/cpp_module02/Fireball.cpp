#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}


Fireball::Fireball(Fireball const &cpy) : ASpell(cpy.getName(), cpy.getEffects())
{
}

Fireball &Fireball::operator=(Fireball const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


Fireball::~Fireball()
{}

ASpell *Fireball::clone() const
{
    return (new Fireball(*this));
}
