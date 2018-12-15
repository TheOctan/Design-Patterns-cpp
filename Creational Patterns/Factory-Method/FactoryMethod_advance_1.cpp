/*
 * C++ Design Patterns: Factory Method
 *
 * Define an interface for creating an object, but let subclasses decide which class to instantiate.
 * Factory Method lets a class defer instantiation to subclasses. The pattern has creational purpose
 * and applies to classes where deals with relationships through inheritence ie. they are static-fixed
 * at compile time. In contrast to Abstract Factory, Factory Method contain method to produce only one
 * type of product.
 *
 */

#include<iostream>
#include<vector>

/*
 * ### When to use ###
 *
 * a class cant anticipate the class of objects it must create
 * a class wants its subclasses to specify the objects it creates
 * classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate
 *
 */

// Identifiers of all units
enum class Entity_ID
{
	Tank_ID = 0,
	Plain_ID,
	Solder_ID
};

// Hierarchy of classes of game characters
#pragma region Units

class Unit
{
public:
	virtual void info()	= 0;
	virtual ~Unit()		= default;

	static Unit* createEntity(Entity_ID id);
	// ...
};

class Tank : public Unit
{
public:
	void info() override
	{
		std::cout << "Tank" << std::endl;
		// ...
	}
	// ...
};

class Plain : public Unit
{
public:
	void info() override
	{
		std::cout << "Plain" << std::endl;
		// ...
	}
	// ...
};

class Solder : public Unit
{
public:
	void info() override
	{
		std::cout << "Solder" << std::endl;
		// ...
	}
	// ...
};

#pragma endregion


// Creating objects using object factories
int main()
{
	std::vector<Unit*> vec;
	vec.push_back(Unit::createEntity(Entity_ID::Tank_ID));
	vec.push_back(Unit::createEntity(Entity_ID::Plain_ID));
	vec.push_back(Unit::createEntity(Entity_ID::Solder_ID));

	for (auto& object : vec)
		object->info();
	// ...

	return 0;
}

Unit * Unit::createEntity(Entity_ID id)
{
	switch (id)
	{
	case Entity_ID::Tank_ID:	return new Tank();		break;
	case Entity_ID::Plain_ID:	return new Plain();		break;
	case Entity_ID::Solder_ID:	return new Solder();	break;
	}
	return nullptr;
}
