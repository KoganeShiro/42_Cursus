
#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : type(type)
{
}

ATarget::~ATarget()
{
}

std::string ATarget::getType() const
{
    return (this->type);
}


void ATarget::getHitBySpell(ASpell const &spell)
{
    std::cout << this->getType() << " has been " << spell.getEffects()
    << "!" << std::endl;
}
