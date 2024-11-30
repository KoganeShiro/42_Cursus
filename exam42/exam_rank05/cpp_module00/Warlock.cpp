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

/*


int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}

*/
