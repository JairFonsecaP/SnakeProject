#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "Console.h"

namespace utility
{
	class ConsoleReader
	{
	private:
		const HANDLE handle;

	public:
		ConsoleReader();

		bool isReturnPressed();
		bool isSpacePressed();
		bool isControlPressed();
		bool isShiftPressed();
		bool isEscapePressed();
		bool isUpArrowPressed();
		bool isDownArrowPressed();
		bool isLeftArrowPressed();
		bool isRightArrowPressed();
		bool isKeyPressed(int key);

		char readCharacter();
		char readCharacter(char options[], int optionsCount);
		char readCharacter(std::string message);
		char readCharacter(std::string message, char options[], int optionsCount);

		std::string readWord();
		std::string readWord(std::string message);

		std::string readLine();
		std::string readLine(std::string message);

		int readInteger();
		int readInteger(int min, int max);
		int readInteger(std::string message);
		int readInteger(std::string message, int min, int max);

		double readDouble();
		double readDouble(double min, double max);
		double readDouble(std::string message);
		double readDouble(std::string message, double min, double max);
	};
}
