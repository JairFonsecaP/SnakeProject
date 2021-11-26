#include "ConsoleReader.h"

namespace utility
{
	ConsoleReader::ConsoleReader()
		: handle(GetStdHandle(STD_OUTPUT_HANDLE))
	{ }

	bool ConsoleReader::isReturnPressed()
	{
		return isKeyPressed(VK_RETURN);
	}

	bool ConsoleReader::isSpacePressed()
	{
		return isKeyPressed(VK_SPACE);
	}

	bool ConsoleReader::isControlPressed()
	{
		return isKeyPressed(VK_CONTROL);
	}

	bool ConsoleReader::isShiftPressed()
	{
		return isKeyPressed(VK_SHIFT);
	}

	bool ConsoleReader::isEscapePressed()
	{
		return isKeyPressed(VK_ESCAPE);
	}

	bool ConsoleReader::isUpArrowPressed()
	{
		return isKeyPressed(VK_UP);
	}

	bool ConsoleReader::isDownArrowPressed()
	{
		return isKeyPressed(VK_DOWN);
	}

	bool ConsoleReader::isLeftArrowPressed()
	{
		return isKeyPressed(VK_LEFT);
	}

	bool ConsoleReader::isRightArrowPressed()
	{
		return isKeyPressed(VK_RIGHT);
	}

	bool ConsoleReader::isKeyPressed(int key)
	{
		SHORT keyState = GetKeyState(key);
		bool pressed = keyState & 0x8000;
		return pressed;
	}

	char ConsoleReader::readCharacter()
	{
		return Console::readCharacter();
	}

	char ConsoleReader::readCharacter(char options[], int optionsCount)
	{
		return Console::readCharacter(options, optionsCount);
	}

	char ConsoleReader::readCharacter(std::string message)
	{
		return Console::readCharacter(message);
	}

	char ConsoleReader::readCharacter(std::string message, char options[], int optionsCount)
	{
		return Console::readCharacter(message, options, optionsCount);
	}

	std::string ConsoleReader::readWord()
	{
		return Console::readWord();
	}

	std::string ConsoleReader::readWord(std::string message)
	{
		return Console::readWord(message);
	}

	std::string ConsoleReader::readLine()
	{
		return Console::readLine();
	}

	std::string ConsoleReader::readLine(std::string message)
	{
		return Console::readLine(message);
	}

	int ConsoleReader::readInteger()
	{
		return Console::readInteger();
	}

	int ConsoleReader::readInteger(int min, int max)
	{
		return Console::readInteger(min, max);
	}

	int ConsoleReader::readInteger(std::string message)
	{
		return Console::readInteger(message);
	}

	int ConsoleReader::readInteger(std::string message, int min, int max)
	{
		return Console::readInteger(message, min, max);
	}

	double ConsoleReader::readDouble()
	{
		return Console::readDouble();
	}

	double ConsoleReader::readDouble(double min, double max)
	{
		return Console::readDouble(min, max);
	}

	double ConsoleReader::readDouble(std::string message)
	{
		return Console::readDouble(message);
	}

	double ConsoleReader::readDouble(std::string message, double min, double max)
	{
		return Console::readDouble(message, min, max);
	}
}
