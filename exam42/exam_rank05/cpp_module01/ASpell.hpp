
#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell(std::string const &name, std::string const &effect);
		ASpell(ASpell const &cpy);
		ASpell &operator=(ASpell const &cpy);
		virtual ~ASpell();

		std::string	getName() const;
		std::string	getEffects() const;
		virtual ASpell	*clone() const = 0;
		void	launch(ATarget const &target) const;

};
