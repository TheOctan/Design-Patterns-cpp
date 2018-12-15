/*
 * C++ Design Patterns: Iterator
 *
 * Iterator pattern has behavioral purpose and applies to objects. The pattern provides
 * a way to access the elements of an aggregate object sequentially without exposing
 * its underlying representation.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * to access an aggregate object's contents without exposing its internal representation
 * to support multiple traversals of aggregate objects
 * to provide a uniform interface for traversing different aggregate structures
 * (to support polymorphic iteration)
 *
 */

class Iterator;

// has a collection of objects and implements the method
// that returns an Iterator for its collection
class Stack
{	
public:
	friend class Iterator;
	Stack()
	{
		count = -1;
	}
	void push(int in)
	{
		items[++count] = in;
	}
	int pop()
	{
		return items[count--];
	}
	bool isEmpty()
	{
		return count == -1;
	}
	Iterator* createItertor() const;
	// ...

private:
	int items[10];
	unsigned int count;
	// ...
};

// is responsible for managing
// the current position of the iterator
class Iterator
{
public:
	Iterator(const Stack* stk)
	{
		_stk = stk;
	}
	void first()
	{
		index = 0;
	}
	void next()
	{
		index++;
	}
	bool isDone()
	{
		return index == _stk->count + 1;
	}
	int currentItem()
	{
		return _stk->items[index];
	}
	// ...

private:
	const Stack* _stk;
	unsigned int index;
	// ...
};

Iterator * Stack::createItertor() const
{
	return new Iterator(this);
}

bool operator == (const Stack& left, const Stack& right)
{
	Iterator* it1 = left.createItertor();
	Iterator* it2 = right.createItertor();

	for (it1->first(), it2->first();
		!it1->isDone();
		it1->next(), it2->next())
	{
		if (it1->currentItem() != it2->currentItem())
			break;
	}

	bool ans = it1->isDone() && it2->isDone();

	delete it1;
	delete it2;

	return ans;
}


int main()
{
	Stack stk1;

	for (int i = 1; i < 5; i++)
		stk1.push(i);
	
	Stack stk2(stk1), stk3(stk1), stk4(stk1), stk5(stk1);

	stk3.pop();
	stk5.pop();
	stk4.push(2);
	stk5.push(9);

	std::cout << "1 == 2 is " << std::boolalpha << (stk1 == stk2) << std::endl;
	std::cout << "1 == 3 is " << std::boolalpha << (stk1 == stk3) << std::endl;
	std::cout << "1 == 4 is " << std::boolalpha << (stk1 == stk4) << std::endl;
	std::cout << "1 == 5 is " << std::boolalpha << (stk1 == stk5) << std::endl;
	// ...

	return 0;
}
