// Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
// by copy. It will have the following functions:

// * void learnSpell(ASpell*), that COPIES a spell in the book
// * void forgetSpell(string const &), that deletes a spell from the book, except
//   if it isn't there
// * ASpell* createSpell(string const &), that receives a string corresponding to
//   the name of a spell, creates it, and returns it.

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"
#include <iostream>

class SpellBook
{
	private:
		std::map < std::string, ASpell * > s_arr;
		SpellBook(SpellBook const & obj);
		SpellBook & operator=(SpellBook const & sb);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* as);
		void forgetSpell(std::string const & sname);
		ASpell* createSpell(std::string const & sname);
};

#endif
