/*
 * C++ Design Patterns: State
 * 
 * The pattern allows an object to alter its behavior when its internal state changes.
 * The object will appear to change its class. It has behavioral purpose and applies
 * to the objects.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * when an object's behavior depends on its state, and it must change its behavior at run-time depending on that state
 * operations have large, multipart conditional statements that depend on the object's state
 *
 */

// ...
class Machine
{
public:
	Machine();
	void setCurrent(class State* s)
	{
		current = s;
	}
	void on();
	void off();
	// ...

private:
	State* current;
	// ...
};

// ...
class State
{
public:
	virtual void on(Machine* m)
	{
		std::cout << "\talready ON" << std::endl;
	}
	virtual void off(Machine* m)
	{
		std::cout << "\talready OFF" << std::endl;
	}
	// ...
};

void Machine::on()
{
	current->on(this);
}

void Machine::off()
{
	current->off(this);
}

class ON : public State
{
public:
	ON()
	{
		std::cout << "\tON-ctor";
	}
	~ON()
	{
		std::cout << "\tdtor-ON" << std::endl;
	}
	void off(Machine* m) override;
	// ...
};

class OFF : public State
{
public:
	OFF()
	{
		std::cout << "\tOFF-ctor";
	}
	~OFF()
	{
		std::cout << "\tdtor-OFF" << std::endl;
	}
	void on(Machine* m) override
	{
		std::cout << "\tgoing from OFF to ON";
		m->setCurrent(new ON());
		delete this;
	}
	// ...
};

void ON::off(Machine * m)
{
	std::cout << "\tgoing from ON to OFF";
	m->setCurrent(new OFF());
	delete this;
}

Machine::Machine()
{
	current = new OFF();
	std::cout << std::endl;
}


int main()
{
	void(Machine::*ptrs[])() =
	{
		&Machine::off,
		&Machine::on
	};

	Machine fsm;
	int num;

	while (true)
	{
		std::cout << "Enter 0/1: ";
		std::cin >> num;

		(fsm.*ptrs[num])();
	}

	return 0;
}
