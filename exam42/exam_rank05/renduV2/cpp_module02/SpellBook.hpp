
#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ATarget;


class SpellBook
{
private:
    std::map < std::string, ASpell * > lib;
public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell*spell);
    void forgetSpell(std::string const &spell);
    ASpell* createSpell(std::string const &spell);
};
