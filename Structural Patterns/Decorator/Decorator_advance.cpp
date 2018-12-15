/*
 * C++ Design Patterns: Decorator
 *
 * Attach additional responsibilities to an object dynamically. Decorators
 * provide a flexible alternative to subclassing for extending functionality.
 * The pattern has structural purpose and applies to objects.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects
 * for responsibilities that can be withdrawn
 * when extension by subclassing is impractical
 *
 */

// Component
class Widget
{
public:
	virtual void draw() = 0;
	// ...
};

// Concrete Component
class TextField : public Widget
{
public:
	TextField(int width, int height)
	:	width(width),
		height(height)
	{
	}

	void draw() override
	{
		std::cout << "TextField: " << width << "x" << height << std::endl;
	}
	// ...

private:
	int width;
	int height;
};

// Decorator
class Decorator : public Widget
{
public:
	Decorator(Widget* ptr) : _wid(ptr)
	{}

	virtual void draw() override
	{
		_wid->draw();
	}
	// ...

private:
	Widget* _wid;
};

// Concrete Decorators
#pragma region Decorators

class BorderDecorator : public Decorator
{
public:
	BorderDecorator(Widget* ptr) : Decorator(ptr)
	{}

	void draw() override
	{
		Decorator::draw();
		std::cout << "BorderDecorator" << std::endl;
	}
	// ...
};

class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(Widget* ptr) : Decorator(ptr)
	{}

	void draw() override
	{
		Decorator::draw();
		std::cout << "ScrollDecorator" << std::endl;
	}
	// ...
};

#pragma endregion


int main()
{
	Widget* object = new BorderDecorator(
						new BorderDecorator(
							new ScrollDecorator(
								new TextField(640, 480))));
	object->draw();
	// ...

	return 0;
}
