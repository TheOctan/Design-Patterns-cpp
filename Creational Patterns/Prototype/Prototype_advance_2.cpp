/*
 * C++ Design Patterns: Prototype
 *
 * Specify the kinds of objects to create using a prototypical instance, and create
 * new objects by copying this prototype. Pattern has creational purpose and deals
 * with object relationships, which are more dynamic. The pattern hides the complexities
 * of making new instances from the client.
 *
 */

#include<iostream>
#include<vector>

/*
 * ### When to use ###
 *
 * when the classes to instantiate are specified at run-time
 * to avoid building a class hierarchy of factories that parallels the class hierarchy of products
 * when instances of a class can have one of only a few different combinations of state
 *
 */

// Hierarchy of classes of game characters
// Polymorphic base class
class Unit
{
public:
	virtual Unit* clone() = 0;
	virtual void info() = 0;
	virtual ~Unit() = default;
	// ...
};

// Derived classes of various combat units
#pragma region Units

class Tank : public Unit
{
	friend class PrototypeFactory;
private:
	Tank() = default;

public:
	Unit * clone() override
	{
		return new Tank(*this);
	}
	void info() override
	{
		std::cout << "Tank" << std::endl;
	}
	// ...
};

class Plain : public Unit
{
	friend class PrototypeFactory;
private:
	Plain() = default;

public:
	Unit * clone() override
	{
		return new Plain(*this);
	}
	void info() override
	{
		std::cout << "Plain" << std::endl;
	}
	// ...
};

class Solder : public Unit
{
	friend class PrototypeFactory;
private:
	Solder() = default;

public:
	Unit * clone() override
	{
		return new Solder(*this);
	}
	void info() override
	{
		std::cout << "Solder" << std::endl;
	}
	// ...
};

#pragma endregion

// Factory for the creation of combat units
class PrototypeFactory
{
public:
	Unit* createTank()
	{
		static Tank prototype;
		return prototype.clone();
	}
	Unit* createPlain()
	{
		static Plain prototype;
		return prototype.clone();
	}
	Unit* createSolder()
	{
		static Solder prototype;
		return prototype.clone();
	}
	// ...
};


int main()
{
	PrototypeFactory factory;
	std::vector<Unit*> vec;
	vec.push_back(factory.createTank());
	vec.push_back(factory.createPlain());
	vec.push_back(factory.createSolder());

	for (auto& object : vec)
		object->info();
	// ...

	return 0;
}