/*
 * C++ Design Patterns: Bridge
 *
 * Decouple an abstraction from its implementation so that the two can vary independently.
 * Bridge pattern has structural purpose and applies to objects, so it deals with the composition of objects.
 *
 */

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * you want to avoid a permanent binding between an abstraction and its implementation
 * both the abstractions and their implementations should be extensible by subclassing
 * changes in the implementation of an abstraction should have no impact on clients
 * you want to hide the implementation of an abstraction completely from clients
 *
 */

// Implementations classes
#pragma region Implementation

class LoggerImpl
{
public:
	virtual		~LoggerImpl()												= default;
	virtual void consoleLog	(std::string& str)								= 0;
	virtual void fileLog	(std::string& file, std::string& str)			= 0;
	virtual void socketLog	(std::string& host, int port, std::string& str)	= 0;
	// ...
};

class ST_LoggerImpl : public LoggerImpl
{
public:
	void consoleLog	(std::string& str)								override;
	void fileLog	(std::string& file, std::string& str)			override;
	void socketLog	(std::string& host, int port, std::string& str) override;
	// ...
};

class MT_LoggerImpl : public LoggerImpl
{
public:
	void consoleLog	(std::string& str)								override;
	void fileLog	(std::string& file, std::string& str)			override;
	void socketLog	(std::string& host, int port, std::string& str)	override;
	// ...
};

#pragma endregion

// Abstractions classes
#pragma region Abstraction

class Logger
{
public:
	Logger(LoggerImpl* ptr);
	virtual		~Logger();
	virtual void log(std::string str)	= 0;
	// ...

protected:
	LoggerImpl * _ptr;
};

class ConsoleLogger : public Logger
{
public:
	ConsoleLogger();
	void log(std::string str) override;
	// ...
};

class FileLogger : public Logger
{
public:
	FileLogger	(std::string fileName);
	void log	(std::string str) override;
	// ...

private:
	std::string file;
};

class SocketLogger : public Logger
{
public:
	SocketLogger(std::string remoteHost, int remotePort);
	void log	(std::string str) override;
	// ...

private:
	std::string host;
	int			port;
};

#pragma endregion

//#define MT	// <- Uncomment this line to change the mode of the logger

int main()
{
	Logger* mas[]{
		new ConsoleLogger(),
		new FileLogger("log.txt"),
		new SocketLogger("root@tecmint", 8910)
		// ...
	};

	for (auto& object : mas)
	{
		object->log("message");
		std::cout << std::endl;
	}
	// ...

	return 0;
}

#pragma region Implementation

void ST_LoggerImpl::consoleLog(std::string & str)
{
	std::cout << "Single-threaded console logger" << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

void ST_LoggerImpl::fileLog(std::string& file, std::string& str)
{
	std::cout << "Single-threaded file logger" << std::endl;
	std::cout << "File name:" << file << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

void ST_LoggerImpl::socketLog(std::string& host, int port, std::string& str)
{
	std::cout << "Single-threaded socket logger" << std::endl;
	std::cout << "Host: " << host << std::endl;
	std::cout << "Port: " << port << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

void MT_LoggerImpl::consoleLog(std::string & str)
{
	std::cout << "Multithreaded console logger" << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

void MT_LoggerImpl::fileLog(std::string& file, std::string& str)
{
	std::cout << "Multithreaded file logger" << std::endl;
	std::cout << "File name:" << file << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

void MT_LoggerImpl::socketLog(std::string& host, int port, std::string& str)
{
	std::cout << "Multithreaded socket logger" << std::endl;
	std::cout << "Host: " << host << std::endl;
	std::cout << "Port: " << port << std::endl;
	std::cout << "Message: " << str << std::endl;
	// ...
}

#pragma endregion

#pragma region Abstraction

Logger::Logger(LoggerImpl * ptr) : _ptr(ptr)
{
}

Logger::~Logger()
{
	delete _ptr;
}

ConsoleLogger::ConsoleLogger()
:	Logger(
#ifdef MT
		new MT_LoggerImpl()
#else
		new ST_LoggerImpl()
#endif // MT
	)
{
}

void ConsoleLogger::log(std::string str)
{
	_ptr->consoleLog(str);
}

FileLogger::FileLogger(std::string fileName)
:	Logger(
#ifdef MT
		new MT_LoggerImpl()
#else
		new ST_LoggerImpl()
#endif // MT
	), file(fileName)
{
}

void FileLogger::log(std::string str)
{
	_ptr->fileLog(file, str);
}

SocketLogger::SocketLogger(std::string remoteHost, int remotePort)
:	Logger(
#ifdef MT
		new MT_LoggerImpl()
#else
		new ST_LoggerImpl()
#endif // MT
	),
	host(remoteHost),
	port(remotePort)
{

}

void SocketLogger::log(std::string str)
{
	_ptr->socketLog(host, port, str);
}

#pragma endregion
