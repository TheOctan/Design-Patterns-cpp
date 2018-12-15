/*
 * C++ Design Patterns: Observer
 *
 * Observer defines a one-to-many dependency between objects so that when one object
 * changes state, all its dependents are notified and updated automatically. The pattern
 * has behavioral purpose and applies to the objects.
 *
 */

#include<iostream>
#include<vector>

/*
 * ### When to use ###
 *
 * when an abstraction has two aspects, one dependent on the other
 * when a change to one object requires changing others, and you don't know how many objects need to be changed
 * when an object should be able to notify other objects without making assumptions about who these objects are
 *
 */

// knows its observers and provides an interface for attaching
// and detaching observers
class Subject
{
public:
	void attach(class Observer* obs)
	{
		observers.push_back(obs);
	}
	void setValue(int value)
	{
		_value = value;
		notify();
	}
	int getValue()
	{
		return _value;
	}
	void notify();
	// ...

private:
	std::vector<Observer*> observers;
	int _value;
	// ...
};

// defines an updating interface for objects that should be notified
// of changes in a subject
class Observer
{
public:
	Observer(Subject* model, int div)
	{
		_model = model;
		denom = div;

		_model->attach(this);
	}

	virtual void update() = 0;
	// ...

protected:
	Subject * getSubject()
	{
		return _model;
	}
	int getDivisor()
	{
		return denom;
	}

private:
	Subject* _model;
	int denom;
	// ...
};

void Subject::notify()
{
	for (auto obj : observers)
		obj->update();
}

// stores state of interest to ConcreteObserver objects and
// sends a notification to its observers when its state changes
#pragma region Concrete Observers

class DivObserver : public Observer
{
public:
	DivObserver(Subject* model, int div)
		: Observer(model, div)
	{
	}
	void update() override
	{
		int v = getSubject()->getValue();
		int d = getDivisor();
		std::cout << v << " div " << d << " is " << v / d << std::endl;
	}
};

class ModObserver : public Observer
{
public:
	ModObserver(Subject* model, int div)
		: Observer(model, div)
	{
	}
	void update() override
	{
		int v = getSubject()->getValue();
		int d = getDivisor();
		std::cout << v << " mod " << d << " is " << v % d << std::endl;
	}
};

#pragma endregion


int main()
{
	Subject* subj = new Subject();

	DivObserver divObs1(subj, 4);
	DivObserver divObs2(subj, 3);
	ModObserver modObs3(subj, 3);

	subj->setValue(14);

	delete subj;

	return 0;
}
