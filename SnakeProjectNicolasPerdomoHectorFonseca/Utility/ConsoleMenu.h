#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Console.h"

namespace utility
{
	class ConsoleMenu
	{
	private:
		std::string title;
		std::string message;
		std::vector<std::string> options;

	public:
		ConsoleMenu(std::string title, std::string message, std::vector<std::string> options);
		ConsoleMenu();

		std::string getTitle() const;
		std::string getMessage() const;
		std::string getOption(int index) const;
		int getSize() const;

		void setTitle(std::string title);
		void setMessage(std::string message);
		void setOptions(std::vector<std::string> options);

		void displayTitle() const;
		void displayMessage() const;
		void displayOptions() const;
		void displayMenu() const;

		int getSelection() const;
		int getSelectionIndex() const;

	private:
		static const std::string separator;
	public:
		static std::string getSeparator();
		static void displaySeparator();
	};
}
