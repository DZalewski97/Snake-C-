#pragma once
#include "info.h"
#include "stan.h"
class wybor
{
public:

	sf::Font font;
	sf::RenderWindow *window;
	sf::Text text[4];
	Stangry *stangry;
	sf::Sprite sprajt;
	wybor(sf::Font font, sf::RenderWindow &window, Stangry &gameState);
	void odtowrzwybor();
	void updatewybor();
	void tworztekst();
	~wybor();
};