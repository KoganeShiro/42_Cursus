#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void	SpellBook::learnSpell(ASpell *spell)
{
    if (spell) {
        this->library[spell->getName()] = spell->clone();
    }
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
    this->library.erase(spellName);
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
    if (this->library.find(spellName) != this->library.end()) {
        return (this->library[spellName]);
    }
    return (NULL);
}
