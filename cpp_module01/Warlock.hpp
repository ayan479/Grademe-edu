#ifndef WARLOCK_HPP
#define WARLOCK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
class Warlock
{
    private:
       std::string name;
       std::string title;

        Warlock();
        Warlock(Warlock const & obj);
        Warlock & operator = (Warlock const & w1);
		// You will need a new attribute to store the spells your Warlock knows. Several
		// types fit the bill, it's up to you to choose the best one.
		std::map < std::string, ASpell * > s_arr;
    public:
        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const & title);
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();
        void introduce() const;
		// * learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
		void learnSpell(ASpell *as);
		// * forgetSpell, takes a string corresponding a to a spell's name, and makes the
		// Warlock forget it. If it's not a known spell, does nothing.
		void forgetSpell(std::string sname);
		// * launchSpell, takes a string (a spell name) and a reference to ATarget, that
		// launches the spell on the selected target. If it's not a known spell, does nothing.
		void launchSpell(std::string sname, ATarget const & at_ref);


};

#endif
