/*
* C++ Design Patterns: Flyweight
*
* Flyweight pattern has has structural purpose, applies to objects and uses sharing to support
* large numbers of fine-grained objects efficiently. The pattern can be used to reduce
* memory usage when you need to create a large number of similar objects.
*
*/

#include<iostream>

/*
* ### When to use ###
*
* when one instance of a class can be used to provide many "virtual instances"
* when all of the following are true
* an application uses a large number of objects
* storage costs are high because of the sheer quantity of objects
* most object state can be made extrinsic
* many groups of objects may be replaced by relatively few shared objects once extrinsic state is removed
* the application doesn't depend on object identity
*
*/

// Flyweight
class Flyweight
{
public:
	Flyweight(int value_one)
	{
		m_value_one = value_one;
		std::cout << "ctor: " << m_value_one << std::endl;
	}
	~Flyweight()
	{
		std::cout << m_value_one << " ";
	}
	void report(int value_two)
	{
		std::cout << m_value_one << value_two << " ";
	}
	// ...

private:
	int m_value_one;
	// ...
};

/*
* FlyweightFactory
* creates and manages flyweight objects and ensures
* that flyweights are shared properly
*/
class Factory
{
public:
	static Flyweight* get_fly(int in)
	{
		if (!s_pool[in])
			s_pool[in] = new Flyweight(in);
		return s_pool[in];
	}
	static void clean_up()
	{
		std::cout << "dtors: ";
		for (int i = 0; i < X; i++)
		{
			if (s_pool[i])
				delete s_pool[i];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	// ...

public:
	static int X;
	static int Y;

private:
	static Flyweight *s_pool[];
	// ...
};

int Factory::X = 6;
int Factory::Y = 10;

Flyweight* Factory::s_pool[]
{
	0,0,0,0,0,0
};


int main()
{
	for (int i = 0; i < Factory::X; i++)
	{
		for (int j = 0; j < Factory::Y; j++)
			Factory::get_fly(i)->report(j);
		std::cout << std::endl;
	}
	Factory::clean_up();

	return 0;
}
