#ifndef FWOOSH_HPP
#define FWOOSH_HPP

// When all this is done, create an implementation of ASpell called Fwoosh. 
#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		// Its default constructor will set the name to "Fwoosh" and the effects to
		// "fwooshed". You will, of course, implement the clone() method. In the case of
		// Fwoosh, it will return a pointer to a new Fwoosh object.
		Fwoosh();
		~Fwoosh();
		virtual ASpell *clone() const;
};

#endif

