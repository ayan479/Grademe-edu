#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const& title) : name(name), title(title)
{
 std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const
{
    return (this->name);
}

std::string const &Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
    this->title = title;
} 

void Warlock::introduce() const{
     std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
        spells[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string name)
{
    if (spells.find(name) != spells.end())
        spells.erase(spells.find(name));
}

void Warlock::launchSpell(std::string name, ATarget const &target)
{
    if (spells.find(name) != spells.end())
        spells[name]->launch(target);
}


