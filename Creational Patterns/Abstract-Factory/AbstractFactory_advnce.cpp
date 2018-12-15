/*
* C++ Design Patterns: Abstract Factory
*
* Abstract factory pattern has creational purpose and provides an interface for
* creating families of related or dependent objects without specifying their
* concrete classes. Pattern applies to object and deal with object relationships,
* which are more dynamic. In contrast to Factory Method, Abstract Factory pattern
* produces family of types that are related, ie. it has more than one method of
* types it produces.
*
*/

#include<iostream>
#include<vector>

/*
* ### When to use ###
*
* a system should be independent of how its products are created, composed, and represented
* a system should be configured with one of multiple families of products
* a family of related product objects is designed to be used together
* you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations
*
*/

// Abstract base classes of all possible types of warriors
#pragma region BaseUnits

class Tank
{
public:
	virtual void info()	= 0;
	virtual ~Tank()		= default;
	// ...
};

class Plain
{
public:
	virtual void info()	= 0;
	virtual ~Plain()	= default;
	// ...
};

class Solder
{
public:
	virtual void info()	= 0;
	virtual ~Solder()	= default;
	// ...
};

#pragma endregion

// Classes of all types of warriors of the enemy team
#pragma region EnemyUnits

class EnemyTank : public Tank
{
public:
	void info() override
	{
		std::cout << "Enemy Tank" << std::endl;
		// ...
	}
	// ...
};

class EnemyPlain : public Plain
{
public:
	void info() override
	{
		std::cout << "Enemy Plain" << std::endl;
		// ...
	}
	// ...
};

class EnemySolder : public Solder
{
public:
	void info() override
	{
		std::cout << "Enemy Solder" << std::endl;
		// ...
	}
	// ...
};

#pragma endregion

// Classes of all types of warriors of the friendly team
#pragma region FriendlyUnits

class FriendlyTank : public Tank
{
public:
	void info() override
	{
		std::cout << "Friendly Tank" << std::endl;
		// ...
	}
	// ...
};

class FriendlyPlain : public Plain
{
public:
	void info() override
	{
		std::cout << "Friendly Plain" << std::endl;
		// ...
	}
	// ...
};

class FriendlySolder : public Solder
{
public:
	void info() override
	{
		std::cout << "Friendly Solder" << std::endl;
		// ...
	}
	// ...
};

#pragma endregion

// Abstract factory for the production of the army
class ArmyFactory
{
public:
	virtual Tank*	createTank()	= 0;
	virtual Plain*	createPlain()	= 0;
	virtual Solder* createSolder()	= 0;
	virtual ~ArmyFactory()			= default;
	// ...
};

// Factory for the creation of the army of the enemy team
class EnemyFactory : public ArmyFactory
{
public:
	Tank * createTank() override
	{
		return new EnemyTank();
	}
	Plain* createPlain() override
	{
		return new EnemyPlain();
	}
	Solder* createSolder() override
	{
		return new EnemySolder();
	}
	// ...
};

// Factory for the creation of the army of the friendly team
class FriendlyFactory : public ArmyFactory
{
public:
	Tank * createTank() override
	{
		return new FriendlyTank();
	}
	Plain* createPlain() override
	{
		return new FriendlyPlain();
	}
	Solder* createSolder() override
	{
		return new FriendlySolder();
	}
	// ...
};

// Class containing the entire army of this or that team
class Army
{
public:
	~Army()
	{
		for (auto object : tanks)	delete object;
		for (auto object : plains)	delete object;
		for (auto object : solders)	delete object;
	}

	void info()
	{
		for (auto object : tanks)	object->info();
		for (auto object : plains)	object->info();
		for (auto object : solders)	object->info();
	}

public:
	std::vector<Tank*>		tanks;
	std::vector<Plain*>		plains;
	std::vector<Solder*>	solders;
};

// Here the army of this or that side is created
class Game
{
public:
	Army * createArmy(ArmyFactory& factory)
	{
		Army* p = new Army();

		p->tanks.push_back(factory.createTank());
		p->plains.push_back(factory.createPlain());
		p->solders.push_back(factory.createSolder());

		return p;
	}
};


int main()
{
	Game			game;
	EnemyFactory	eFactory;
	FriendlyFactory fFactory;

	Army* eArmy = game.createArmy(eFactory);
	Army* fArmy = game.createArmy(fFactory);

	std::cout << "Enemy army:" << std::endl;
	eArmy->info();

	std::cout << "\nFriendly army:" << std::endl;
	fArmy->info();
	// ...

	return 0;
}
