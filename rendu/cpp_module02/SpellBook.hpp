#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
    private:
        std::map<std::string, ASpell *> spells;

        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &name);
        ASpell *createSpell(std::string const &name);
};