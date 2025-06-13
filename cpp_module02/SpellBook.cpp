#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

SpellBook::SpellBook(SpellBook const & obj)
{
	*this = obj;
}

SpellBook & SpellBook::operator=(SpellBook const & sb)
{
	s_arr = sb.s_arr;
	return (*this);
} 

void SpellBook::learnSpell(ASpell* as)
{
	if(as)
		s_arr[as->getName()] = as;
}

void SpellBook::forgetSpell(std::string const & sname)
{
	if(s_arr.find(sname) != s_arr.end())
		s_arr.erase(s_arr.find(sname));
}

ASpell* SpellBook::createSpell(std::string const & sname)
{
	ASpell* tmp = NULL;
	if (s_arr.find(sname) != s_arr.end())
		tmp = s_arr[sname];
	return (tmp);
}