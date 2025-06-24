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
    return this->name;
}

std::string const &Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(std::string const &title)
{
    this->title = title;
} 

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
    spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string name)
{
    spellBook.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const &target)
{
    ASpell *spell = spellBook.createSpell(name);
    if (spell)
    {
        spell->launch(target);
        // No delete here since we don't care about memory leaks
    }
}