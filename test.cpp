// C++ Module 02 Template Guide
// This file serves as a reference template for the module 02 assignment patterns
#include <string>
#include <iostream>
#include <map>

/********************************************************************
 * ABSTRACT BASE CLASS PATTERN
 ********************************************************************/

// This is the pattern for abstract base classes like ASpell and ATarget
class AbstractClass {
protected:
    // Protected attributes are accessible by derived classes
    std::string attribute1;
    std::string attribute2;
    
public:
    // Orthodox Canonical Form - always implement these four
    AbstractClass() {
        // Default initialization if needed
    }
    
    AbstractClass(AbstractClass const & obj) {
        // Copy all attributes
        *this = obj;
    }
    
    AbstractClass & operator=(AbstractClass const & obj) {
        if (this != &obj) {
            this->attribute1 = obj.attribute1;
            this->attribute2 = obj.attribute2;
        }
        return *this;
    }
    
    // Virtual destructor is crucial for proper cleanup in inheritance
    virtual ~AbstractClass() {
        // Cleanup if needed
    }
    
    // Constructor with parameters
    AbstractClass(std::string const & param1, std::string const & param2) :
        attribute1(param1), attribute2(param2) {
    }
    
    // Getter methods
    std::string const & getAttribute1() const {
        return attribute1;
    }
    
    std::string const & getAttribute2() const {
        return attribute2;
    }
    
    // Pure virtual method (makes the class abstract)
    virtual AbstractClass* clone() const = 0;
    
    // Other methods
    void someMethod(AnotherClass const & param) const {
        // Implementation
    }
};

/********************************************************************
 * CONCRETE DERIVED CLASS PATTERN
 ********************************************************************/

// Pattern for concrete classes like Fwoosh, Fireball, Dummy, etc.
class ConcreteClass : public AbstractClass {
public:
    // Often only need default constructor and destructor
    ConcreteClass() : AbstractClass("fixed_value", "another_value") {
        // Any additional initialization
    }
    
    ~ConcreteClass() {
        // Any specific cleanup
    }
    
    // Implementation of the pure virtual method (required)
    virtual AbstractClass* clone() const {
        return new ConcreteClass(*this);
    }
};

/********************************************************************
 * CONTAINER CLASS PATTERN
 ********************************************************************/

// Pattern for container classes like SpellBook, TargetGenerator
class ContainerClass {
private:
    // Storage container (usually a map)
    std::map<std::string, AbstractClass*> items;
    
    // Private copy constructor and assignment operator
    // This makes the class non-copyable
    ContainerClass(ContainerClass const & obj);
    ContainerClass & operator=(ContainerClass const & obj);
    
public:
    // Simple constructor/destructor
    ContainerClass() {
        // Initialize if needed
    }
    
    ~ContainerClass() {
        // Clean up map items if you own them
        std::map<std::string, AbstractClass*>::iterator it = items.begin();
        while (it != items.end()) {
            delete it->second;  // Only if this class owns the pointers
            ++it;
        }
        items.clear();
    }
    
    // Standard operations
    void learn(AbstractClass* item) {
        if (item) {
            // Store a copy using the clone method
            std::string name = item->getAttribute1();
            
            // Clean up previous item with same name if it exists
            forget(name);
            
            // Store new item
            items[name] = item->clone();
        }
    }
    
    void forget(std::string const & name) {
        std::map<std::string, AbstractClass*>::iterator it = items.find(name);
        if (it != items.end()) {
            delete it->second;  // Only if this class owns the pointers
            items.erase(it);
        }
    }
    
    AbstractClass* create(std::string const & name) {
        std::map<std::string, AbstractClass*>::iterator it = items.find(name);
        if (it != items.end()) {
            return it->second->clone();  // Return a copy
        }
        return NULL;  // Not found
    }
};

/********************************************************************
 * MANAGER CLASS PATTERN
 ********************************************************************/

// Pattern for manager classes like Warlock
class ManagerClass {
private:
    // Attributes
    std::string attribute1;
    std::string attribute2;
    ContainerClass container;  // Container for managed objects
    
    // Make non-copyable by declaring private and not implementing
    ManagerClass();
    ManagerClass(ManagerClass const & obj);
    ManagerClass & operator=(ManagerClass const & obj);
    
public:
    // Constructor/Destructor with messages
    ManagerClass(std::string const & param1, std::string const & param2) :
        attribute1(param1), attribute2(param2) {
        std::cout << attribute1 << ": This looks like another boring day." << std::endl;
    }
    
    ~ManagerClass() {
        std::cout << attribute1 << ": My job here is done!" << std::endl;
    }
    
    // Getters and setters
    std::string const & getAttribute1() const {
        return attribute1;
    }
    
    std::string const & getAttribute2() const {
        return attribute2;
    }
    
    void setAttribute2(std::string const & value) {
        attribute2 = value;
    }
    
    // Operations that delegate to container
    void learnSomething(AbstractClass* item) {
        container.learn(item);
    }
    
    void forgetSomething(std::string name) {
        container.forget(name);
    }
    
    void useSomething(std::string name, AnotherAbstractClass const & target) {
        // Implementation with delegation to container
    }
    
    // Other methods
    void introduce() const {
        std::cout << attribute1 << ": I am " << attribute1 << ", " << attribute2 << "!" << std::endl;
    }
};

/********************************************************************
 * IMPLEMENTATION PATTERNS AND TIPS
 ********************************************************************/

/*
 * Forward Declaration (for circular dependencies)
 */
class ClassB;  // Forward declaration

class ClassA {
    // Can use ClassB* or ClassB& but not methods of ClassB directly
    ClassB* somePtr;  // OK
    // ClassB someObject;  // NOT OK without full declaration
};

/*
 * Memory Management Tips
 * - Always delete what you new
 * - Use virtual destructors for base classes
 * - Be clear about ownership of pointers
 * - For this assignment, follow the specific memory requirements
 */

/*
 * Testing Tips
 * - Test each class independently first
 * - Then test interactions between classes
 * - Make sure all memory is properly freed (no leaks)
 * - Check that your classes behave correctly with invalid