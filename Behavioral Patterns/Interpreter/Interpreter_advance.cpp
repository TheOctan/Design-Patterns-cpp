/*
 * C++ Design Patterns: Interpreter
 *
 * Given a language, the pattern defines a represention for its grammar along with an
 * interpreter that uses the representation to interpret sentences in the language.
 * The Interpreter pattern has behavioral purpose and applies to the classes.
 *
 */

#include<iostream>
#include<string>

/*
 * ### When to use ###
 *
 * when the grammar is simple (in case of complex grammars, there are better alternatives)
 * efficiency is not a critical concern
 *
 */

class Thousand;
class Hundred;
class Ten;
class One;

// Nonterminal Expression
// implements an Interpret operation for nonterminal symbols
// in the grammar(one such class is required for every rule in the grammar)
class RNInterpreter
{
public:
	RNInterpreter();
	RNInterpreter(int) {}

	int interpret(char*);
	virtual void interpret(char* input, int& total)
	{
		int index = 0;
		
		if (!strncmp(input, nine(), 2))
		{
			total += 9 * multiplier();
			index += 2;
		}
		else if (!strncmp(input, four(), 2))
		{
			total += 4 * multiplier();
			index += 2;
		}
		else
		{
			if (input[0] == five())
			{
				total += 5 * multiplier();
				index = 1;
			}
			else
			{
				index = 0;
			}

			for (int end = index + 3; index < end; index++)
			{
				if (input[index] == one())
					total += 1 * multiplier();
				else break;
			}
		}
		strcpy_s(input, 20, &(input[index]));
	}

protected:
	virtual char		one () { return ' '; }
	virtual const char* four() { return "";  }
	virtual char		five() { return ' '; }
	virtual const char* nine() { return "";  }
	virtual int			multiplier() { return 0; }

private:
	RNInterpreter* thousands;
	RNInterpreter* hundreds;
	RNInterpreter* tens;
	RNInterpreter* ones;
};

// Terminal Expression
// implements an Interpret operation associated with terminal symbols
// in the grammar(an instance is required for every terminal symbol
// in a sentence)
#pragma region SubInterprets

class Thousand : public RNInterpreter
{
public:
	Thousand(int) : RNInterpreter(1) {}

protected:
	char one() override
	{
		return 'M';
	}
	const char* four() override
	{
		return "";
	}
	char five() override
	{
		return '\0';
	}
	const char* nine() override
	{
		return "";
	}
	int multiplier() override
	{
		return 1000;
	}
};

class Hundred : public RNInterpreter
{
public:
	Hundred(int) : RNInterpreter(1) {}

protected:
	char one() override
	{
		return 'C';
	}
	const char* four() override
	{
		return "CD";
	}
	char five() override
	{
		return 'D';
	}
	const char* nine() override
	{
		return "CM";
	}
	int multiplier() override
	{
		return 100;
	}
};

class Ten : public RNInterpreter
{
public:
	Ten(int) : RNInterpreter(1) {}

protected:
	char one() override
	{
		return 'X';
	}
	const char* four() override
	{
		return "XL";
	}
	char five() override
	{
		return 'L';
	}
	const char* nine() override
	{
		return "XC";
	}
	int multiplier() override
	{
		return 10;
	}
};

class One : public RNInterpreter
{
public:
	One(int) : RNInterpreter(1) {}

protected:
	char one() override
	{
		return 'I';
	}
	const char* four() override
	{
		return "IV";
	}
	char five() override
	{
		return 'V';
	}
	const char* nine() override
	{
		return "IX";
	}
	int multiplier() override
	{
		return 1;
	}
};

#pragma endregion

RNInterpreter::RNInterpreter()
{
	thousands	= new Thousand(1);
	hundreds	= new Hundred(1);
	tens		= new Ten(1);
	ones		= new One(1);
}

int RNInterpreter::interpret(char* input)
{
	int total = 0;

	thousands->interpret(input, total);
	hundreds->interpret(input, total);
	tens->interpret(input, total);
	ones->interpret(input, total);

	if (input == "")
		return 0;

	return total;
}

int main()
{
	RNInterpreter interpreter;
	char input[20];

	std::cout << "Enter Roman Numeral: ";
	while (std::cin >> input)
	{
		std::cout << "\tinterpretation is "
			<< interpreter.interpret(input) << std::endl;
		std::cout << "Enter Roman Numeral: ";
	}

	//romanNumeral :: = { thousands } {hundreds} {tens} {ones}
	//thousands, hundreds, tens, ones :: = nine | four | {five} {one} {one} {one}
	//nine :: = "CM" | "XC" | "IX"
	//four :: = "CD" | "XL" | "IV"
	//five :: = 'D' | 'L' | 'V'
	//one  :: = 'M' | 'C' | 'X' | 'I'

	return 0;
}
