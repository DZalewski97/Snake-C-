#pragma once
#include "info.h"
#include "Snake.h"
class gra
{
public:
	gra();
	Stangry stangry;
	sf::RenderWindow window;
	sf::Font font;
	sf::RenderWindow win;
	sf::Font fonts;
	void run();
	void runMenu();
	void runEngine1();
	void runEngine2();
	void runwybor();
	~gra();
};
