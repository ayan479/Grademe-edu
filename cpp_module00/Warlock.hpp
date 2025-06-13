#ifndef WARLOCK_HPP
#define WARLOCK_HPP

# include <iostream>

class Warlock
{
    private:
       // It has the following private attributes :
       // * name (string)
       // * title (string) 
       std::string name;
       std::string title;

        // our Warlock will also have, in addition to whatever's required by Coplien's
        // form, a constructor that takes, in this order, its name and title. Your Warlock
        // will not be able to be copied, instantiated by copy, or instantiated without a name and a title.
        Warlock();
        Warlock(Warlock const & obj);
        Warlock & operator = (Warlock const & w1);

    public:
        // Since they're private, you will write the following getters :
        // * getName, returns a reference to constant string
        // * getTitle, returns a reference to constant string
        // Both these functions will have to be callable on a constant Warlock.
        std::string const & getName() const;
        std::string const & getTitle() const;

        // Create the following setter: 
        // * setTitle, returns void and takes a reference to constant string
        void setTitle(std::string const & title);

        //
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();

        // So you will write the following function:
        // * void introduce() const;
        void introduce() const;
};

#endif

