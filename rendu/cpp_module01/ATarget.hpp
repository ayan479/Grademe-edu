#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp" // Include ASpell to use it in ATarget

class ASpell;

class ATarget
{
    protected:
        std::string type;

    public:
        ATarget();
        ATarget(std::string const &type);
        ATarget(ATarget const &other);
        ATarget& operator=(ATarget const &other);
        virtual ~ATarget();

        std::string const &getType() const;

        virtual ATarget* clone() const = 0;

        void getHitBySpell(ASpell const &spell) const;
};
