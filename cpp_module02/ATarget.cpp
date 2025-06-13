
#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::~ATarget() {}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget & ATarget::operator=(ATarget const & at)
{
	this->type = at.type;
	return (*this);
}

ATarget::ATarget(std::string type)
{
	this->type = type;
}

std::string ATarget::getType() const
{
	return (this->type);
}

// It will display :
// <TYPE> has been <EFFECTS>!
// <TYPE> is the ATarget's type, and <EFFECTS> is the return of the ASpell's getEffects function.
void ATarget::getHitBySpell(ASpell const & as_ref) const
{
	std::cout << this->type << " has been " << as_ref.getEffects() << "!\n";
}