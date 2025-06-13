#include "Fwoosh.hpp"

// Its default constructor will set the name to "Fwoosh" and the effects to "fwooshed".
Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

// implement the clone() method. In the case of Fwoosh,
// it will return a pointer to a new Fwoosh object.
ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}