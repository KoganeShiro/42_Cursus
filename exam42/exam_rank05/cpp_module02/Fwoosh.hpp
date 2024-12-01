#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh(Fwoosh const &cpy);
		Fwoosh &operator=(Fwoosh const &cpy);
		Fwoosh(std::string const &name, std::string const &effect);
		~Fwoosh();

		//Fwoosh *clone() const;
		ASpell *clone() const;

};
