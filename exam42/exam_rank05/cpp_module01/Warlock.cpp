#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day."
		<< std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!"
		<< std::endl; 
}

void	Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void	Warlock::setTitle(std::string const &title)
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

void	Warlock::learnSpell(ASpell *spell)
{
    this->library[spell->getName()] = spell;
}

void	Warlock::forgetSpell(std::string spellName)
{
    this->library.erase(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget const &target)
{
    if (this->library.find(spellName) != this->library.end()) {
        target.getHitBySpell(*this->library[spellName]);
    }
}

/*
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
*/
