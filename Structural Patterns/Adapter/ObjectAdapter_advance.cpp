/*
 * C++ Design Patterns: Adapter (Object scope)
 *
 * Convert the interface of a class into another interface the clients expect.
 * Adapter lets classes work together that couldn't otherwise because of
 * incompatible interfaces, ie. allows to use a client with an incompatible
 * interface by an Adapter that does the conversion. Adapter has structural purpose
 * and can be applied on classes and also on object. A class adapter uses multiple
 * inheritance to adapt one interface to another and the object adapter uses object
 * composition to combine classes with different interfaces.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * you want to use an existing class, and its interface does not match the one you need
 * you want to create a reusable class that cooperates with classes that don't necessarily have compatible interfaces
 *
 */

// adaptable class
class FahrenheitSensor
{
public:
	float getFahrenheitTemp()
	{
		float t = 64.f;
		// ...
		return t;
	}
	// ...
};

// interface
class Sensor
{
public:
	virtual ~Sensor()				= default;
	virtual float getTemperature()	= 0;
	// ...
};

// class-adapter
class Adapter : public Sensor
{
public:
	Adapter(FahrenheitSensor* ptr) : _ptr(ptr)
	{}
	~Adapter() override
	{
		delete this->_ptr;
	}
	float getTemperature() override
	{
		return (this->_ptr->getFahrenheitTemp() - 32.f)*5.f / 9.f;
	}
	// ...

private:
	FahrenheitSensor* _ptr;
	// ...
};


int main()
{
	Sensor* ptr = new Adapter(new FahrenheitSensor());
	std::cout << "Celsius temperature = " << ptr->getTemperature() << std::endl;
	// ...

	delete ptr;

	return 0;
}
