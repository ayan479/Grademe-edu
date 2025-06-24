#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
  if (target)
    targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
  if (targets.find(type) != targets.end())
    targets.erase(type);
}

ATarget *TargetGenerator::createTarget(std::string const &type)
{
    if (targets.find(type) != targets.end())
    {
        return targets[type]->clone();
    }
    return NULL;
}