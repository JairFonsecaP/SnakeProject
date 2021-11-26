#pragma once
#include <iostream>
#include <string>

namespace utility
{
	class Console
	{
	public:
		static char readCharacter();
		static char readCharacter(char options[], int optionsCount);
		static char readCharacter(std::string message);
		static char readCharacter(std::string message, char options[], int optionsCount);

		static std::string readWord();
		static std::string readWord(std::string message);

		static std::string readLine();
		static std::string readLine(std::string message);

		static int readInteger();
		static int readInteger(int min, int max);
		static int readInteger(std::string message);
		static int readInteger(std::string message, int min, int max);

		static double readDouble();
		static double readDouble(double min, double max);
		static double readDouble(std::string message);
		static double readDouble(std::string message, double min, double max);
		
		static void write(char character);
		static void write(std::string message);
		static void write(std::string message, unsigned int indentation);
		
		static void writeLine();
		static void writeLine(char character);
		static void writeLine(std::string message);
		static void writeLine(std::string message, unsigned int indentation);

		static void pause();
		static void clear();
	};
}
