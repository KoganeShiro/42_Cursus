
#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ASpell;
class SpellBook;

class Warlock
{
private:
    std::string name;
    std::string title;
    SpellBook *spellBook;

public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    void    setTitle(std::string const &title);
    std::string getName() const;
    std::string getTitle() const;

    void introduce() const;

    void    learnSpell(ASpell *spell);
    void    forgetSpell(std::string spellName);
    void    launchSpell(std::string spellName, ATarget &target);
};
