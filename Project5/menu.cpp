#include "menu.h"



menu::menu(sf::Font font, sf::RenderWindow &window,Stangry &stangry)
{
	this->font = font;
	this->window = &window;
	this->stangry = &stangry;

}
void menu::odtowrzmenu()
{
	sf::Texture tlo;
	tlo.loadFromFile("tlo.jpg");
	sf::Sprite sprajt;
	sprajt.setTexture(tlo);
	tworztekst();

	while (stangry->stan == Stangry::MENU)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(*window));
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				stangry->stan = Stangry::EXIT;
			if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				if (text[1].getGlobalBounds().contains(mouse))
				{
					stangry->stan = Stangry::POZIOM;
				}
				if (text[2].getGlobalBounds().contains(mouse))
				{
					stangry->stan = Stangry::EXIT;
				}
			}
		}
		updatemenu();
		window->clear();
		window->draw(sprajt);
		for (size_t i = 0; i < 4; i++)
		{
			window->draw(text[i]);
		}
		window->display();
	}
}
void menu::tworztekst()
{
	std::string tekst[] = { "SNAKE","PLAY","EXIT" };

	text[0].setFont(font);
	text[0].setString(tekst[0]);
	text[0].setCharacterSize(120);
	text[0].setPosition(sf::Vector2f(Informacje::szerokosc / 2 - (text[0].getGlobalBounds().width / 2), Informacje::wysokosc / 4 - text[0].getGlobalBounds().height / 2));
	text[1].setFont(font);
	text[1].setString(tekst[1]);
	text[1].setCharacterSize(80);
	text[1].setPosition(sf::Vector2f(Informacje::szerokosc / 4 + (text[0].getGlobalBounds().width / 4), Informacje::wysokosc / 4 + text[0].getGlobalBounds().height));
	text[2].setFont(font);
	text[2].setString(tekst[2]);
	text[2].setCharacterSize(80);
	text[2].setPosition(sf::Vector2f(Informacje::szerokosc / 4 + (text[0].getGlobalBounds().width / 4), Informacje::wysokosc / 4 + text[0].getGlobalBounds().height * 2));
}
void menu::updatemenu()
{
	sf::Vector2f mouse(sf::Mouse::getPosition(*window));
	for (size_t i = 1; i < 3; i++)
	{
		if (text[i].getGlobalBounds().contains(mouse))
		{
			text[i].setFillColor(sf::Color::Cyan);
		}
		else text[i].setFillColor(sf::Color::White);

	}
}
menu::~menu()
{
}