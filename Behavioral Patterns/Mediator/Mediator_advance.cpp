/*
 * C++ Design Patterns: Mediator
 *
 * Mediator pattern has behavioral purpose and applies on objects.
 * The pattern defines an object that encapsulates how a set of objects interact.
 * It promotes loose coupling by keeping objects from referring to each
 * other explicitly, and it lets you vary their interaction independently.
 *
 */

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * a set of objects communicate in well-defined but complex ways
 * reusing an object is difficult because it refers to and communicates with many other objects
 * a behavior that's distributed between several classes should be customizable without a lot of subclassing
 *
 */

class FileSelectionDialog;

// each colleague communicates with its mediator whenever
// it would have otherwise communicated with another colleague
#pragma region Colleague Classes

class Widget
{
public:
	Widget(FileSelectionDialog* mediator, std::string name)
	{
		_mediator = mediator;
		_name = name;
	}
	virtual void changed();
	virtual void updateWidget() = 0;
	virtual void queryWidget() = 0;

protected:
	std::string _name;
private:
	FileSelectionDialog * _mediator;
};

class List : public Widget
{
public:
	List(FileSelectionDialog* dir, std::string name)
		: Widget(dir, name)
	{
	}

	void queryWidget() override
	{
		std::cout << "\t" << _name << " list queried" << std::endl;
	}
	void updateWidget() override
	{
		std::cout << "\t" << _name << " list updated" << std::endl;
	}
};

class Edit : public Widget
{
public:
	Edit(FileSelectionDialog* dir, std::string name)
		: Widget(dir, name)
	{
	}

	void queryWidget() override
	{
		std::cout << "\t" << _name << " edit queried" << std::endl;
	}
	void updateWidget() override
	{
		std::cout << "\t" << _name << " edit updated" << std::endl;
	}
};

#pragma endregion

// Mediator
// implements cooperative behavior by coordinating Colleague objects
// and knows its colleagues
class FileSelectionDialog
{
public:
	enum Widgets
	{
		FilterEdit = 0,
		DirList,
		FileList,
		SelectionEdit
	};

	FileSelectionDialog()
	{
		_components[Widgets::FilterEdit]	= new Edit(this, "filter");
		_components[Widgets::DirList]		= new List(this, "dir");
		_components[Widgets::FileList]		= new List(this, "file");
		_components[Widgets::SelectionEdit] = new Edit(this, "selection");
	}
	virtual ~FileSelectionDialog();
	
	void handleEvent(int which)
	{
		_components[which]->changed();
	}
	virtual void widgetChanged(Widget* theChangeWidget)
	{
		if (theChangeWidget == _components[Widgets::FilterEdit])
		{
			_components[Widgets::FilterEdit]->queryWidget();
			_components[Widgets::DirList]->updateWidget();
			_components[Widgets::FileList]->updateWidget();
			_components[Widgets::SelectionEdit]->updateWidget();
		}
		else if (theChangeWidget == _components[Widgets::DirList])
		{
			_components[Widgets::DirList]->queryWidget();
			_components[Widgets::FilterEdit]->updateWidget();
			_components[Widgets::FileList]->updateWidget();
			_components[Widgets::SelectionEdit]->updateWidget();
		}
		else if (theChangeWidget == _components[Widgets::FileList])
		{
			_components[Widgets::FileList]->queryWidget();
			_components[Widgets::SelectionEdit]->updateWidget();
		}
		else if (theChangeWidget == _components[Widgets::SelectionEdit])
		{
			_components[Widgets::SelectionEdit]->queryWidget();
			std::cout << "\tfile opened" << std::endl;
		}
	}

private:
	Widget* _components[4];
};

FileSelectionDialog::~FileSelectionDialog()
{
	for (auto obj : _components)
		delete obj;
}

void Widget::changed()
{
	_mediator->widgetChanged(this);
}

int main()
{
	FileSelectionDialog fileDialog;
	int i;

	std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
	std::cin >> i;

	while (i)
	{
		fileDialog.handleEvent(i - 1);
		std::cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
		std::cin >> i;
	}

	return 0;
}
