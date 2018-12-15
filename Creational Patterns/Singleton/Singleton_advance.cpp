/*
 * C++ Design Patterns: Singleton
 *
 * Ensure a class only has one instance, and provide a global point of access to it.
 * Pattern has creational purpose and deals with object relationships, which are more
 * dynamic. The Singleton is often used as a part another design patterns (see [Façade]
 * and [Flyweight]).
 *
 */

#include <iostream>

/*
 * ### When to use ###
 *
 * there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point
 * when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code
 *
 */

class Singleton
{
public:
	static Singleton& getInstance();
	void about();
	// ...

private:
	class Destroyer
	{
	public:
		void initialize(Singleton* p);
		~Destroyer();

	private:
		Singleton * instance;
	};

protected:
	Singleton()							= default;
	~Singleton()						= default;
	Singleton(const Singleton&)			= delete;
	Singleton& operator = (Singleton&)	= delete;

private:
	static Destroyer destroyer;
	static Singleton* instance;
	// ...
};


int main()
{
	Singleton::getInstance().about();
	return 0;
}

Singleton* Singleton::instance = nullptr;
Singleton::Destroyer Singleton::destroyer;

Singleton::Destroyer::~Destroyer()
{
	std::cout << "Singleton is destruct" << std::endl;
	delete this->instance;
}

void Singleton::Destroyer::initialize(Singleton * p)
{
	this->instance = p;
}

Singleton & Singleton::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Singleton();
		destroyer.initialize(instance);
	}

	return *instance;
}

void Singleton::about()
{
	std::cout << "This is Singleton." << std::endl;
	// ...
}
