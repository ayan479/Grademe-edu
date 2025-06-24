#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &name)
{
    spells.erase(name); // Simple erase without delete
}

ASpell *SpellBook::createSpell(std::string const &name)
{
    if (spells.find(name) != spells.end())
        return spells[name]->clone(); // Return a clone for safety
    return NULL;
}

// void SpellBook::learnSpell(ASpell *spell)
// {
//     if (spell)
//         spells[spell->getName()] = spell;
// }

// void SpellBook::forgetSpell(std::string name)
// {
//     if (spells.find(name) != spells.end())
//         spells.erase(spells.find(name));
// }


// ASpell *SpellBook::createSpell(std::string const &name)
// {
//     ASpell *tmp = NULL;
//     if (spells.find(name) != spells.end())
//         tmp = spells[name];
//     return tmp;
// }
