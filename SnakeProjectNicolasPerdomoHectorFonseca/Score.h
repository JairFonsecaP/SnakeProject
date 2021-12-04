#pragma once
#include <string>
#include <vector>
#include "DateTime.h"
#include "Strings.h"

class Score
{
private:
	std::string name;
	int score;
	int level;
	utility::DateTime date;

public:
	Score(std::string name, int score, int level);

	std::string getName();
	int getScore();
	int getLevel();
	utility::DateTime getDate();

	static void sortScores(std::vector<Score*>scores);
	static std::vector<std::string> scoresToString(std::vector<Score*>scores);
};

