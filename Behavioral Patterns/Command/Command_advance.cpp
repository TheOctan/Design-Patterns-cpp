/*
 * C++ Design Patterns: Commnand
 *
 * Command pattern encapsulates a request as an object, thereby letting you parameterize
 * clients with different requests, queue or log requests, and supports undoable
 * operations. The pattern has a behavioral purpose and deals with relationships between objects.
 *
 */

#include<iostream>
#include<vector>
#include<string>

/*
 * ### When to use ###
 *
 * want to parameterize objects by an action to perform
 * want to specify, queue, and execute requests at different times
 * support undo
 * support logging changes so that they can be reapplied in case of a system crash
 * structure a system around high-level operations built on primitives operations
 */

// ...
class Game
{
public:
	void create()
	{
		std::cout << "Crete game " << std::endl;
	}
	void open(std::string file)
	{
		std::cout << "Open game from " << file << std::endl;
	}
	void save(std::string file)
	{
		std::cout << "Save game in " << file << std::endl;
	}
	void makeMove(std::string move)
	{
		std::cout << "Make move " << move << std::endl;
	}
};

std::string getPlayerInput(std::string promt)
{
	std::string input;
	std::cout << promt;
	std::cin >> input;

	return input;
}

// declares an interface for all commands
class Command
{
public:
	virtual ~Command()		= default;
	virtual void execute()	= 0;
	// ...

protected:
	Command(Game* ptr) : p_game(ptr) {}
	Game* p_game;
};

// implements execute by invoking the corresponding
// operation(s) on Receiver
#pragma region Concrete Command

class CreateGameCommand : public Command
{
public:
	CreateGameCommand(Game* ptr)
		: Command(ptr)
	{
	}
	void execute() override
	{
		p_game->create();
	}
	// ...
};

class OpenGameCommand : public Command
{
public:
	OpenGameCommand(Game* ptr)
		: Command(ptr)
	{
	}
	void execute() override
	{
		std::string fileName = getPlayerInput("Enter file name: ");
		p_game->open(fileName);
	}
	// ...
};

class SaveGameCommand : public Command
{
public:
	SaveGameCommand(Game* ptr)
		: Command(ptr)
	{
	}
	void execute() override
	{
		std::string fileName = getPlayerInput("Enter file name: ");
		p_game->save(fileName);
	}
	// ...
};

class MakeMoveCommand : public Command
{
public:
	MakeMoveCommand(Game* ptr)
		: Command(ptr)
	{
	}
	void execute() override
	{
		p_game->save("TEMP_FILE");
		std::string move = getPlayerInput("Enter your move: ");
		p_game->makeMove(move);
	}
};

class UndoCommand : public Command
{
public:
	UndoCommand(Game* ptr)
		: Command(ptr)
	{
	}
	void execute() override
	{
		p_game->open("TEMP_FILE");
	}
};

#pragma endregion


int main()
{
	Game* game = new Game();

	std::vector<Command*> commands;
	commands.push_back(new CreateGameCommand(game));

	commands.push_back(new MakeMoveCommand(game));	// E2-E4
	commands.push_back(new MakeMoveCommand(game));	// D2-D3

	commands.push_back(new UndoCommand(game));
	commands.push_back(new SaveGameCommand(game));	// game1.sav
	
	for (auto obj : commands)
		obj->execute();
	// ...

	for (auto obj : commands)
		delete obj;
	delete game;

	return 0;
}
