/*
 * C++ Design Patterns: Template Method
 *
 * Template method defines the skeleton of an algorithm in an operation, deferring some
 * steps to subclasses. It lets subclasses redefine certain steps of an algorithm
 * without changing the algorithm's structure. The pattern has behavioral purpose and
 * applies to the classes.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * to implement the invariant parts of an algorithm once and leave it up to subclasses to implement the behavior that can vary
 * when common behavior among subclasses should be factored and localizedin a common class to avoid code duplication
 * to control subclasses extensions
 *
 */

// Abstract Class
// implements a template method defining the skeleton of an algorithm
class Base
{
public:
	void execute()
	{
		a();
		ph1();
		c();
		ph2();
		e();
		// ...
	}

private:
	void a()
	{
		std::cout << "a ";
	}
	void c()
	{
		std::cout << "c ";
	}
	void e()
	{
		std::cout << "e ";
	}

	virtual void ph1() = 0;
	virtual void ph2() = 0;
	// ...
};

// implements the primitive operations to carry out specific steps
// of the algorithm, there may be many Concrete classes, each implementing
// the full set of the required operation

#pragma region Concrete Classes

class One : public Base
{
private:
	void ph1() override
	{
		std::cout << "b ";
	}
	void ph2() override
	{
		std::cout << "d ";
	}
	// ...
};

class Two : public Base
{
private:
	void ph1() override
	{
		std::cout << "2 ";
	}
	void ph2() override
	{
		std::cout << "4 ";
	}
	// ...
};

#pragma endregion


int main()
{
	Base* array[]
	{
		new One(),
		new Two()
	};

	for (int i = 0; i < 2; i++)
	{
		array[i]->execute();
		std::cout << std::endl;
		// ...
	}

	for (auto obj : array)
		delete obj;

	return 0;
}
