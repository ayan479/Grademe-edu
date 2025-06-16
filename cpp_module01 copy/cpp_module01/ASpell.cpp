#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(std::string const &name, std::string const & effects) : name(name), effects(effects)
{}

ASpell::~ASpell()
{

}

ASpell::ASpell(ASpell const &other)
{
    *this = other;
}

ASpell& ASpell::operator=(ASpell const &other)
{
    this->name = other.name;
    this->effects = other.effects;
    
    return *this;
}

