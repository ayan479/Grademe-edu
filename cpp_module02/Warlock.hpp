#ifndef WARLOCK_HPP
#define WARLOCK_HPP

# include <iostream>
// # include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"
class Warlock
{
    private:
       std::string name;
       std::string title;
	   SpellBook SpellBook;

        Warlock();
        Warlock(Warlock const & obj);
        Warlock & operator = (Warlock const & w1);
		// std::map < std::string, ASpell * > s_arr;
    public:
        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const & title);
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();
        void introduce() const;
		void learnSpell(ASpell *as);
		void forgetSpell(std::string sname);
		void launchSpell(std::string sname, ATarget const & at_ref);


};

#endif
