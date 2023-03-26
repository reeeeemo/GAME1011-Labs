#pragma once
#ifndef __MESSAGER_H__
#define __MESSAGER_H__
class Messager
{
public:
	static void WelcomePlayer();
	static int GetChoiceInput();
private:
	static int GetInput();
};

#endif //!__MESSAGER_H__