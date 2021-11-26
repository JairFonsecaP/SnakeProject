#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Console.h"

namespace utility
{
	class ConsoleWriter
	{
	private:
		const HANDLE handle;

	public:
		ConsoleWriter();

		void clear();
		void clearRegion(int left, int top, int right, int bottom);
		void clearRegion(COORD topLeft, COORD bottomRight);
		void fillRegion(char character, int left, int top, int right, int bottom);
		void fillRegion(char character, COORD topLeft, COORD bottomRight);
		void drawRectangle(int left, int top, int right, int bottom);
		void drawRectangle(COORD topLeft, COORD bottomRight);

		void setWindowSize(int width, int height);
		void setWindowSize(COORD size);
		void setCursorVisible(bool visible);
		void setCursorPosition(int x, int y);
		void setCursorPosition(COORD position);
		void setCharacterAtPosition(int x, int y, char character);
		void setCharacterAtPosition(COORD position, char character);

		COORD getCursorPosition();
		char getCharacterAtPosition(int x, int y);
		char getCharacterAtPosition(COORD position);

		void write(char character);
		void write(std::string message);
		void write(std::string message, unsigned int indentation);

		void writeLine();
		void writeLine(char character);
		void writeLine(std::string message);
		void writeLine(std::string message, unsigned int indentation);

		void pause();
	};
}

