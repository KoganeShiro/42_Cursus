
#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : type(type)
{}


ATarget::ATarget(ATarget const &cpy) : type(cpy.type)
{}

ATarget &ATarget::operator=(ATarget const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


ATarget::~ATarget()
{}

std::string	ATarget::getType() const
{
    return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout <<
        this->getType() << " has been " << spell.getEffects() << "!"
    << std::endl;
}
