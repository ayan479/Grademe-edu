#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

// In addition to this, just so he won't have only dummy to attack, let's make a
// new target for him, which will be the BrickWall (Type: "Inconspicuous Red-brick Wall").
#include "ATarget.hpp"

class BrickWall: public ATarget
{
	public:
		BrickWall();
		~BrickWall();
		virtual ATarget *clone() const;
};

#endif