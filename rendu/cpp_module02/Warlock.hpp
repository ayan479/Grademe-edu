#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>

class Warlock
{
    private:
        std::string name;
        std::string title;
        SpellBook   grim;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;
        
        void setTitle(std::string const &title);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &name);
        void launchSpell(std::string const &name, ATarget &target);
        // ASpell *createSpell(std::string const &name);
};