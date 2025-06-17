#pragma once 

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map <std::string, ASpell *> spells;

        SpellBook(SpellBook const& other);
        SpellBook &operator=(SpellBook const &other);
    public:
        SpellBook();        
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string name);
        ASpell* createSpell(std::string const &);
};
