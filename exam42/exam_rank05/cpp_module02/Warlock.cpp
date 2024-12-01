#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title), spellBook(new SpellBook())
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
    this->spellBook->learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spellName)
{
    this->spellBook->forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, ATarget const &target)
{
    if (this->spellBook->createSpell(spellName) != NULL) {
        this->spellBook->createSpell(spellName)->launch(target);
    }
}

/*
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;


  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
*/
