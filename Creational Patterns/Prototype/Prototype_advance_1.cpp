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
#include<map>

/*
 * ### When to use ###
 *
 * when the classes to instantiate are specified at run-time
 * to avoid building a class hierarchy of factories that parallels the class hierarchy of products
 * when instances of a class can have one of only a few different combinations of state
 *
 */

// Identifiers of all units
enum class Entity_ID
{
	Tank_ID = 0,
	Plain_ID,
	Solder_ID
};

class Unit;
typedef std::map<Entity_ID, Unit*> Registry;

// The registry of prototypes is defined as Singleton
Registry& getRegistry()
{
	static Registry _instance;
	return _instance;
}

// The only purpose of this class is to help in choosing
// the right constructor when creating prototypes
class Dummy { /* ... */ };

// Polymorphic base class. It also defines a static
// generalized constructor for creating units
class Unit
{
public:
	virtual Unit* clone()	= 0;
	virtual void info()		= 0;
	virtual ~Unit()			= default;

	static Unit* create(Entity_ID id)
	{
		Registry& reg = getRegistry();

		if (reg.find(id) != reg.end())
			return reg[id]->clone();
		return nullptr;
	}
	// ...

protected:
	static void addPrototype(Entity_ID id, Unit* prototype)
	{
		Registry& reg = getRegistry();
		reg[id] = prototype;
	}
	static void removePrototype(Entity_ID id)
	{
		Registry& reg = getRegistry();
		reg.erase(reg.find(id));
	}
};

// In the derived classes of different combat units in the form of static
// data members, the corresponding prototypes are determined
#pragma region Units

class Tank : public Unit
{
private:
	Tank() = default;
	Tank(Dummy)
	{
		Unit::addPrototype(Entity_ID::Tank_ID, this);
	}

public:
	Unit* clone() override
	{
		return new Tank(*this);
	}
	void info() override
	{
		std::cout << "Tank" << std::endl;
		// ...
	}
	// ...

private:
	static Tank prototype;
};

class Plain : public Unit
{
private:
	Plain() = default;
	Plain(Dummy)
	{
		Unit::addPrototype(Entity_ID::Plain_ID, this);
	}

public:
	Unit* clone() override
	{
		return new Plain(*this);
	}
	void info() override
	{
		std::cout << "Plain" << std::endl;
		// ...
	}
	// ...

private:
	static Plain prototype;
};

class Solder : public Unit
{
private:
	Solder() = default;
	Solder(Dummy)
	{
		Unit::addPrototype(Entity_ID::Solder_ID, this);
	}

public:
	Unit* clone() override
	{
		return new Solder(*this);
	}
	void info() override
	{
		std::cout << "Solder" << std::endl;
		// ...
	}
	// ...

private:
	static Solder prototype;
};

Tank	Tank::prototype		= Tank	(Dummy());
Plain	Plain::prototype	= Plain	(Dummy());
Solder	Solder::prototype	= Solder(Dummy());

#pragma endregion


int main()
{
	std::vector<Unit*> vec;
	vec.push_back(Unit::create(Entity_ID::Tank_ID));
	vec.push_back(Unit::create(Entity_ID::Plain_ID));
	vec.push_back(Unit::create(Entity_ID::Solder_ID));

	for (auto& object : vec)
		object->info();
	// ...

	return 0;
}