#include "Warlock.hpp"

// Upon creation, the Warlock says :
// <NAME>: This looks like another boring day.
// Of course, whenever we use placeholders like <NAME>, <TITLE>, etc...
// in outputs, you will replace them by the appropriate value. Without the < and >.

Warlock::Warlock(std::string const & name, std::string const & title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

// When he dies, he says:
// <NAME>: My job here is done!

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

std::string const & Warlock::getName() const
{
    return (this->name);
}

std::string const & Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(std::string const & title)
{
    this->title = title;
}

// So you will write the following function:
// * void introduce() const;
// It must display:
// <NAME>: I am <NAME>, <TITLE>!

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}
