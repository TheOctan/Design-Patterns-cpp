/*
* C++ Design Patterns: Flyweight
*
* Flyweight pattern has has structural purpose, applies to objects and uses sharing to support
* large numbers of fine-grained objects efficiently. The pattern can be used to reduce
* memory usage when you need to create a large number of similar objects.
*
*/

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * when one instance of a class can be used to provide many "virtual instances"
 * when all of the following are true
 * an application uses a large number of objects
 * storage costs are high because of the sheer quantity of objects
 * most object state can be made extrinsic
 * many groups of objects may be replaced by relatively few shared objects once extrinsic state is removed
 * the application doesn't depend on object identity
 *
 */

#define MAX_ICONS 5

// declares an interface through which flyweights can receive
// and act on extrinsic state
#pragma region Flyweight

class Icon
{
public:
	Icon(std::string fileName)
	{
		_name = fileName;
		if (fileName == "go")
		{
			_width = 20;
			_height = 20;
		}
		if (fileName == "stop")
		{
			_width = 40;
			_height = 40;
		}
		if (fileName == "select")
		{
			_width = 60;
			_height = 60;
		}
		if (fileName == "undo")
		{
			_width = 30;
			_height = 30;
		}
	}

	std::string getName()
	{
		return _name;
	}
	void draw(int x, int y)
	{
		std::cout << "\tdrawing " << _name
			<< ": upper left (" << x << "," << y
			<< ") - lower rigth (" << x + _width << ","
			<< y + _height << ")" << std::endl;
	}
	// ...

private:
	std::string _name;
	int _width;
	int _height;
	// ...
};

// Flyweight
class DialogBox
{
public:
	DialogBox(int x, int y, int incr)
	:	_iconsOriginX(x),
		_iconsOriginY(y),
		_iconsXIncrement(incr)
	{
	}

	virtual void draw() = 0;
	// ...

protected:
	Icon * _icons[3];
	int _iconsOriginX;
	int _iconsOriginY;
	int _iconsXIncrement;
	// ...
};

#pragma endregion

// adds storage for intrinsic state
#pragma region ConcreteFlyweight

class FileSelection : public DialogBox
{
public:
	FileSelection(Icon* first, Icon* second, Icon* third)
		: DialogBox(100, 100, 100)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	}
	void draw() override
	{
		std::cout << "Drawing FileSelection: " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			_icons[i]->draw(_iconsOriginX + (i*_iconsXIncrement), _iconsOriginY);
		}
	}
	// ...
};

class CommitTransaction : public DialogBox
{
public:
	CommitTransaction(Icon* first, Icon* second, Icon* third)
		: DialogBox(150, 150, 150)
	{
		_icons[0] = first;
		_icons[1] = second;
		_icons[2] = third;
	}
	void draw() override
	{
		std::cout << "Drawing CommitTransaction: " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			_icons[i]->draw(_iconsOriginX + (i*_iconsXIncrement), _iconsOriginY);
		}
	}
	// ...
};

#pragma endregion

// creates and manages flyweight objects and ensures
// that flyweights are shared properly
#pragma region Factory

class FlyweightFactory
{
public:
	static Icon* getIcon(std::string name)
	{
		for (int i = 0; i < _numIcons; i++)
		{
			if (_icons[i]->getName() == name)
			{
				return _icons[i];
			}
		}
		_icons[_numIcons] = new Icon(name);
		return _icons[_numIcons++];
	}
	static void reportTheIcons()
	{
		std::cout << "Active Flyweights: ";
		for (int i = 0; i < _numIcons; i++)
		{
			std::cout << _icons[i]->getName() << " ";
		}
		std::cout << std::endl;
	}
	// ...

private:
	static int _numIcons;
	static Icon* _icons[MAX_ICONS];
	// ...
};

int FlyweightFactory::_numIcons = 0;
Icon* FlyweightFactory::_icons[];

#pragma endregion

int main()
{
	DialogBox* dialogs[2];

	dialogs[0] = new FileSelection(
		FlyweightFactory::getIcon("go"),
		FlyweightFactory::getIcon("stop"),
		FlyweightFactory::getIcon("select")
	);

	dialogs[1] = new CommitTransaction(
		FlyweightFactory::getIcon("select"),
		FlyweightFactory::getIcon("stop"),
		FlyweightFactory::getIcon("undo")
	);

	for (int i = 0; i < 2; i++)
		dialogs[i]->draw();
	// ...

	FlyweightFactory::reportTheIcons();

	return 0;
}
