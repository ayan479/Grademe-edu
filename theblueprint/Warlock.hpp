#pragma once 

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
    std::string name;
    std::string title;
    SpellBook spellBook; // IMPORTANT: renamed from "SpellBook" to "spellBook" to avoid shadowing

    Warlock();
    Warlock(Warlock const& other);
    Warlock &operator=(Warlock const &other);
    
public:
    Warlock(std::string const & name, std::string const & title);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void setTitle(std::string const &title);

    void introduce() const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string name);
    void launchSpell(std::string name, ATarget const &target);
};