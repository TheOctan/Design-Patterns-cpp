
/*
 * C++ Design Patterns: Builder
 *
 * Builder pattern has creational purpose and separates the construction of a complex object
 * from its representation so that the same construction process can create different
 * representations. It is object pattern, ie. relationships can be changed at run-time
 * and are more dynamic. Often is used for building composite structures but constructing
 * objects requires more domain knowledge of the client than using a Factory.
 */

#include<iostream>
#include<vector>

/*
 * ### When to use ###
 *
 * the algorithm for creating a object should be independent of the parts and how they're assembled
 * the construction process must allow different representations for the object that's constructed
 *
 */

// Classes of all possible combat units
#pragma region Units

class Tank
{
public:
	void info()
	{
		std::cout << "Tank" << std::endl;
		// ...
	}
	// ...
};

class Plain
{
public:
	void info()
	{
		std::cout << "Plain" << std::endl;
		// ...
	}
	// ...
};

class Solder
{
public:
	void info()
	{
		std::cout << "Solder" << std::endl;
		// ...
	}
	// ...
};

class Catapult
{
public:
	void info()
	{
		std::cout << "Catapult" << std::endl;
		// ...
	}
	// ...
};

class Car
{
public:
	void info()
	{
		std::cout << "Car" << std::endl;
		// ...
	}
	// ...
};

#pragma endregion

// Base class containing all types of units
class Army
{
public:
	void info()
	{
		for (auto& object : tanks)		object.info();
		for (auto& object : plains)		object.info();
		for (auto& object : solders)	object.info();
		for (auto& object : catapults)	object.info();
		for (auto& object : cars)		object.info();
	}

public:
	std::vector<Tank>		tanks;
	std::vector<Plain>		plains;
	std::vector<Solder>		solders;
	std::vector<Catapult>	catapults;
	std::vector<Car>		cars;
};

// Base class ArmyBuilder declares an interface for a phased
// building the army and provides for its implementation by default
class ArmyBuilder
{
public:
	ArmyBuilder() : _ptr(nullptr) {};	
	virtual		~ArmyBuilder	() = default;

	virtual void createArmy		() { /* ... */ }
	virtual void buildTank		() { /* ... */ }
	virtual void buildPlain		() { /* ... */ }
	virtual void buildSolder	() { /* ... */ }
	virtual void buildCatapult	() { /* ... */ }
	virtual void buildCar		() { /* ... */ }
	// ...

	virtual Army* getArmy		() { return this->_ptr; }

protected:
	Army* _ptr;
};

// The enemy team has all types of combat units except catapults
class EnemyArmyBuilder : public ArmyBuilder
{
public:
	void createArmy	() override { this->_ptr = new Army(); }
	void buildTank	() override { this->_ptr->tanks.	push_back(Tank());	}
	void buildPlain	() override { this->_ptr->plains.	push_back(Plain());	}
	void buildSolder() override { this->_ptr->solders.	push_back(Solder());}
	void buildCar	() override { this->_ptr->cars.		push_back(Car());	}
	// ...
};

// The friendly team has all types of combat units except cars
class FriendlyArmyBuilder : public ArmyBuilder
{
public:
	void createArmy		() override { this->_ptr = new Army(); }
	void buildTank		() override { this->_ptr->tanks.	push_back(Tank());		}
	void buildPlain		() override { this->_ptr->plains.	push_back(Plain());		}
	void buildSolder	() override { this->_ptr->solders.	push_back(Solder());	}
	void buildCatapult	() override { this->_ptr->catapults.push_back(Catapult());	}
	// ...
};

// The class manager step by step creating army of this or that team
// It is here that the algorithm for building an army is defined
class Director
{
public:
	Army * createArmy(ArmyBuilder& builder)
	{
		builder.createArmy();
		builder.buildTank();
		builder.buildPlain();
		builder.buildSolder();
		builder.buildCatapult();
		builder.buildCar();
		// ...

		return builder.getArmy();
	}
	// ...
};


int main()
{
	Director			dir;
	EnemyArmyBuilder	eBuilder;
	FriendlyArmyBuilder fBuilder;
	
	Army* eArmy = dir.createArmy(eBuilder);
	Army* fArmy = dir.createArmy(fBuilder);

	std::cout << "Enemy army:" << std::endl;
	eArmy->info();

	std::cout << "\nFriendly army:" << std::endl;
	fArmy->info();
	// ...

	return 0;
}
