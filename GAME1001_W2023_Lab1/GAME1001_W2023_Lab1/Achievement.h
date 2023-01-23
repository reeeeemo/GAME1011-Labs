#pragma once
#ifndef  __ACHIEVEMENT_H__
#define __ACHIEVEMENT_H__
#include <iostream>
#include <string>


class Achievement {
public:
	Achievement(std::string inputTitle, std::string inputDescription, double inputScore);
	std::string GetTitle();
	std::string GetDescription();
	double GetScoreValue();
private:
	std::string title;
	std::string description;
	double score_value;
};

#endif // ! __ACHIEVEMENT_H__
