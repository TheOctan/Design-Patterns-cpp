/*
 * C++ Design Patterns: Strategy
 *
 * Strategy defines a family of algorithms, encapsulates each one, and makes them
 * interchangeable. It lets the algorithm vary independently fromclients that use it.
 * The pattern has behavioral purpose and applies to the objects.
 *
 */

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * many related classes differ only in their behavior
 * you need different variants of an algorithm
 * an algorithm uses data that clients shouldn't know about
 *
 */

// Strategy
// declares an interface common to all supported algorithms
class Compression
{
public:
	virtual ~Compression()							= default;
	virtual void compress(const std::string& file)	= 0;
	// ...
};

// implement the algorithm using the Strategy interface
#pragma region Concrete Strategies

class ZIP_Compression : public Compression
{
public:
	void compress(const std::string& file) override
	{
		std::cout << "ZIP compression" << std::endl;
	}
	// ...
};

class ARJ_Compression : public Compression
{
public:
	void compress(const std::string& file) override
	{
		std::cout << "ARJ compression" << std::endl;
	}
	// ...
};

class RAR_Compression : public Compression
{
public:
	void compress(const std::string& file) override
	{
		std::cout << "RAR compression" << std::endl;
	}
	// ...
};

#pragma endregion

// ...
class Compressor
{
public:
	Compressor(Compression* comp)
		: _ptr(comp)
	{
	}
	~Compressor() 
	{
		delete _ptr;
	}

	void compress(const std::string& file)
	{
		_ptr->compress(file);
	}
	// ...

private:
	Compression* _ptr;
	// ...
};


int main()
{
	Compressor* ptr = new Compressor(new ZIP_Compression());
	ptr->compress("file.txt");
	// ...
	
	delete ptr;

	return 0;
}
