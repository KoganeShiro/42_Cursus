
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title), spellBook(new SpellBook())
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
        this->spellBook->learnSpell(spell);
    }
}


void    Warlock::forgetSpell(std::string spellName)
{
        this->spellBook->forgetSpell(spellName);
}


void    Warlock::launchSpell(std::string spellName, ATarget &target)
{
    if (this->spellBook->createSpell(spellName)) {
        this->spellBook->createSpell(spellName)->launch(target);
    }
}


//c++ -Wall -Werror -Wextra Warlock.cpp ATarget.cpp ASpell.cpp Fwoosh.cpp Dummy.cpp Fireball.cpp Polymorph.cpp TargetGenerator.cpp SpellBook.cpp BrickWall.cpp

// int main()
// {
//   Warlock richard("Richard", "foo");
//   richard.setTitle("Hello, I'm Richard the Warlock!");
//   BrickWall model1;

//   Polymorph* polymorph = new Polymorph();
//   TargetGenerator tarGen;

//   tarGen.learnTargetType(&model1);
//   richard.learnSpell(polymorph);

//   Fireball* fireball = new Fireball();

//   richard.learnSpell(fireball);

//   ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

//   richard.introduce();
//   richard.launchSpell("Polymorph", *wall);
//   richard.launchSpell("Fireball", *wall);
// }