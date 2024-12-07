

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;


class Fwoosh : public ASpell
{

public:
    Fwoosh();
    ~Fwoosh();

    ASpell *clone() const;
};
