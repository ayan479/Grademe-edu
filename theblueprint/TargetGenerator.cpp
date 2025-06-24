#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        targets[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
    if (targets.find(name) != targets.end())
        targets.erase(targets.find(name));
}


ATarget *TargetGenerator::createTarget(std::string const &name)
{
    ATarget *tmp = NULL;
    if (targets.find(name) != targets.end())
        tmp = targets[name];
    return tmp;
}
