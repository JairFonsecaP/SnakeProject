#include "ConsoleWriter.h"

namespace utility
{
	ConsoleWriter::ConsoleWriter()
		: handle(GetStdHandle(STD_OUTPUT_HANDLE))
	{ }

	void ConsoleWriter::clear()
	{
		system("CLS");
	}

	void ConsoleWriter::clearRegion(int left, int top, int right, int bottom)
	{
		clearRegion({ (SHORT)left, (SHORT)top }, { (SHORT)right, (SHORT)bottom });
	}

	void ConsoleWriter::clearRegion(COORD topLeft, COORD bottomRight)
	{
		fillRegion(' ', topLeft, bottomRight);
	}

	void ConsoleWriter::fillRegion(char character, int left, int top, int right, int bottom)
	{
		fillRegion(character, { (SHORT)left, (SHORT)top }, { (SHORT)right, (SHORT)bottom });
	}

	void ConsoleWriter::fillRegion(char character, COORD topLeft, COORD bottomRight)
	{
		COORD originalCursorPosition = getCursorPosition();
		for (int y = topLeft.Y; y <= bottomRight.Y; y++)
		{
			for (int x = topLeft.X; x <= bottomRight.X; x++)
			{
				setCursorPosition(x, y);
				std::cout << character;
			}
		}
		setCursorPosition(originalCursorPosition);
	}

	void ConsoleWriter::drawRectangle(int left, int top, int right, int bottom)
	{
		drawRectangle({ (SHORT)left, (SHORT)top }, { (SHORT)right, (SHORT)bottom });
	}

	void ConsoleWriter::drawRectangle(COORD topLeft, COORD bottomRight)
	{
		COORD originalCursorPosition = getCursorPosition();

		setCursorPosition(topLeft);
		std::cout << (char)201;  // top left corner
		for (int i = topLeft.X + 1; i < bottomRight.X; i++)
			std::cout << (char)205; // top horizontal line
		std::cout << (char)187;  // top right corner
		for (int i = topLeft.Y + 1; i < bottomRight.Y; i++)
		{
			setCursorPosition(topLeft.X, i);
			std::cout << (char)186;  // left vertical line
			setCursorPosition(bottomRight.X, i);
			std::cout << (char)186;  // right vertical line
		}
		setCursorPosition(topLeft.X, bottomRight.Y);
		std::cout << (char)200;  // bottom left corner
		for (int i = topLeft.X + 1; i < bottomRight.X; i++)
			std::cout << (char)205;  // bottom horizontal line
		std::cout << (char)188;  // bottom right corner

		setCursorPosition(originalCursorPosition);
	}

	void ConsoleWriter::setWindowSize(int width, int height)
	{
		setWindowSize({ (SHORT)width, (SHORT)height});
	}
	
	void ConsoleWriter::setWindowSize(COORD size)
	{
		COORD maxSize = GetLargestConsoleWindowSize(handle);
		if (size.X > maxSize.X)
			size.X = maxSize.X;
		if (size.Y > maxSize.Y)
			size.Y = maxSize.Y;
		
		SetConsoleScreenBufferSize(handle, size);

		const SMALL_RECT windowRectangle = { 0, 0, size.X - 1, size.Y - 1 };
		SetConsoleWindowInfo(handle, true, &windowRectangle);
	}

	void ConsoleWriter::setCursorVisible(bool visible)
	{
		CONSOLE_CURSOR_INFO cursor;
		GetConsoleCursorInfo(handle, &cursor);
		cursor.bVisible = visible;
		SetConsoleCursorInfo(handle, &cursor);
	}

	void ConsoleWriter::setCursorPosition(int x, int y)
	{
		setCursorPosition({ (SHORT)x, (SHORT)y });
	}

	void ConsoleWriter::setCursorPosition(COORD position)
	{
		std::cout.flush(); // displays pending characters in the stream
		SetConsoleCursorPosition(handle, position);
	}

	void ConsoleWriter::setCharacterAtPosition(int x, int y, char character)
	{
		setCharacterAtPosition({ (SHORT)x, (SHORT)y }, character);
	}

	void ConsoleWriter::setCharacterAtPosition(COORD position, char character)
	{
		COORD originalCursorPosition = getCursorPosition();
		setCursorPosition(position);
		std::cout << character;
		setCursorPosition(originalCursorPosition);
	}

	COORD ConsoleWriter::getCursorPosition()
	{
		std::cout.flush();
		CONSOLE_SCREEN_BUFFER_INFO buffer;
		GetConsoleScreenBufferInfo(handle, &buffer);
		return buffer.dwCursorPosition;
	}

	char ConsoleWriter::getCharacterAtPosition(int x, int y)
	{
		return getCharacterAtPosition({ (SHORT)x, (SHORT)y });
	}
	
	char ConsoleWriter::getCharacterAtPosition(COORD position)
	{
		CHAR_INFO buffer;
		COORD dwBufferSize = { 1, 1 };
		COORD dwBufferCoordinate = { 0, 0 };
		SMALL_RECT readRegion;

		readRegion.Top = readRegion.Bottom = position.Y;
		readRegion.Left = readRegion.Right = position.X;

		bool success = ReadConsoleOutput(handle, &buffer, dwBufferSize, dwBufferCoordinate, &readRegion);
		if (success)
		{
			return buffer.Char.AsciiChar;
		}
		else
		{
			Console::writeLine("ReadConsoleOutput failed: %d", GetLastError());
			return 1;
		}
	}

	void ConsoleWriter::write(char character)
	{
		Console::write(character);
	}
	
	void ConsoleWriter::write(std::string message)
	{
		Console::write(message);
	}

	void ConsoleWriter::write(std::string message, unsigned int indentation)
	{
		Console::write(message, indentation);
	}

	void ConsoleWriter::writeLine()
	{
		Console::writeLine();
	}

	void ConsoleWriter::writeLine(char character)
	{
		Console::writeLine(character);
	}

	void ConsoleWriter::writeLine(std::string message)
	{
		Console::writeLine(message);
	}

	void ConsoleWriter::writeLine(std::string message, unsigned int indentation)
	{
		Console::writeLine(message, indentation);
	}

	void ConsoleWriter::pause()
	{
		Console::pause();
	}
}
