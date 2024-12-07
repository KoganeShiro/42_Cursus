
#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell*spell)
{
    if (spell) {
        this->lib[spell->getName()] = spell->clone();
    }
}
void SpellBook::forgetSpell(std::string const &spell)
{
    if (this->lib.find(spell) != this->lib.end()) {
        this->lib.erase(spell);
    }
}

ASpell* SpellBook::createSpell(std::string const &spell)
{
    if (this->lib[spell]) {
        return (this->lib[spell]);
    }
    return (NULL);
}
