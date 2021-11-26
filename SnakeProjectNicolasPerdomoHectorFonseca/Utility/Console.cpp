#include "Console.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace utility
{
	char Console::readCharacter()
	{
		char character;
		cin >> character;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return character;
	}

	char Console::readCharacter(char options[], int optionsCount)
	{
		while (true)
		{
			char character = readCharacter();
			for (int i = 0; i < optionsCount; i++)
			{
				if (options[i] == character)
					return character;
			}

			cout << "    Error: Invalid character. '"
				<< character << "' is not in the set of options { ";
			for (int i = 0; i < optionsCount; i++)
				cout << options[i] << " ";
			cout << "}" << endl;
		}
	}

	char Console::readCharacter(string message)
	{
		Console::writeLine(message);
		return readCharacter();
	}

	char Console::readCharacter(string message, char options[], int optionsCount)
	{
		Console::writeLine(message);
		return readCharacter(options, optionsCount);
	}

	string Console::readWord()
	{
		string cinWord;
		cin >> cinWord;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinWord;
	}

	string Console::readWord(string message)
	{
		Console::writeLine(message);
		return readWord();
	}

	string Console::readLine()
	{
		string cinLine;
		std::getline(cin, cinLine);
		return cinLine;
	}

	string Console::readLine(string message)
	{
		Console::writeLine(message);
		return readLine();
	}

	int Console::readInteger()
	{
		int cinInt;
		cin >> cinInt;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "    Error: Invalid integer format" << endl;
			cin >> cinInt;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinInt;
	}

	int Console::readInteger(int min, int max)
	{
		int cinInt = readInteger();
		while (cinInt < min || cinInt > max)
		{
			cout << "    Error: Out of bounds. " << cinInt << " is not between " << min << " and " << max << endl;
			cinInt = readInteger();
		}
		return cinInt;
	}

	int Console::readInteger(string message)
	{
		Console::writeLine(message);
		return readInteger();
	}

	int Console::readInteger(string message, int min, int max)
	{
		Console::writeLine(message);
		return readInteger(min, max);
	}

	double Console::readDouble()
	{
		double cinDouble;
		cin >> cinDouble;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "    Error: Invalid number format" << endl;
			cin >> cinDouble;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return cinDouble;
	}

	double Console::readDouble(double min, double max)
	{
		double cinDouble = readDouble();
		while (cinDouble < min || cinDouble > max)
		{
			cout << "    Error: Out of bounds. " << cinDouble << " is not between " << min << " and " << max << endl;
			cinDouble = readDouble();
		}
		return cinDouble;
	}

	double Console::readDouble(string message)
	{
		Console::writeLine(message);
		return readDouble();
	}

	double Console::readDouble(string message, double min, double max)
	{
		Console::writeLine(message);
		return readDouble(min, max);
	}

	void Console::write(char character)
	{
		cout << character;
	}

	void Console::write(std::string message)
	{
		cout << message;
	}

	void Console::write(std::string message, unsigned int indentation)
	{
		for (unsigned int i = 0; i < indentation; i++)
			write("    ");
		write(message);
	}

	void Console::writeLine()
	{
		cout << endl;
	}

	void Console::writeLine(char character)
	{
		write(character);
		writeLine();
	}

	void Console::writeLine(std::string message)
	{
		write(message);
		writeLine();
	}

	void Console::writeLine(std::string message, unsigned int indentation)
	{
		write(message, indentation);
		writeLine();
	}

	void Console::pause()
	{
		int character = cin.get();
		std::streamsize cinBufferSize = cin.rdbuf()->in_avail();
		if (cinBufferSize > 0)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void Console::clear()
	{
		system("CLS");
	}
}
