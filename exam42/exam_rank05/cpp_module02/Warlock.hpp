#pragma once
#include  <iostream>
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include "Fireball.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"

#define SPELL_NUMBER 10

class Warlock
{
	private:
		std::string name;
		std::string title;
		SpellBook	*spellBook;
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void	introduce() const;
		void	setTitle(std::string const &title);
		std::string getName() const;
		std::string getTitle() const;
		
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget const &target);

};
