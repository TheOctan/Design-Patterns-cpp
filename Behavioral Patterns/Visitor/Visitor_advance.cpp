/*
* C++ Design Patterns: Visitor
*
* Visitor represents an operation to be performed on the elements of an object
* structure. It lets you define a new operation without changing the classes of
* the elements on which it operates. The pattern has behavioral purpose and applies
* to the objects.
*
*/

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * an object structure contains many classes of objects with differing interfaces,
 * and you want to perform operations on these objects that depend on their concrete classes
 * many distinct and unrelated operations need to be performed on objects in an object structure,
 * and you want to avoid "polluting" their classes with these operations
 * the classes defining the object structure rarely change, but you often want
 * to define new operations over the structure
 *
 */

// defines an accept operation that takes a visitor as an argument
class Element
{
public:
	
	virtual void accept(class Visitor& v) = 0;
	// ...
};

// implement an accept operation that takes a visitor as an argument
#pragma region Concrete Elements

class This : public Element
{
public:
	void accept(Visitor& v) override;
	std::string thiss()
	{
		return "This";
	}
	// ...
};

class That : public Element
{
public:
	void accept(Visitor& v) override;
	std::string that()
	{
		return "That";
	}
	// ...
};

class TheOther : public Element
{
public:
	void accept(Visitor& v) override;
	std::string theOther()
	{
		return "theOther";
	}
	// ...
};

#pragma endregion

// declares a Visit operation for each class of ConcreteElement
// in the object structure
class Visitor
{
public:
	virtual void visit(This* e)		= 0;
	virtual void visit(That* e)		= 0;
	virtual void visit(TheOther*e)	= 0;
	// ...
};

void This::accept(Visitor & v)
{
	v.visit(this);
}

void That::accept(Visitor & v)
{
	v.visit(this);
}

void TheOther::accept(Visitor & v)
{
	v.visit(this);
}

// implement each operation declared by Visitor, which implement
// a fragment of the algorithm defined for the corresponding class
// of object in the structure
#pragma region Concrete Visitors

class UpVisitor : public Visitor
{
public:
	void visit(This *e)
	{
		std::cout << "do Up on " + e->thiss() << std::endl;
	}
	void visit(That *e)
	{
		std::cout << "do Up on " + e->that() << std::endl;
	}
	void visit(TheOther *e)
	{
		std::cout << "do Up on " + e->theOther() << std::endl;
	}
	// ...
};

class DownVisitor : public Visitor
{
	void visit(This *e)
	{
		std::cout << "do Down on " + e->thiss() << std::endl;
	}
	void visit(That *e)
	{
		std::cout << "do Down on " + e->that() << std::endl;
	}
	void visit(TheOther *e)
	{
		std::cout << "do Down on " + e->theOther() << std::endl;
	}
	// ...
};

#pragma endregion


int main()
{
	Element* list[]
	{
		new This(),
		new That(),
		new TheOther()
	};

	UpVisitor	up;
	DownVisitor down;

	for (auto obj : list)
		obj->accept(up);
	// ...

	for (auto obj : list)
		obj->accept(down);
	// ...

	for (auto obj : list)
		delete obj;
	

	return 0;
}
