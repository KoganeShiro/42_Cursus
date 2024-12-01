#pragma once
#include  <iostream>
#include <map>
#include <string>
#include "Fwoosh.hpp"
#include "Dummy.hpp"

#define SPELL_NUMBER 10

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map < std::string, ASpell * > library;
	
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
