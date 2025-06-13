#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(std::string const & name, std::string const & effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell & ASpell::operator= (ASpell const & as)
{
	this->name = as.name;
	this->effects = as.effects;
	return (*this);
}

std::string const & ASpell::getName() const
{
	return (this->name);
}

std::string const & ASpell::getEffects() const
{
	return (this->effects);
}

// ASpell has a constructor that takes its name and its effects, in that order.
ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

// This one will simply call the getHitBySpell of the passed object, passing the current instance as parameter.

void ASpell::launch(ATarget const & at_ref) const
{
	at_ref.getHitBySpell(*this);
}
