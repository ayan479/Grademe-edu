#ifndef FIREBALL_HPP
#define FIREBALL_HPP
// Create the following two spells, on the same model as Fwoosh:
// * Fireball (Name: "Fireball", Effects: "burnt to a crisp")


#include "ASpell.hpp"

class Fireball: public ASpell
{
	public: 
		Fireball();
		~Fireball();
		virtual ASpell *clone() const;

};

#endif