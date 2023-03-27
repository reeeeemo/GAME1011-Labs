#pragma once
#ifndef __MESSAGER_H__
#define __MESSAGER_H__

#include <string>


class Messager
{
public:
	static void WelcomePlayer();
	static int GetChoiceInput();
	static std::string GetStringInput();
	static void OutputString(std::string);
	static int GetIntInput(); // Technically this and GetChoiceInput() could be the same with parameters, but not necessary for this project.
private:
	static int GetInput();
};

#endif //!__MESSAGER_H__