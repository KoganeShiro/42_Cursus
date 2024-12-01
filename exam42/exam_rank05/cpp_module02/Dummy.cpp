
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}


Dummy::Dummy(Dummy const &cpy) : ATarget(cpy.getType())
{
}

Dummy &Dummy::operator=(Dummy const &cpy)
{
    if (this != &cpy) {
        *this = cpy;
    }
    return (*this);
}


Dummy::~Dummy()
{}

ATarget *Dummy::clone() const
{
    return (new Dummy(*this));
}
