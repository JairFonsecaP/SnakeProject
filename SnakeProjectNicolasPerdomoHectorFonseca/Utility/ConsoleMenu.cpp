#include "ConsoleMenu.h"
using std::cin;
using std::endl;
using std::string;
using std::to_string;

namespace utility
{
	// Instance members

	ConsoleMenu::ConsoleMenu(std::string title, std::string message, std::vector<std::string> options)
		: title(title), message(message), options(options)
	{ }

	ConsoleMenu::ConsoleMenu()
		: title(), message(), options()
	{ }

	string ConsoleMenu::getTitle() const
	{
		return title;
	}

	string ConsoleMenu::getMessage() const
	{
		return message;
	}

	string ConsoleMenu::getOption(int index) const
	{
		if (index >= 0 && index < getSize())
			return options[index];
		else
			return string();
	}

	int ConsoleMenu::getSize() const
	{
		return (int) options.size();
	}

	void ConsoleMenu::setTitle(string title)
	{
		this->title = title;
	}

	void ConsoleMenu::setMessage(string message)
	{
		this->message = message;
	}

	void ConsoleMenu::setOptions(std::vector<std::string> options)
	{
		this->options = options;
	}

	void ConsoleMenu::displayTitle() const
	{
		if (title.length() > 0)
		{
			Console::writeLine(title);
			Console::writeLine();
		}
	}

	void ConsoleMenu::displayMessage() const
	{
		if (message.length() > 0)
		{
			Console::writeLine(message);
			Console::writeLine();
		}
	}

	void ConsoleMenu::displayOptions() const
	{
		const unsigned int indentation = 1;
		for (int i = 0; i < getSize(); i++)
		{
			Console::writeLine(to_string(i + 1) + " - " + options[i], indentation);
		}
		Console::writeLine();
	}

	void ConsoleMenu::displayMenu() const
	{
		displaySeparator();
		displayTitle();
		displayOptions();
	}

	int ConsoleMenu::getSelection() const
	{
		int min = 1;
		int max = (int) options.size();

		int userInt;
		if (message.length() > 0)
			userInt = Console::readInteger(message, min, max);
		else
			userInt = Console::readInteger(min, max);
		Console::writeLine();

		// return option number (one-based numbering)
		return userInt;
	}

	int ConsoleMenu::getSelectionIndex() const
	{
		// return option index (zero-based numbering)
		return getSelection() - 1;
	}


	// Static members

	const string ConsoleMenu::separator = "-------------------------";

	std::string ConsoleMenu::getSeparator()
	{
		return separator;
	}

	void ConsoleMenu::displaySeparator()
	{
		Console::writeLine(separator);
	}
}
