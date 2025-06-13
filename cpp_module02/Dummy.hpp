#ifndef DUMMY_HPP
#define DUMMY_HPP

// In the same way, create a concrete ATarget called Dummy, the type of which
// is "Target Practice Dummy". You must also implement its clone() method.
#include "ATarget.hpp"

class Dummy:public  ATarget
{
	public:
		Dummy();
		~Dummy();
		virtual ATarget *clone() const;
};

#endif