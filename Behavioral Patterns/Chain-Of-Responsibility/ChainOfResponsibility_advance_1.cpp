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
#include<ctime>

/*
 * ### When to use ###
 *
 * more than one object may handle a request, and the handler should be ascertained automatically
 * you want to issue a request to one of several objects without specifying the receiver explicitly
 * the set of objects that can handle a request should be specified dynamically
 *
 */

// defines an interface for handling requests and
// optionally implements the successor link
class Handler
{
public:
	Handler()
	{
		_next = nullptr;
	}
	void setNext(Handler* next)
	{
		_next = next;
	}
	void add(Handler* next)
	{
		if (_next)
			_next->add(next);
		else
			_next = next;
	}
	virtual void handle(int i)
	{
		_next->handle(i);
	}
	// ...

private:
	Handler* _next;
};

// handle requests they are responsible for
#pragma region Concrete Handler

class Handler1 : public Handler
{
public:
	void handle(int i) override
	{
		if (rand() % 3)
		{
			std::cout << "H1_passed_" << i << " ";
			Handler::handle(i);
		}
		else
		{
			std::cout << "H1_handled_" << i << " ";
		}
		// ...
	}
	// ...
};

class Handler2 : public Handler
{
public:
	void handle(int i) override
	{
		if (rand() % 3)
		{
			std::cout << "H2_passed_" << i << " ";
			Handler::handle(i);
		}
		else
		{
			std::cout << "H2_handled_" << i << " ";
		}
		// ...
	}
	// ...
};

class Handler3 : public Handler
{
public:
	void handle(int i)
	{
		if (rand() % 3)
		{
			std::cout << "H3_passsed_" << i << " ";
			Handler::handle(i);
		}
		else
		{
			std::cout << "H3_handled_" << i << " ";
		}
		// ...
	}
	// ...
};

#pragma endregion


int main()
{
	srand(unsigned(time(NULL)));

	Handler1* root	= new Handler1();
	Handler2* two	= new Handler2();
	Handler3* thr	= new Handler3();

	root->add(two);
	root->add(thr);
	thr->setNext(root);

	for (int i = 1; i < 10; i++)
	{
		root->handle(i);
		std::cout << std::endl;
		// ...
	}

	delete thr;
	delete two;
	delete root;

	return 0;
}
