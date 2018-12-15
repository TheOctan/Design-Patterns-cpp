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

// defines the common interface for RealSubject and Proxy
// so that a Proxy can be used anywhere a RealSubject is expected
class Subject
{
public:
	virtual void execute() = 0;
	virtual ~Subject() { /* ... */ }
	// ...
};

// defines the real object that the proxy represents
class RealSubject : public Subject
{
public:
	RealSubject(std::string s)
	{
		str = s;
	}
	void execute() override
	{
		std::cout << str << std::endl;
	}
	// ...

private:
	std::string str;
	// ...
};

// maintains a reference that lets the proxy access the real subject
class Proxy : public Subject
{
public:
	Proxy(std::string s)
	{
		int num = s.find_first_of(' ');
		first = s.substr(0, num);

		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		second = s.substr(0, num);

		s = s.substr(num + 1);
		num = s.find_first_of(' ');
		third = s.substr(0, num);
		s = s.substr(num + 1);

		_ptr = new RealSubject(s);
	}
	~Proxy()
	{
		delete _ptr;
	}
	RealSubject* operator->()
	{
		std::cout << first << " " << second << " ";
		return _ptr;
	}
	void execute() override
	{
		std::cout << first << " " << third << " ";
		_ptr->execute();
	}
	// ...

private:
	std::string first;
	std::string second;
	std::string third;
	RealSubject* _ptr;
	// ...
};


int main()
{
	Proxy obj("the quick brown fox jumped over the dog");
	obj->execute();
	obj.execute();
	// ...

	return 0;
}
