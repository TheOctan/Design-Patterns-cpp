/*
 * C++ Design Patterns: Object Pool
 *
 * The use of the Object Pool pattern can significantly improve system performance;
 * its use is most effective in situations where creating instances of a certain class is
 * expensive, objects in the system are created often, but the number of objects created
 * in a unit of time is limited.
 *
 */

#include<iostream>
#include<list>

/*
 * ### When to use ###
 *
 * Used to control the caching of objects. A client that has access to an object pool can
 * avoid creating new objects by simply querying the already created instance in the pool.
 * A pool of objects can be incremented when, in the absence of free objects,
 * new objects are created or the number of objects created is limited.
 *
 */

// Reusable object
class Resource
{
public:
	Resource() : number(0) {}

	void reset()
	{
		this->number = 0;
	}
	int getValue()
	{
		return this->number;
	}
	void setValue(int number)
	{
		this->number = number;
	}
	// ...

private:
	int number;
};

// Reusable Pool
class ObjectPool
{
public:
	static ObjectPool& getInstance()
	{
		if (instance == nullptr)
		{
			instance = new ObjectPool();
		}

		return *instance;
	}
	Resource* getResource()
	{
		if (resources.empty())
		{
			std::cout << "Creating new" << std::endl;
			return new Resource();
		}
		else
		{
			std::cout << "Reusing existing" << std::endl;
			Resource* object = this->resources.front();
			this->resources.pop_front();

			return object;
		}
	}
	void releaseResource(Resource* object)
	{
		object->reset();
		this->resources.push_back(object);
	}

protected:
	ObjectPool()							= default;
	~ObjectPool()							= default;
	ObjectPool(const ObjectPool&)			= delete;
	ObjectPool& operator = (ObjectPool&)	= delete;

private:
	static ObjectPool* instance;
	std::list<Resource*> resources;
};

ObjectPool* ObjectPool::instance = nullptr;


int main()
{
	ObjectPool& pool = ObjectPool::getInstance();

	Resource* one;
	Resource* two;

	one = pool.getResource();
	one->setValue(10);
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	two = pool.getResource();
	two->setValue(20);
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

	pool.releaseResource(one);
	pool.releaseResource(two);

	std::cout << std::endl;

	one = pool.getResource();
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	two = pool.getResource();
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
	// ...

	return 0;
}