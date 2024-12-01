#include "ASpell.hpp"

ASpell::ASpell(std::string const &name, std::string const &effect) : name(name), effects(effect)
{}


ASpell::ASpell(ASpell const &cpy) : name(cpy.getName()), effects(cpy.getEffects())
{}

ASpell &ASpell::operator=(ASpell const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


ASpell::~ASpell()
{}

std::string	ASpell::getName() const
{
    return (this->name);
}

std::string	ASpell::getEffects() const
{
    return (this->effects);
}


void	ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}
