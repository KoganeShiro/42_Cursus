
#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ATarget;


class TargetGenerator
{
private:
    std::map < std::string, ATarget * > lib;
public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget*target);
    void forgetTargetType(std::string const &target);
    ATarget* createTarget(std::string const &target);
};
