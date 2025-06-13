#include "Polymorph.hpp"

// Create the following two spells, on the same model as Fwoosh:
// * Polymorph (Name: "Polymorph", Effects: "turned into a critter")

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}