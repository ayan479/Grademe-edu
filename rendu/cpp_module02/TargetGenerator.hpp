#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *> targets;

        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *Target);
        void forgetTargetType(std::string const &name);
        ATarget *createTarget(std::string const &name);
};