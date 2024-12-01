
#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		ATarget(std::string const &type);
		ATarget(ATarget const &cpy);
		ATarget &operator=(ATarget const &cpy);
		virtual ~ATarget();

		std::string getType() const;
		virtual ATarget	*clone() const = 0;
		void	getHitBySpell(ASpell const &spell) const;

};
