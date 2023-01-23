#include "Achievement.h"

std::string Achievement::GetTitle() {
	return title;
}

std::string Achievement::GetDescription() {
	return description;
}

double Achievement::GetScoreValue() {
	return score_value;
}

Achievement::Achievement(std::string inputTitle, std::string inputDescription, double inputScore)
{
	title = inputTitle;
	description = inputDescription;
	score_value = inputScore;
}