
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
    std::cout <<
        this->getName() << ": This looks like another boring day."
    << std::endl;
}

Warlock::~Warlock()
{
    std::cout <<
        this->getName() << ": My job here is done!"
    << std::endl;
}

void    Warlock::setTitle(std::string const &title)
{
    this->title = title;
}
 
 
std::string Warlock::getName() const
{
    return (this->name);
}

std::string Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::introduce() const
{
    std::cout <<
        this->getName() << ": I am " << this->getName() << ", "
        << this->getTitle() << "!"
    << std::endl;
}

void    Warlock::learnSpell(ASpell *spell)
{
    if (spell) {
        this->lib[spell->getName()] = spell->clone();
    }
}


void    Warlock::forgetSpell(std::string spellName)
{
    if (this->lib.find(spellName) != this->lib.end()) {
        this->lib.erase(spellName);
    }
}


void    Warlock::launchSpell(std::string spellName, ATarget &target)
{
    if (this->lib[spellName]) {
        this->lib[spellName]->launch(target);
    }
}


//c++ -Wall -Werror -Wextra Warlock.cpp ATarget.cpp ASpell.cpp Fwoosh.cpp Dummy.cpp
// int main()
// {
//   Warlock richard("Richard", "the Titled");

//   Dummy bob;
//   Fwoosh* fwoosh = new Fwoosh();

//   richard.learnSpell(fwoosh);

//   richard.introduce();
//   richard.launchSpell("Fwoosh", bob);

//   richard.forgetSpell("Fwoosh");
//   richard.launchSpell("Fwoosh", bob);
// }