// Make a TargetGenerator class, in canonical form, and as before,
// non-copyable.

// It will have the following functions:

// * void learnTargetType(ATarget*), teaches a target to the generator

// * void forgetTargetType(string const &), that makes the generator forget a
//   target type if it's known

// * ATarget* createTarget(string const &), that creates a target of the
//   specified type

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"
#include <iostream>

class TargetGenerator
{
	private:
		std::map < std::string, ATarget * > t_arr;
		TargetGenerator(TargetGenerator const & obj);
		TargetGenerator & operator=(TargetGenerator const & tg); 
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* at);
		void forgetTargetType(std::string const & tname);
		ATarget* createTarget(std::string const & tname);
};

#endif