#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
  std::cout << this->name << ": My job here is done!" << std::endl;
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
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
  grim.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const &name)
{
  grim.forgetSpell(name);
}

void Warlock::launchSpell(std::string const &name, ATarget &target)
{
  ASpell *spell = grim.createSpell(name);

  if (spell)
  {
    spell->launch(target);
    delete spell;
  }
}