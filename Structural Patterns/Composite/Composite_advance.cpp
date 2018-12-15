/*
 * C++ Design Patterns: Composite
 *
 * Compose objects into tree structures to represent part-whole hierarchies.
 * Composite lets clients treat individual objects and compositions of objects uniformly.
 * The pattern has structural purpose and applies to objects.
 *
 */

#include<iostream>
#include<vector>
#include<cassert>

/*
 * ### When to use ###
 *
 * you want to represent part-whole hierarchies of objects
 * you want clients to be able to ignore the difference between compositions of objects and individual objects
 *
 */

// Component
class Unit
{
public:
	virtual ~Unit()				= default;
	virtual int getStrength()	= 0;
	virtual void addUnit(Unit* ptr) { assert(false); }
	// ...
};

// Primitives
#pragma region Units

class Tank : public Unit
{
public:
	int getStrength() override
	{
		return 1;
	}
	// ...
};

class Plain : public Unit
{
public:
	int getStrength() override
	{
		return 2;
	}
	// ...
};

class Solder : public Unit
{
public:
	int getStrength() override
	{
		return 3;
	}
	// ...
};

#pragma endregion

// Composite
class CompositeUnit : public Unit
{
public:
	~CompositeUnit() override
	{
		for (auto& object : units)
			delete object;
	}

	int getStrength() override
	{
		int total = 0;
		for (auto& object : units)
			total += object->getStrength();
		
		return total;
	}
	void addUnit(Unit* ptr) override
	{
		units.push_back(ptr);
	}

private:
	std::vector<Unit*> units;
};

// Auxiliary function for creating an army
CompositeUnit* createLegion()
{
	CompositeUnit* legion = new CompositeUnit();

	for (int i = 0; i < 10; i++)
		legion->addUnit(new Tank());

	for (int i = 0; i < 15; i++)
		legion->addUnit(new Plain());

	for (int i = 0; i < 30; i++)
		legion->addUnit(new Solder());
	// ...

	return legion;
}


int main()
{
	CompositeUnit* army = new CompositeUnit();

	for (int i = 0; i < 4; i++)
		army->addUnit(createLegion());

	std::cout << "The army damaging strength is " << army->getStrength() << std::endl;
	// ...

	delete army;

	return 0;
}
