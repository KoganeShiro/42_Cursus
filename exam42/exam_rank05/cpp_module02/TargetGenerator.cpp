#include "TargetGenerator.hpp"

/*
* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type
*/

TargetGenerator::TargetGenerator()
{
}


TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target) {
        this->target[target->getType()] = target->clone();
    }
}


void TargetGenerator::forgetTargetType(std::string const &target)
{
    this->target.erase(target);
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    if (this->target.find(target) != this->target.end()) {
        return (this->target[target]);
    }
    return (NULL);
}
