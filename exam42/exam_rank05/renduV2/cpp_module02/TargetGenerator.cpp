
#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget*target)
{
    if (target) {
        this->lib[target->getType()] = target->clone();
    }
}
void TargetGenerator::forgetTargetType(std::string const &target)
{
    if (this->lib.find(target) != this->lib.end()) {
        this->lib.erase(target);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    if (this->lib[target]) {
        return (this->lib[target]);
    }
    return (NULL);
}
