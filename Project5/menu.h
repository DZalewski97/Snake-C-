#pragma once
#include "stan.h"
#include "info.h"
class menu
{
public:
	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text[4];
	Stangry *stangry;
	sf::Sprite sprajt;


	menu(sf::Font font, sf::RenderWindow &window, Stangry &stangry);
	void odtowrzmenu();
	void updatemenu();
	void tworztekst();
	~menu();
};