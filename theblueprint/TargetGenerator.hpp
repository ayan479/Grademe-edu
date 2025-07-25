#pragma once 

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"

class TargetGenerator
{
    private:
        std::map <std::string, ATarget *> targets;

        TargetGenerator(TargetGenerator const& other);
        TargetGenerator &operator=(TargetGenerator const &other);
    public:
        TargetGenerator();        
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &target);
};
