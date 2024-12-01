
#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{

public:
    BrickWall();
    BrickWall(BrickWall const &cpy);
    BrickWall &operator=(BrickWall const &cpy);
    ~BrickWall();

    ATarget *clone() const;
};
