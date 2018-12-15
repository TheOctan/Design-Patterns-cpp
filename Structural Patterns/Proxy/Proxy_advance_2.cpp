/*
 * C++ Design Patterns: Proxy
 *
 * Proxy pattern provides a surrogate or placeholder for another object to control access to it.
 * The pattern has structural purpose and applies to objects.
 *
 */

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * whenever there is a need for a more versatile or sophisticated reference to an object than a simple pointer
 *
 */

// class-client
#pragma region Client

class Person
{
public:
	Person()
	{
		nameString = list[next++];
	}
	std::string name()
	{
		return nameString;
	}

private:
	std::string nameString;
	static std::string list[];
	static int next;
	// ...
};

std::string Person::list[]
{
	"William",
	"Harry",
	"Nikola",
	"Emily"
};
int Person::next = 0;

#pragma endregion

// Real subject
class PetttCashProtected
{
public:
	PetttCashProtected()
	{
		balance = 500;
	}
	bool withDraw(int amount)
	{
		if (amount > balance)
			return false;

		balance -= amount;
		return true;
	}
	int getBalance()
	{
		return balance;
	}

private:
	int balance;
	// ...
};

// Proxy
// maintains a reference that lets the proxy access the real subject
class PettyCash
{
public:
	bool withDraw(Person& p, int amount)
	{
		if (p.name() == "William" || p.name() == "Nikola"
								|| p.name() == "Emily")
			return realThing.withDraw(amount);
		else return false;
	}
	int getBalance()
	{
		return realThing.getBalance();
	}

private:
	PetttCashProtected realThing;
};


int main()
{
	PettyCash pc;
	Person workers[4];

	for (int i = 0, amount = 100; i < 4; i++, amount += 100)
	{
		if (!pc.withDraw(workers[i], amount))
			std::cout << "No money for " << workers[i].name() << std::endl;
		else
			std::cout << amount << " dollars for" << workers[i].name() << std::endl;
		// ...
	}

	std::cout << "Remaining balance is " << pc.getBalance() << std::endl;

	return 0;
}
