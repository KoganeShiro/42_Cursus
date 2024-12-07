
#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget
{

public:
    Dummy();
    ~Dummy();

    ATarget *clone() const;
};

