
#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ATarget;


class BrickWall : public ATarget
{

public:
    BrickWall();
    ~BrickWall();

    ATarget *clone() const;
};

