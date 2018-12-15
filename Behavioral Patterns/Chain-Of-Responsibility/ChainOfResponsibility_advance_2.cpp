/*
 * C++ Design Patterns: Chain of Responsibility
 *
 * Chain of Responsibility pattern avoids coupling the sender of a request to its receiver
 * by giving more than one object a chance to handle the request. The pattern chains
 * the receiving objects and passes the request along the chain until an object handles it.
 * It has a behavioral purpose and deals with relationships between objects.
 *
 */

#include<iostream>
#include<vector>
#include<ctime>

/*
 * ### When to use ###
 *
 * more than one object may handle a request, and the handler should be ascertained automatically
 * you want to issue a request to one of several objects without specifying the receiver explicitly
 * the set of objects that can handle a request should be specified dynamically
 *
 */

// Handler
class Component
{
public:
	Component(int value, Component* next)
	:	_value(value),
		_next(next)
	{
	}
	void setNext(Component* next)
	{
		_next = next;
	}
	virtual void traverse()
	{
		std::cout << _value << " ";
	}
	virtual void volunteer()
	{
		_next->volunteer();
	}
	// ...

private:
	int _value;
	Component* _next;
};

// Concrete
class Primitive : public Component
{
public:
	Primitive(int value, Component* next = nullptr)
		: Component(value, next)
	{
	}
	void volunteer() override
	{
		Component::traverse();
		if (rand() * 100 % 6 != 0)
		{
			Component::volunteer();
		}
	}
	// ...
};

// Node
class Composite : public Component
{
public:
	Composite(int value, Component* next = nullptr)
		: Component(value, next)
	{
	}
	void add(Component* com)
	{
		_children.push_back(com);
	}
	void traverse() override
	{
		Component::traverse();
		for (auto obj : _children)
		{
			obj->traverse();
		}
	}
	void volunteer() override
	{
		Component::volunteer();
	}
	// ...

private:
	std::vector<Component*> _children;
};


int main()
{
	srand(unsigned(time(NULL)));

	Primitive seven(7);
	Primitive six(6, &seven);
	
	Composite three(3, &six);
	three.add(&six);
	three.add(&seven);
	
	Primitive five(5, &three);
	Primitive four(4, &five);

	Composite two(2, &four);
	two.add(&four);
	two.add(&five);

	Composite one(1, &two);

	Primitive nine(9, &one);
	Primitive eight(8, &nine);

	one.add(&two);
	one.add(&three);
	one.add(&eight);
	one.add(&nine);

	seven.setNext(&eight);

	std::cout << "travers: ";
	one.traverse();
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		one.volunteer();
		std::cout << std::endl;
		// ...
	}

	// 1
	// |
	// +-- 2
	// |   |
	// |   +-- 4 5
	// |
	// +-- 3
	// |   |
	// |   +-- 6 7
	// |
	// +-- 8 9


	return 0;
}
