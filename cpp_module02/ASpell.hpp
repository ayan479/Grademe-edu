#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
# include "ATarget.hpp"
class ATarget;

class ASpell
{
    protected:
    // Create an abstract class called ASpell, in Coplien's form, that has the
    // following protected attributes:
    // * name (string)
    // * effects (string)
        std::string name;
        std::string effects;

    public:
        ASpell();
        virtual ~ASpell();
		ASpell(std::string const & name, std::string const & effects);
		ASpell & operator = (ASpell const & as);
        
		// Both will have getters (getName and getEffects) that return strings.
        // Also add a clone pure method that returns a pointer to ASpell.
        // All these functions can be called on a constant object.
        std::string const & getName() const;
        std::string const & getEffects() const;
        virtual ASpell* clone() const = 0;
        // ASpell has a constructor that takes its name and its effects, in that order.
        ASpell(ASpell const & obj);

		// Finally, add to your ASpell class a launch function that takes a reference to constant ATarget.
		// This one will simply call the getHitBySpell of the passed object, passing the current instance as parameter.
		void launch(ATarget const & at_ref) const;

};

#endif
