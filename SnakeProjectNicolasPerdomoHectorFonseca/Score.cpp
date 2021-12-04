#include "Score.h"

using utility::DateTime;
using utility::Strings;
using std::string;
using std::vector;

Score::Score(std::string name, int score, int level)
	:name(name), score(score), level(level), date(DateTime::getNow())
{
}

string Score::getName()
{
	return name;
}

int Score::getScore()
{
	return score;
}

int Score::getLevel()
{
	return level;
}

DateTime Score::getDate()
{
	return date;
}

void Score::sortScores(vector<Score*>scores)
{
	for (size_t i = 0; i < scores.size() - 1; i++)
	{
		for (size_t j = i + 1; j < scores.size(); j++)
		{
			if (scores.at(i)->getScore() < scores.at(j)->getScore())
			{
				Score temp = *scores.at(i);
				*scores.at(i) = *scores.at(j);
				*scores.at(j) = temp;
			}
		}
	}
}

vector<string> Score::scoresToString(vector<Score*>scores)
{
	vector<string> toReturn;
	for (size_t i = 0; i < scores.size()  ; i++)
	{
		string scoreInString =
			"Name: " + scores.at(i)->name +
			"\t|| Score: " + Strings::integerToString(scores.at(i)->score) +
			"\t|| Level: " + Strings::integerToString(scores.at(i)->level) +
			"\t|| Date: " + scores.at(i)->date.toString();
		toReturn.push_back(scoreInString);
	}
	return toReturn;
}