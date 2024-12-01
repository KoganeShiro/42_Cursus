
#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget
{    
public:
    Dummy();
    Dummy(Dummy const &cpy);
    Dummy &operator=(Dummy const &cpy);
    ~Dummy();

    ATarget *clone() const;

};
