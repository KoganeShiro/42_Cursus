

#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
    std::map < std::string, ATarget*> target;
public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const &target);
    ATarget* createTarget(std::string const &target);
};

