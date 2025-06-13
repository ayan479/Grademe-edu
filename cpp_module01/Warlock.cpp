// Add to the Warlock the following member functions:

// * learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
// * forgetSpell, takes a string corresponding a to a spell's name, and makes the
//   Warlock forget it. If it's not a known spell, does nothing.
// * launchSpell, takes a string (a spell name) and a reference to ATarget, that
//   launches the spell on the selected target. If it's not a known spell, does
//   nothing.

// You will need a new attribute to store the spells your Warlock knows. Several
// types fit the bill, it's up to you to choose the best one.

#include "Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

std::string const & Warlock::getName() const
{
    return (this->name);
}

std::string const & Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(std::string const & title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

//makes the Warlock learn a spell
//Remember: "Learn a spell, add it to the collection."
void Warlock::learnSpell(ASpell *as)
{
	if (as)
		s_arr[as->getName()] = as;
}

// makes the Warlock forget it. If it's not a known spell, does nothing.
// Remember: "Forget a spell, remove it from the collection."
void Warlock::forgetSpell(std::string sname)
{
	if (s_arr.find(sname) != s_arr.end())
		s_arr.erase(s_arr.find(sname));
}

// launches the spell on the selected target. If it's not a known spell, does nothing.
// Remember: "Launch a spell, if it exists, cast it on the target."
void Warlock::launchSpell(std::string sname, ATarget const & at_ref)
{
	if (s_arr.find(sname) != s_arr.end())
		s_arr[sname]->launch(at_ref);
}
