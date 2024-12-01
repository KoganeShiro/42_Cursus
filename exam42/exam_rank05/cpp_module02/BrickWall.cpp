
#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}


BrickWall::BrickWall(BrickWall const &cpy) : ATarget(cpy.getType())
{
}

BrickWall &BrickWall::operator=(BrickWall const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


BrickWall::~BrickWall()
{}

ATarget *BrickWall::clone() const
{
    return (new BrickWall(*this));
}
